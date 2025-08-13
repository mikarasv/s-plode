from collections.abc import Callable, Generator
from typing import Any, cast, override

import rustworkx as rx

from .custom_types import (
    EdgeDict,
    EdgeLabel,
    EdgeType,
    FuncName,
    NodeDict,
    NodeIndex,
    NodeType,
)
from .genericGraph import GenericGraph


class GraphRx(GenericGraph):
    @override
    def initialize_graph(self) -> rx.PyDiGraph:
        return rx.PyDiGraph()

    @override
    def add_node(
        self,
        name: str,
        scope: FuncName,
        node_type: NodeType = NodeType.NONE,
    ) -> NodeIndex:
        node_data = NodeDict(
            {"name": name, "scope": scope, "node_type": node_type, "node_index": None}
        )
        index = self.graph.add_node(node_data)

        self.graph[index]["node_index"] = index
        return index

    @override
    def add_edge(
        self,
        parent: NodeIndex,
        child: NodeIndex,
        label: EdgeLabel,
        index: NodeIndex | None = None,
        origin: EdgeType = EdgeType.AST,
    ) -> None:
        self.graph.add_edge(
            parent, child, {"label": label, "edge_index": index, "from_": origin}
        )
        if label == EdgeLabel.BIDIR:
            self.graph.add_edge(
                child,
                parent,
                {"label": EdgeLabel.INVIS, "edge_index": None, "from_": origin},
            )

    # INSPECTORS
    def matches(self, node: NodeDict, node_name: str, scope: FuncName | None) -> bool:
        return node["name"] == node_name and (scope is None or node["scope"] == scope)

    def is_node_type_ID(self, index: NodeIndex) -> bool:
        return cast(NodeDict, self.graph[index])["node_type"] == NodeType.ID

    # NODE GETTERS
    def get_node_by_index(self, index: NodeIndex) -> NodeDict:
        return cast(NodeDict, self.graph[index])

    @override
    def get_name_by_index(self, index: NodeIndex) -> str:
        return cast(NodeDict, self.graph[index])["name"]

    def get_scope_by_index(self, index: NodeIndex) -> FuncName:
        return cast(NodeDict, self.graph[index])["scope"]

    def find_index_by_name(
        self, node_name: str, scope: FuncName | None = None
    ) -> Generator[NodeIndex, None, None]:
        for node in self.graph.nodes():
            if self.matches(node, node_name, scope):
                yield node["node_index"]

    # NODES GETTERS
    def node_indices(self) -> list[NodeIndex]:
        return [NodeIndex(i) for i in self.graph.node_indices()]

    def successor_indices(self, node: NodeIndex) -> list[NodeIndex]:
        return [NodeIndex(i) for i in self.graph.successor_indices(node)]

    def successors(self, node: NodeIndex) -> list[NodeDict]:
        return [cast(NodeDict, i) for i in self.graph.successors(node)]

    def bfs_successors(self, node: NodeIndex | None) -> list[NodeDict]:
        if node is None:
            return []
        return [
            cast(NodeDict, node_dict)
            for _, successors in rx.bfs_successors(self.graph, node)
            for node_dict in successors
        ]

    def neighbors(self, node: NodeIndex) -> list[NodeIndex]:
        return [NodeIndex(i) for i in self.graph.neighbors(node)]

    # EDGE GETTERS
    def in_edges(self, node: NodeIndex) -> list[EdgeDict]:
        return [
            EdgeDict({"node_a": i[0], "node_b": i[1], "data": i[2]})
            for i in self.graph.in_edges(node)
        ]

    def in_edge_with_index(self, node: NodeIndex | None, index: int) -> EdgeDict | None:
        if node is not None:
            return next(
                (
                    EdgeDict({"node_a": i[0], "node_b": i[1], "data": i[2]})
                    for i in self.graph.in_edges(node)
                    if i[2]["edge_index"] == index
                ),
                None,
            )
        raise ValueError("No index provided for in_edge_with_index")

    def out_edges(self, node: NodeIndex | None) -> list[EdgeDict]:
        if node is None:
            return []
        return [
            EdgeDict({"node_a": i[0], "node_b": i[1], "data": i[2]})
            for i in self.graph.out_edges(node)
        ]

    def out_edge_with_index(
        self, node: NodeIndex | None, index: int
    ) -> EdgeDict | None:
        if node is not None:
            return next(
                (
                    EdgeDict({"node_a": i[0], "node_b": i[1], "data": i[2]})
                    for i in self.graph.out_edges(node)
                    if i[2]["edge_index"] == index
                ),
                None,
            )
        raise ValueError("No index provided for out_edge_with_index")

    # MODIFIERS
    def remove_edge(self, parent: NodeIndex, child: NodeIndex) -> None:
        self.graph.remove_edge(parent, child)

    def remove_nodes_from(self, nodes: list[NodeIndex]) -> None:
        self.graph.remove_nodes_from(nodes)

    def to_dot(
        self,
        node_attr: Callable[[Any], dict[str, str]] | None = None,
        edge_attr: Callable[[Any], dict[str, str]] | None | None = None,
    ) -> str | None:
        return self.graph.to_dot(node_attr=node_attr, edge_attr=edge_attr)
