from collections.abc import Callable, Generator
from typing import Any, cast

import rustworkx as rx

from .custom_types import (
    BFSSuccessor,
    EdgeDict,
    EdgeLabel,
    EdgeType,
    FuncName,
    NodeDict,
    NodeIndex,
    NodeType,
)


class GraphRx:
    def __init__(self) -> None:
        self.graph = rx.PyDiGraph()

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

    def matches(self, node: NodeDict, node_name: str, scope: FuncName | None) -> bool:
        return node["name"] == node_name and (scope is None or node["scope"] == scope)

    def find_index_by_name(
        self, node_name: str, scope: FuncName | None = None
    ) -> Generator[NodeIndex, None, None]:
        for node in self.graph.nodes():
            if self.matches(node, node_name, scope):
                yield node["node_index"]

    def get_node_by_index(self, index: NodeIndex) -> NodeDict:
        return cast(NodeDict, self.graph[index])

    def in_edges(self, node: NodeIndex) -> list[EdgeDict]:
        return [
            EdgeDict({"node_a": i[0], "node_b": i[1], "data": i[2]})
            for i in self.graph.in_edges(node)
        ]

    def out_edges(self, node: NodeIndex | None) -> list[EdgeDict]:
        if node is None:
            return []
        return [
            EdgeDict({"node_a": i[0], "node_b": i[1], "data": i[2]})
            for i in self.graph.out_edges(node)
        ]

    def remove_edge(self, parent: NodeIndex, child: NodeIndex) -> None:
        self.graph.remove_edge(parent, child)

    def successors(self, node: NodeIndex) -> list[NodeDict]:
        return [cast(NodeDict, i) for i in self.graph.successors(node)]

    def bfs_successors(self, node: NodeIndex | None) -> list[BFSSuccessor]:
        if node is None:
            return []
        return [
            BFSSuccessor(node=a, successors=b)
            for a, b in rx.bfs_successors(self.graph, node)
        ]

    def remove_nodes_from(self, nodes: list[NodeIndex]) -> None:
        self.graph.remove_nodes_from(nodes)

    def node_indices(self) -> list[NodeIndex]:
        return [NodeIndex(i) for i in self.graph.node_indices()]

    def neighbors(self, node: NodeIndex) -> list[NodeIndex]:
        return [NodeIndex(i) for i in self.graph.neighbors(node)]

    def successor_indices(self, node: NodeIndex) -> list[NodeIndex]:
        return [NodeIndex(i) for i in self.graph.successor_indices(node)]

    def to_dot(
        self,
        node_attr: Callable[[Any], dict[str, str]] | None = None,
        edge_attr: Callable[[Any], dict[str, str]] | None | None = None,
    ) -> str | None:
        return self.graph.to_dot(node_attr=node_attr, edge_attr=edge_attr)
