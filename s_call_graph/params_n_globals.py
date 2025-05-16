from .custom_types import FuncName, GlobalVar, NodeIndex, NodeType
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

    def is_valid_var(self, node: NodeIndex) -> bool:
        node_data = self.graph.get_node_by_index(node)
        return (
            node_data["node_type"] == NodeType.ID
            and node_data["node_index"] is not None
        )

    def collect_global_vars(self, decl_nodes: list[NodeIndex]) -> set[NodeIndex]:
        return {
            child_index
            for decl in decl_nodes
            for child_index in self.graph.neighbors(decl)
            if self.is_valid_var(child_index)
        }

    def collect_global_var_types(
        self,
        global_vars_idxs: set[NodeIndex],
    ) -> list[GlobalVar]:
        return [
            {
                "g_var": self.graph.get_node_by_index(var_idx),
                "var_type": self.graph.get_node_by_index(type_idx),
            }
            for var_idx in global_vars_idxs
            for type_idx in self.graph.neighbors(var_idx)
            if self.graph.get_node_by_index(type_idx)["node_type"] != NodeType.ID
        ]

    def get_globals(self) -> list[GlobalVar]:
        root_id = self.get_root_id()
        if root_id is None:
            return list()

        decl_nodes = self.get_decl_nodes(root_id)
        global_vars = self.collect_global_vars(decl_nodes)
        return self.collect_global_var_types(global_vars)
