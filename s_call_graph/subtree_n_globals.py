from typing import List, Set

from pycparser import c_ast

from .custom_types import FuncName, GlobalVar, NodeDict, NodeIndex, NodeType
from .rustworkX import GraphRx


class SubtreeNGlobalsParser:
    def __init__(
        self, graph: GraphRx, ast: c_ast.FileAST, ansatz: FuncName | None
    ) -> None:
        self.graph = graph
        self.ast = ast
        self.ansatz = ansatz

    def get_root_id(self) -> NodeIndex | None:
        return next(self.graph.find_index_by_name("FileAST"), None)

    def get_decl_nodes(self, root_id: NodeIndex) -> List[NodeIndex]:
        return [
            node
            for node in self.graph.neighbors(root_id)
            if self.graph.get_node_by_index(node)["name"] == "Decl"
        ]

    def collect_global_vars(self, decl_nodes: List[NodeIndex]) -> Set[NodeIndex]:
        return {
            self.graph.get_node_by_index(child)["node_index"]
            for decl in decl_nodes
            for child in self.graph.neighbors(decl)
            if self.graph.get_node_by_index(child)["node_type"] == NodeType.ID
        }

    def collect_global_var_types(
        self,
        global_vars_idxs: Set[NodeIndex],
    ) -> Set[GlobalVar]:
        return {
            GlobalVar(
                g_var=NodeDict(**self.graph.get_node_by_index(var_idx)),
                var_type=NodeDict(**self.graph.get_node_by_index(type_idx)),
            )
            for var_idx in global_vars_idxs
            for type_idx in self.graph.neighbors(var_idx)
            if self.graph.get_node_by_index(type_idx)["node_type"] != NodeType.ID
        }

    def find_local_func_calls(self, func_with_calls: str) -> List[NodeIndex]:
        return [
            node_index
            for node_index in self.graph.find_index_by_name("FuncCall") or []
            if self.graph.get_node_by_index(node_index)["scope"] == func_with_calls
        ]

    def get_called_func_index(self, call: NodeIndex) -> NodeIndex | None:
        edges = self.graph.out_edges(call)
        if len(edges) < 2:
            return None
        name = self.graph.get_node_by_index(edges[1][1])["name"]
        return next(self.graph.find_index_by_name(name, "Global"), None)

    def get_called_func_nodes(self) -> Set[FuncName]:
        func_calls = self.find_local_func_calls(self.ansatz)
        result = set()
        remaining = func_calls
        while remaining:
            call = remaining.pop()
            called_idx = self.get_called_func_index(call)
            if called_idx is None:
                continue
            result.add(self.graph.get_node_by_index(called_idx)["name"])
            remaining.extend(
                self.find_local_func_calls(
                    self.graph.get_node_by_index(called_idx)["name"]
                )
            )
        return result

    def get_subtree(self, called_func_list: Set[str]) -> c_ast.FileAST:
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

    def parse_globals(self) -> Set[GlobalVar]:
        root_id = self.get_root_id()
        if root_id is None:
            return set()

        decl_nodes = self.get_decl_nodes(root_id)
        global_vars = self.collect_global_vars(decl_nodes)
        global_vars_with_type = self.collect_global_var_types(global_vars)
        return global_vars_with_type

    def get_subtree_and_globals(self) -> Set[GlobalVar]:
        if self.ansatz:
            called_funcs = self.get_called_func_nodes()
            self.ast = self.get_subtree(called_funcs | {self.ansatz})

        g_vars_with_types = self.parse_globals()

        return g_vars_with_types
