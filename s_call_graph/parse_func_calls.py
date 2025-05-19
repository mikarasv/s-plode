from collections.abc import Generator

from .custom_types import EdgeLabel, FuncName, NodeDict, NodeIndex, NodeType
from .rustworkX import GraphRx


class FuncCallsParser:
    def __init__(self, graph: GraphRx, ansatz: FuncName | None) -> None:
        self.graph = graph
        self.ansatz = ansatz

    def is_valid_func(self, node: NodeDict) -> bool:
        name = node["name"]
        ret_value = name != "Decl"
        if self.ansatz is None:
            ret_value = name != self.ansatz and ret_value
        return ret_value

    def get_param_idx(self, func_node_index: NodeIndex | None) -> NodeIndex | None:
        edges = self.graph.out_edges(func_node_index)
        if len(edges) < 2:
            return None
        param_idx = edges[1]["node_b"]
        if self.graph.get_name_by_index(param_idx) != "Params":
            return None
        return param_idx

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

    # Renames parameters in the function definition to avoid name conflicts
    def make_params_name_unique(self) -> None:
        for func_node in filter(self.is_valid_func, self.graph.successors(0)):
            func_node_index = func_node["node_index"]
            param_idx = self.get_param_idx(func_node_index)
            param_names = self.collect_param_names(param_idx)
            if func_node:
                self.rename_if_match(func_node_index, param_names)

    def get_func_index(self, call: NodeIndex) -> NodeIndex | None:
        called_func_index = next(
            (
                node["node_b"]
                for node in self.graph.out_edges(call)
                if self.graph.is_node_type_ID(node["node_b"])
            ),
            None,
        )
        if called_func_index is None:
            return None

        func_index = next(
            self.graph.find_index_by_name(
                self.graph.get_name_by_index(called_func_index),
                "Global",
            ),
            None,
        )
        return func_index

    def get_param_node(self, params_node: NodeIndex) -> Generator[NodeDict, None, None]:
        return (
            succ
            for succ in self.graph.bfs_successors(params_node)
            if succ["node_type"] == NodeType.ID
        )

    # Get the index node of parameters of a function call
    def get_params_nodes(self, call: NodeIndex) -> Generator[NodeDict, None, None]:
        func_index = self.get_func_index(call)
        if func_index is None:
            return None

        params_node = self.graph.out_edges(func_index)[1]["node_b"]
        if self.graph.get_name_by_index(params_node) == "Params":
            yield from self.get_param_node(params_node)

    def get_arg_node(self, call: NodeIndex) -> NodeIndex | None:
        node = next(
            (
                node["node_b"]
                for node in self.graph.out_edges(call)
                if self.graph.get_name_by_index(node["node_b"]) == "ExprList"
            ),
            None,
        )
        return node

    def get_arg_node_index(
        self, arg_node: NodeIndex
    ) -> Generator[NodeDict, None, None]:
        return (
            succ
            for succ in self.graph.bfs_successors(arg_node)
            if succ["node_type"] == NodeType.ID
        )

    # Get the index node of arguments of a function call
    def get_func_args(self, call: NodeIndex) -> Generator[NodeDict, None, None]:
        arg_node = self.get_arg_node(call)
        if arg_node is None:
            return None

        if self.graph.get_name_by_index(arg_node) == "ExprList":
            yield from self.get_arg_node_index(arg_node)

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
        scope: FuncName | None,
        body_node: NodeIndex,
        param: NodeDict,
        arg: NodeDict,
    ) -> None:
        if scope is None:
            return
        assign_node = self.graph.add_node("Assign", scope)
        self.graph.add_edge(body_node, assign_node, EdgeLabel.UNIDIR)

        param_node = self.graph.add_node(param["name"], scope, NodeType.ID)
        self.graph.add_edge(param_node, assign_node, EdgeLabel.UNIDIR)

        arg_node = self.graph.add_node(arg["name"], scope, NodeType.ID)
        self.graph.add_edge(assign_node, arg_node, EdgeLabel.UNIDIR)

        arg["name"] = param["name"]

    def process_func_call(self, call: NodeIndex) -> None:
        func_call_scope = self.graph.get_scope_by_index(call)

        param_nodes = self.get_params_nodes(call)
        if not param_nodes:
            return

        args_nodes = self.get_func_args(call)
        if not args_nodes:
            return

        body_node = self.get_body_node_in_scope(func_call_scope)

        for param, arg in zip(param_nodes, args_nodes):
            self.add_assign_nodes(func_call_scope, body_node, param, arg)

    def add_assign_arg_param(self) -> None:
        self.make_params_name_unique()
        call_nodes = self.graph.find_index_by_name("FuncCall")
        if call_nodes is not None:
            for call in call_nodes:
                self.process_func_call(call)
