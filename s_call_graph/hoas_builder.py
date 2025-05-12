from collections import defaultdict
from typing import Dict, List

from .custom_types import EdgeType, NodeIndex, NodeType
from .rustworkX import GraphRx


class HoasBuilder:
    def __init__(self, graph: GraphRx) -> None:
        self.graph = graph

    def group_id_nodes(self) -> Dict[str, List[NodeIndex]]:
        name_to_nodes = defaultdict(list)
        for node in self.graph.node_indices():
            if self.graph.get_node_by_index(node)["node_type"] == NodeType.ID:
                name_to_nodes[self.graph.get_node_by_index(node)["name"]].append(node)
        return name_to_nodes

    def connect_hoas_edges(self, name_to_nodes: Dict[str, List[NodeIndex]]) -> None:
        for nodes in name_to_nodes.values():
            nodes.sort()
            for i, u in enumerate(nodes):
                for v in nodes[i + 1 :]:
                    self.graph.add_edge(u, v, "", origin=EdgeType.HOAS)

    def make_hoas(self) -> None:
        name_to_nodes = self.group_id_nodes()
        self.connect_hoas_edges(name_to_nodes)
