from pycparser import c_ast

from .custom_types import EdgeDict, FuncName, NodeIndex
from .rustworkX import GraphRx


class GraphFilterer:
    def __init__(
        self,
        graph: GraphRx,
        ansatz: FuncName | None,
        ast: c_ast.FileAST,
        includes: list[FuncName],
    ):
        self.graph = graph
        self.ast = ast
        self.ansatz = ansatz
        self.includes = includes

    ### Graph Filtering Decl nodes ###
    def get_ansatz_decls(self, ansatz_child: NodeIndex) -> list[NodeIndex]:
        return [
            index
            for index in list(self.graph.successor_indices(ansatz_child))
            if self.graph.get_name_by_index(index) == "Decl"
        ]

    def get_default_excluded_nodes(self) -> list[NodeIndex]:
        irrelevant_list = ["Typedef", "Typename", "FileAST"]
        return [
            x for irr in irrelevant_list for x in self.graph.find_index_by_name(irr)
        ]

    def filter_graph(self) -> None:
        exclude_nodes = self.get_default_excluded_nodes()
        if self.ansatz:
            ansatz_index = next(self.graph.find_index_by_name(self.ansatz), None)

            if ansatz_index is not None:
                ansatz_children = list(self.graph.successor_indices(ansatz_index))
                ansatz_decls = self.get_ansatz_decls(ansatz_children[0])
                exclude_nodes.extend(ansatz_decls)

        self.graph.remove_nodes_from(exclude_nodes)

    ### Subtree Extraction ###
    def get_local_func_call_edge(
        self, call_index: NodeIndex, scope: FuncName
    ) -> EdgeDict | None:
        edge = self.graph.out_edge_with_index(call_index, 0)
        if edge is None:
            # Assert: should have at least edge with the "func name"
            raise ValueError(f"Node {call_index} does not have an outgoing edge.")
        if self.graph.get_scope_by_index(call_index) != scope:
            return None
        return edge

    def find_local_called_funcs(self, scope: FuncName) -> list[NodeIndex]:
        func_call_idxs = self.graph.find_index_by_name("FuncCall")
        call_indices: list[NodeIndex] = (
            list(func_call_idxs) if func_call_idxs is not None else []
        )

        result = []

        for call_index in call_indices:
            edge = self.get_local_func_call_edge(call_index, scope)
            if edge is not None:
                result.append(edge["node_b"])

        return result

    def get_called_func_nodes(self) -> set[FuncName]:
        if self.ansatz is None:
            return set()
        # Get called functions on ansatz
        called_funcs = self.find_local_called_funcs(self.ansatz)
        result = {self.ansatz}
        remaining = called_funcs
        # Find called functions on functions called by ansatz
        while remaining:
            called_func_idx = remaining.pop()
            func_name = self.graph.get_name_by_index(called_func_idx)
            result.add(func_name)
            # Get called functions on current function
            remaining.extend(self.find_local_called_funcs(func_name))
        result.update(self.includes)

        return result

    def get_filtered_tree(self, called_func_list: set[str]) -> c_ast.FileAST:
        # Filter FuncDef nodes
        filtered_ext = []
        for ext in self.ast.ext:
            if isinstance(ext, c_ast.FuncDef):
                func_name = ext.decl.name
                if func_name in called_func_list:
                    filtered_ext.append(ext)
            else:
                filtered_ext.append(ext)  # Other nodes remain (decl, etc.)

        # Create a new FileAST with the filtered nodes
        filtered_ast = c_ast.FileAST(filtered_ext)
        return filtered_ast

    def get_subtree(self) -> c_ast.FileAST:
        if self.ansatz:
            called_funcs = self.get_called_func_nodes()
            self.ast = self.get_filtered_tree(called_funcs)
        return self.ast
