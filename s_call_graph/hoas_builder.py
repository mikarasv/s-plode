from collections import defaultdict

import rustworkx as rx

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex
from .rustworkX import GraphRx


class HoasBuilder:
    def __init__(
        self, graph: GraphRx, ansatz: FuncName | None, includes: list[str]
    ) -> None:
        self.graph = graph
        self.ansatz = ansatz
        self.includes = includes

    def _group_id_nodes(self) -> dict[FuncName, list[NodeIndex]]:
        name_to_nodes = defaultdict(list)
        for node in self.graph.node_indices():
            if self.graph.is_node_type_ID(node):
                name_to_nodes[self.graph.get_name_by_index(node)].append(node)
        return name_to_nodes

    def _get_edge_type_to_add(self, u: NodeIndex, v: NodeIndex) -> EdgeLabel | None:
        if u == v:
            return None
        scope_u = self.graph.get_scope_by_index(u)
        scope_v = self.graph.get_scope_by_index(v)
        label = None
        if scope_u == scope_v:
            label = EdgeLabel.BIDIR
        elif scope_v == "Global" or scope_v in self.graph.get_name_by_index(u):
            label = EdgeLabel.UNIDIR
        return label

    def _evaluate_edge(self, u: NodeIndex, v: NodeIndex) -> None:
        edge = self._get_edge_type_to_add(u, v)
        if edge is not None:
            self.graph.add_edge(u, v, edge, origin=EdgeType.HOAS)

    def _connect_hoas_edges(self, name_to_nodes: dict[str, list[NodeIndex]]) -> None:
        for nodes in name_to_nodes.values():
            nodes.sort()
            for i, u in enumerate(nodes):
                for v in nodes:
                    self._evaluate_edge(u, v)

    def make_hoas(self) -> None:
        name_to_nodes = self._group_id_nodes()
        self._connect_hoas_edges(name_to_nodes)
        # Get rid of unused nodes
        components = rx.weakly_connected_components(self.graph.graph)
        if self.ansatz:
            exclude_nodes: list[NodeIndex] = list()
            ansatz_index = next(self.graph.find_index_by_name(self.ansatz), None)
            include_idxs = [
                idx
                for name in self.includes
                for idx in self.graph.find_index_by_name(name, "Global")
            ]
            for component in components:
                if ansatz_index not in component and ansatz_index not in include_idxs:
                    exclude_nodes.extend(component)

            self.graph.remove_nodes_from(exclude_nodes)
