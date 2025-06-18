from pycparser import c_ast

from .custom_types import FuncName, NodeIndex
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

    # Subtree Extraction
    def find_local_func_calls(self, scope: FuncName) -> list[NodeIndex]:
        return [
            self.graph.neighbors(node_index)[0]
            for node_index in self.graph.find_index_by_name("FuncCall") or []
            if self.graph.get_scope_by_index(node_index) == scope
        ]

    def get_called_func_index(self, call: NodeIndex) -> NodeIndex | None:
        edge = self.graph.out_edge_with_index(call, 1)
        if edge is None:
            return None
        name = self.graph.get_name_by_index(edge["node_b"])
        return next(self.graph.find_index_by_name(name, "Global"), None)

    def get_called_func_nodes(self) -> set[FuncName]:
        if self.ansatz is None:
            return set()
        func_calls = self.find_local_func_calls(self.ansatz)
        result = set()
        remaining = func_calls
        while remaining:
            call = remaining.pop()
            called_idx = self.get_called_func_index(call)
            if called_idx is None:
                continue
            result.add(self.graph.get_name_by_index(called_idx))
            remaining.extend(
                self.find_local_func_calls(self.graph.get_name_by_index(called_idx))
            )
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
            self.ast = self.get_filtered_tree(called_funcs | {self.ansatz})
        return self.ast
