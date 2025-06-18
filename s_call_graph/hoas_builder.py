from collections import defaultdict

import rustworkx as rx

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex
from .rustworkX import GraphRx


class HoasBuilder:
    def __init__(self, graph: GraphRx, ansatz: FuncName | None) -> None:
        self.graph = graph
        self.ansatz = ansatz

    def group_id_nodes(self) -> dict[str, list[NodeIndex]]:
        name_to_nodes = defaultdict(list)
        for node in self.graph.node_indices():
            if self.graph.is_node_type_ID(node):
                name_to_nodes[self.graph.get_name_by_index(node)].append(node)
        return name_to_nodes

    def evaluate_edge(self, u: NodeIndex, v: NodeIndex) -> None:
        scope = self.graph.get_scope_by_index(v)
        if scope == "Global" or scope in self.graph.get_name_by_index(v):
            self.graph.add_edge(u, v, EdgeLabel.UNIDIR, origin=EdgeType.HOAS)

    def connect_hoas_edges(self, name_to_nodes: dict[str, list[NodeIndex]]) -> None:
        for nodes in name_to_nodes.values():
            nodes.sort()
            for u in nodes:
                for v in nodes:
                    self.evaluate_edge(u, v)

    def make_hoas(self) -> None:
        name_to_nodes = self.group_id_nodes()
        self.connect_hoas_edges(name_to_nodes)
        # Get rid of unused nodes
        components = rx.weakly_connected_components(self.graph.graph)
        if self.ansatz:
            exclude_nodes: list[NodeIndex] = list()
            ansatz_index = next(self.graph.find_index_by_name(self.ansatz), None)
            for component in components:
                if ansatz_index not in component:
                    exclude_nodes.extend(component)
                    exclude_nodes.extend(component)

            self.graph.remove_nodes_from(exclude_nodes)
