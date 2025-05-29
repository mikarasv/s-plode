from .custom_types import FuncName, NodeIndex, VarAndType
from .rustworkX import GraphRx


class ParamsNGlobalsParser:
    def __init__(self, graph: GraphRx, ansatz: FuncName | None) -> None:
        self.graph = graph
        self.ansatz = ansatz
        self.may_be_sym_vars: list[VarAndType] = []

    def get_root_id(self) -> NodeIndex | None:
        return next(self.graph.find_index_by_name("FileAST"), None)

    def get_decl_nodes(self, root_id: NodeIndex) -> list[NodeIndex]:
        return [
            node
            for node in self.graph.neighbors(root_id)
            if self.graph.get_name_by_index(node) == "Decl"
        ]

    def collect_global_vars(self, decl_nodes: list[NodeIndex]) -> set[NodeIndex]:
        return {
            child_index
            for decl in decl_nodes
            for child_index in self.graph.neighbors(decl)
            if self.graph.is_node_type_ID(child_index)
        }

    def collect_global_var_types(
        self,
        global_vars_idxs: set[NodeIndex],
    ) -> list[VarAndType]:
        return [
            {
                "g_var": self.graph.get_node_by_index(var_idx),
                "var_type": self.graph.get_node_by_index(type_idx),
            }
            for var_idx in global_vars_idxs
            for type_idx in self.graph.neighbors(var_idx)
            if not self.graph.is_node_type_ID(type_idx)
        ]

    def get_globals_n_params(self) -> None:
        root_id = self.get_root_id()
        if root_id is not None:
            decl_nodes = self.get_decl_nodes(root_id)
            global_vars = self.collect_global_vars(decl_nodes)
            self.may_be_sym_vars = self.collect_global_var_types(global_vars)
        if self.ansatz:
            ansatz_params_node = next(
                self.graph.find_index_by_name("Params", self.ansatz), None
            )
            if ansatz_params_node:
                ansatz_args = self.graph.neighbors(ansatz_params_node)
                self.may_be_sym_vars.extend(
                    [
                        {
                            "g_var": self.graph.get_node_by_index(arg),
                            "var_type": self.graph.get_node_by_index(
                                self.graph.out_edges(arg)[0]["node_b"]
                            ),
                        }
                        for arg in ansatz_args
                        if self.graph.is_node_type_ID(arg)
                    ]
                )

    def get_sym_var_names(self) -> set[str]:
        return {global_var["g_var"]["name"] for global_var in self.may_be_sym_vars}
