from typing_extensions import cast

from .custom_types import EdgeDict, FuncName, NodeIndex, VarAndType
from .rustworkX import GraphRx


class ParamsNGlobalsParser:
    def __init__(self, graph: GraphRx, ansatz: FuncName | None) -> None:
        self.graph = graph
        self.ansatz = ansatz
        self.global_vars: list[VarAndType] = []
        self.ansatz_params: list[VarAndType] = []

    def _eliminate_redundant_vars(self, var_list: list[VarAndType]) -> list[VarAndType]:
        seen_vars = set()
        filtered = []

        for var_and_type in var_list:
            key = (
                var_and_type["var_dict"]["node_index"],
                var_and_type["var_type"]["node_index"],
            )
            if key not in seen_vars:
                seen_vars.add(key)
                filtered.append(var_and_type)

        return filtered

    ### Collecting Symbolic Global Variables ###
    def _get_decl_nodes(self) -> list[NodeIndex]:
        return [
            node
            for node in self.graph.node_indices()
            if self.graph.get_name_by_index(node) == "Decl"
            and self.graph.get_scope_by_index(node) == "Global"
        ]

    def _collect_global_vars(self, decl_nodes: list[NodeIndex]) -> set[NodeIndex]:
        return {
            child_index
            for decl in decl_nodes
            for child_index in self.graph.neighbors(decl)
            if self.graph.is_node_type_ID(child_index)
        }

    def _collect_global_var_types(
        self,
        global_vars_idxs: set[NodeIndex],
    ) -> None:
        self.global_vars = [
            {
                "var_dict": self.graph.get_node_by_index(var_idx),
                "var_type": self.graph.get_node_by_index(type_idx),
            }
            for var_idx in global_vars_idxs
            for type_idx in self.graph.neighbors(var_idx)
            if not self.graph.is_node_type_ID(type_idx)
        ]
        self.global_vars = self._eliminate_redundant_vars(self.global_vars)

    def _check_arg_index_and_type(
        self, arg_index: NodeIndex | None, type_edge: EdgeDict | None
    ) -> bool:
        return (
            type_edge is None
            or not arg_index
            or not self.graph.is_node_type_ID(arg_index)
        )

    ### Collecting Symbolic Ansatz Parameters ###
    def _collect_ansatz_params(self) -> None:
        ansatz_params_node = next(
            self.graph.find_index_by_name("Params", self.ansatz), None
        )
        for arg in self.graph.bfs_successors(ansatz_params_node):
            arg_index = arg.get("node_index")
            type_edge = self.graph.out_edge_with_index(arg_index, 0)

            if self._check_arg_index_and_type(arg_index, type_edge):
                continue

            arg_index = cast(NodeIndex, arg_index)
            type_edge = cast(EdgeDict, type_edge)
            type_idx = type_edge["node_b"]
            self.ansatz_params.append(
                {
                    "var_dict": self.graph.get_node_by_index(arg_index),
                    "var_type": self.graph.get_node_by_index(type_idx),
                }
            )
        self.ansatz_params = self._eliminate_redundant_vars(self.ansatz_params)

    def get_globals_n_params(self) -> None:
        decl_nodes = self._get_decl_nodes()
        global_vars = self._collect_global_vars(decl_nodes)
        self._collect_global_var_types(global_vars)
        if self.ansatz:
            self._collect_ansatz_params()

    def get_sym_var_names(self) -> set[str]:
        possible_sym_vars = self.ansatz_params + self.global_vars
        if not possible_sym_vars:
            return set()
        return {posible_var["var_dict"]["name"] for posible_var in possible_sym_vars}
