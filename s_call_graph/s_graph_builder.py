from collections import defaultdict

import rustworkx as rx

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex
from .rustworkX import GraphRx


class SGraphBuilder:

    def __init__(
        self, graph: GraphRx, ansatz: FuncName | None, includes: list[str]
    ) -> None:
        self.graph = graph
        self.ansatz = ansatz
        self.includes = includes
        self.nodes = list(graph.graph.node_indices())
        self.scope_map = {
            node: self.graph.get_scope_by_index(node) for node in self.nodes
        }
        self.name_map = {
            node: self.graph.get_name_by_index(node) for node in self.nodes
        }

    def _group_id_nodes(self) -> dict[FuncName, list[NodeIndex]]:
        name_to_nodes = defaultdict(list)
        for node in self.graph.node_indices():
            if self.graph.is_node_type_ID(node):
                name_to_nodes[self.name_map[node]].append(node)
        return name_to_nodes

    def _get_edge_type_to_add(self, u: NodeIndex, v: NodeIndex) -> EdgeLabel | None:

        scope_u = self.scope_map[u]
        scope_v = self.scope_map[v]

        label = None
        if scope_u == scope_v:
            label = EdgeLabel.BIDIR
        # v is global or v is named after _[scope_u]_[param of the function]
        # where the function name is scope_u
        elif scope_v == "Global" or scope_u in self.name_map[v]:
            label = EdgeLabel.UNIDIR
        return label

    def _edge_handler(
        self, u: NodeIndex, v: NodeIndex, edge_label: EdgeLabel | None
    ) -> None:
        if edge_label == EdgeLabel.BIDIR and u > v:
            return
        if edge_label:
            self.graph.add_edge(u, v, edge_label, origin=EdgeType.NAME_RES)

    def _connect_s_graph_edge(self, u: NodeIndex, v: NodeIndex) -> None:
        if u != v:
            edge_label = self._get_edge_type_to_add(u, v)
            self._edge_handler(u, v, edge_label)

    def _connect_s_graph_edges(self, name_to_nodes: dict[str, list[NodeIndex]]) -> None:
        for nodes in name_to_nodes.values():
            for u in nodes:
                for v in nodes:
                    self._connect_s_graph_edge(u, v)

    def _get_include_idxs(self) -> list[NodeIndex]:
        return [
            idx
            for name in self.includes
            for idx in self.graph.find_index_by_name(name, "Global")
        ]

    def _exclude_unused_nodes(self, components: list[set[NodeIndex]]) -> None:
        exclude_nodes: list[NodeIndex] = list()
        ansatz_index = next(self.graph.find_index_by_name(self.ansatz), None)  # type: ignore
        include_idxs = self._get_include_idxs()
        for component in components:
            if ansatz_index not in component and ansatz_index not in include_idxs:
                exclude_nodes.extend(component)

        self.graph.remove_nodes_from(exclude_nodes)

    def make_s_graph(self) -> None:
        name_to_nodes = self._group_id_nodes()
        self._connect_s_graph_edges(name_to_nodes)
        # Get rid of unused nodes
        if self.ansatz:
            components = rx.weakly_connected_components(self.graph.graph)
            self._exclude_unused_nodes(components)
