from collections import defaultdict

import rustworkx as rx

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex
from .rustworkX import GraphRx


class HoasBuilder:

    def __init__(self, graph: GraphRx, ansatz: FuncName | None,
                 includes: list[str]) -> None:
        self.graph = graph
        self.ansatz = ansatz
        self.includes = includes
        self.nodes = list(graph.graph.node_indices())
        self.scope_map = {
            node: self.graph.get_scope_by_index(node)
            for node in self.nodes
        }
        self.name_map = {
            node: self.graph.get_name_by_index(node)
            for node in self.nodes
        }

    def _group_id_nodes(self) -> dict[FuncName, list[NodeIndex]]:
        name_to_nodes = defaultdict(list)
        for node in self.graph.node_indices():
            if self.graph.is_node_type_ID(node):
                name_to_nodes[self.name_map[node]].append(node)
        return name_to_nodes

    def _get_edge_type_to_add(self, u: NodeIndex,
                              v: NodeIndex) -> EdgeLabel | None:

        scope_u = self.scope_map[u]
        scope_v = self.scope_map[v]

        label = None
        if scope_u == scope_v:
            label = EdgeLabel.BIDIR
        elif scope_v == "Global" or scope_v in self.name_map[u]:
            label = EdgeLabel.UNIDIR
        return label

    def _edge_handler(self, u: NodeIndex, v: NodeIndex,
                      edge_label: EdgeLabel) -> None:
        if edge_label:
            self.graph.add_edge(u, v, edge_label, origin=EdgeType.HOAS)

    def _connect_hoas_edges(self,
                            name_to_nodes: dict[str, list[NodeIndex]]) -> None:
        for nodes in name_to_nodes.values():
            for u in nodes:
                for v in nodes:
                    if u == v:
                        continue
                    edge_label = self._get_edge_type_to_add(u, v)
                    if edge_label == EdgeLabel.BIDIR and u > v:
                        # ya se agregó en la iteración (v, u)
                        continue
                    self._edge_handler(u, v, edge_label)

    def make_hoas(self) -> None:
        name_to_nodes = self._group_id_nodes()
        self._connect_hoas_edges(name_to_nodes)
        # Get rid of unused nodes
        components = rx.weakly_connected_components(self.graph.graph)
        if self.ansatz:
            exclude_nodes: list[NodeIndex] = list()
            ansatz_index = next(self.graph.find_index_by_name(self.ansatz),
                                None)
            include_idxs = [
                idx for name in self.includes
                for idx in self.graph.find_index_by_name(name, "Global")
            ]
            for component in components:
                if ansatz_index not in component and ansatz_index not in include_idxs:
                    exclude_nodes.extend(component)

            self.graph.remove_nodes_from(exclude_nodes)
