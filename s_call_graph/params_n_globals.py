from .custom_types import FuncName, GlobalVar, NodeDict, NodeIndex, NodeType
from .rustworkX import GraphRx


class ParamsNGlobalsParser:
    def __init__(self, graph: GraphRx, ansatz: FuncName | None) -> None:
        self.graph = graph
        self.ansatz = ansatz

    def get_root_id(self) -> NodeIndex | None:
        return next(self.graph.find_index_by_name("FileAST"), None)

    def get_decl_nodes(self, root_id: NodeIndex) -> list[NodeIndex]:
        return [
            node
            for node in self.graph.neighbors(root_id)
            if self.graph.get_node_by_index(node)["name"] == "Decl"
        ]

    def collect_global_vars(self, decl_nodes: list[NodeIndex]) -> set[NodeIndex]:
        return {
            self.graph.get_node_by_index(child)["node_index"]
            for decl in decl_nodes
            for child in self.graph.neighbors(decl)
            if self.graph.get_node_by_index(child)["node_type"] == NodeType.ID
        }

    def collect_global_var_types(
        self,
        global_vars_idxs: set[NodeIndex],
    ) -> set[GlobalVar]:
        return {
            GlobalVar(
                g_var=NodeDict(**self.graph.get_node_by_index(var_idx)),
                var_type=NodeDict(**self.graph.get_node_by_index(type_idx)),
            )
            for var_idx in global_vars_idxs
            for type_idx in self.graph.neighbors(var_idx)
            if self.graph.get_node_by_index(type_idx)["node_type"] != NodeType.ID
        }

    def parse_globals(self) -> set[GlobalVar]:
        root_id = self.get_root_id()
        if root_id is None:
            return set()

        decl_nodes = self.get_decl_nodes(root_id)
        global_vars = self.collect_global_vars(decl_nodes)
        global_vars_with_type = self.collect_global_var_types(global_vars)
        return global_vars_with_type

    def get_globals(self) -> set[GlobalVar]:
        return self.parse_globals()
