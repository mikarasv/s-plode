from .custom_types import EdgeLabel, FuncName, FuncVar, NodeDict, NodeIndex, NodeType
from .rustworkX import GraphRx


class FuncCallsParser:
    def __init__(self, graph: GraphRx, ansatz: FuncName | None) -> None:
        self.graph = graph
        self.ansatz = ansatz

    ### Renaming parameters and their uses in Functions except for ansatz ###
    def is_valid_func(self, node: NodeDict) -> bool:
        name = node["name"]
        # If it is Decl, it is a declaration of a global variable
        ret_value = name != "Decl"
        if self.ansatz is not None:
            ret_value = name != self.ansatz and ret_value
        return ret_value

    def get_param_idx(self, func_node_index: NodeIndex | None) -> NodeIndex | None:
        # AST ensures that Params node has always index 1
        edge = self.graph.out_edge_with_index(func_node_index, 1)
        if edge is not None:
            param_idx = edge["node_b"]
            return param_idx
        return None

    def collect_param_names(self, param_idx: NodeIndex | None) -> set[FuncName]:
        return {
            node["name"]
            for node in self.graph.bfs_successors(param_idx)
            if node["node_type"] == NodeType.ID
        }

    def rename_if_match(
        self, func_node_index: NodeIndex | None, param_names: set[str]
    ) -> None:
        for node in self.graph.bfs_successors(func_node_index):
            if node["name"] in param_names:
                node["name"] = f"_{node['scope']}_{node['name']}"

    # Renames parameters and their uses in every function definition
    def make_params_name_unique(self) -> None:
        for func_node in filter(self.is_valid_func, self.graph.successors(0)):
            func_node_index = func_node["node_index"]
            param_idx = self.get_param_idx(func_node_index)
            param_names = self.collect_param_names(param_idx)
            self.rename_if_match(func_node_index, param_names)

    def is_valid_identifier_node(self, node: dict) -> bool:
        return node["node_type"] == NodeType.ID

    def make_func_var(self, node: dict, edge_index: int | None) -> FuncVar:
        return FuncVar(
            var=node,
            index=edge_index if edge_index is not None else -1,
        )

    ### Function Call Params And Arguments ###
    def get_id_succs_from_node(
        self, node: NodeIndex, edge_index: int | None
    ) -> list[FuncVar]:
        seen = set()
        result = []

        for succ in self.graph.bfs_successors(node):
            if not self.is_valid_identifier_node(succ):
                continue

            identifier = succ["node_index"]
            if identifier in seen:
                continue

            seen.add(identifier)
            result.append(self.make_func_var(succ, edge_index))

        return result

    def get_func_index(self, func_call: NodeIndex) -> NodeIndex | None:
        called_func_name_index = next(
            (
                node["node_b"]
                for node in self.graph.out_edges(func_call)
                if self.graph.is_node_type_ID(node["node_b"])
            ),
            None,
        )
        if called_func_name_index is None:
            return None

        # Find the index of the function declaration in the global scope
        func_index = next(
            self.graph.find_index_by_name(
                self.graph.get_name_by_index(called_func_name_index),
                "Global",
            ),
            None,
        )
        return func_index

    # Get Params node of a function from its declaration
    def get_params_nodes(self, func_call: NodeIndex) -> list[FuncVar]:
        # Get the index of the declaration of the function referenced on the CallFunc node
        func_index = self.get_func_index(func_call)
        if func_index is not None:
            # Ensured by visitor that Params node has always index 1
            params_node = self.graph.out_edge_with_index(func_index, 1)
            if params_node is not None:
                all_vars = []
                for edge in self.graph.out_edges(params_node["node_b"]):
                    all_vars.extend(
                        # Gets all bfs succesors with ID node type (i.e should be function parameters)
                        self.get_id_succs_from_node(
                            edge["node_b"], edge["data"]["edge_index"]
                        )
                    )
                return sorted(all_vars, key=lambda var: var["index"])
        return []

    def get_arg_node(self, call: NodeIndex) -> NodeIndex | None:
        node = next(
            (
                node["node_b"]  # ExprList node (i.e args)
                for node in self.graph.out_edges(call)
                if self.graph.get_name_by_index(node["node_b"]) == "ExprList"
            ),
            None,
        )
        return node

    # Get the node of arguments of a function call
    def get_func_args(self, call: NodeIndex) -> list[FuncVar]:
        # "Expr List" (i.e the node whose childs are the arguments) on the "FuncCall" node
        arg_list_node = self.get_arg_node(call)
        all_vars = []
        for succ in self.graph.out_edges(arg_list_node):
            all_vars.append(
                FuncVar(
                    var=self.graph.get_node_by_index(succ["node_b"]),
                    index=(
                        index
                        if (index := succ["data"]["edge_index"]) is not None
                        # TODO: Fix -1 edge_index
                        else -1
                    ),
                )
            )
        return sorted(all_vars, key=lambda var: var["index"])

    def get_body_node_in_scope(self, scope: FuncName) -> NodeIndex:
        body_node = next(
            (
                node
                for node in self.graph.find_index_by_name("Body")
                if self.graph.get_scope_by_index(node) == scope
            ),
            None,
        )
        if body_node is None:
            raise ValueError(f"Body node not found in scope: {scope}")
        return body_node

    def add_assign_nodes(
        self,
        scope: FuncName,
        body_node: NodeIndex,
        param: NodeDict,
        arg: NodeDict,
    ) -> None:
        arg_index = arg["node_index"]
        if arg_index is None:
            raise ValueError("Argument node index is None")
        # It is supossed to have only one in edge
        # ExprList -> "argument" is only one way
        expr_list_edge = self.graph.in_edges(arg_index)[0]
        if expr_list_edge is None:
            raise ValueError("ExprList node not found for the argument index")

        # Get the ExprList node (i.e the node that contains the argument)
        # Before adding a new in edge to the "argument"
        expr_list_node = expr_list_edge["node_a"]

        # Add Body -> (new) Assign edge
        assign_node = self.graph.add_node("Assign", scope)
        self.graph.add_edge(body_node, assign_node, EdgeLabel.UNIDIR)

        # Add "parameter" -> Assign edge
        param_node = self.graph.add_node(param["name"], scope, NodeType.ID)
        self.graph.add_edge(param_node, assign_node, EdgeLabel.UNIDIR)

        # Add the Assign -> "real argument" edge
        self.graph.add_edge(assign_node, arg_index, EdgeLabel.UNIDIR)

        # Remove the edge from the "ExprList" to the real argument (in the FuncCall node)
        self.graph.remove_edge(expr_list_node, arg_index)

        # Add "parameter" to the ExprList node
        param_node = self.graph.add_node(param["name"], scope, NodeType.ID)
        self.graph.add_edge(expr_list_node, param_node, EdgeLabel.UNIDIR)

    def process_func_call(self, func_call_node: NodeIndex) -> None:
        # Name of the function that is making a call to another function
        # (i.e the scope of the FuncCall node))
        func_call_scope = self.graph.get_scope_by_index(func_call_node)

        # Obtained from the definition of the function that is being called
        param_nodes = self.get_params_nodes(func_call_node)
        if not param_nodes:
            return

        # Childs of the "Expr List" node (i.e the arguments of the function call)
        args_nodes = self.get_func_args(func_call_node)
        if not args_nodes:
            return

        body_node = self.get_body_node_in_scope(func_call_scope)
        for param, arg in zip(param_nodes, args_nodes):
            self.add_assign_nodes(func_call_scope, body_node, param["var"], arg["var"])

    def add_assign_arg_param(self) -> None:
        func_call_nodes = self.graph.find_index_by_name("FuncCall")
        if func_call_nodes is not None:
            for call in func_call_nodes:
                self.process_func_call(call)
