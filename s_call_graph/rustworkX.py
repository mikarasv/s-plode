from typing import Generator

import rustworkx as rx

from .custom_types import EdgeType, FuncName, NodeDict, NodeIndex, NodeType


class GraphRx:
    def __init__(self) -> None:
        self.graph = rx.PyDiGraph()

    def add_node(
        self,
        name: str,
        scope: FuncName,
        node_type: NodeType = NodeType.NONE,
    ) -> NodeIndex:
        node_data: NodeDict = {
            "name": name,
            "scope": scope,
            "node_type": node_type,
        }
        index = self.graph.add_node(node_data)

        self.graph[index]["node_index"] = index
        return index

    def add_edge(
        self,
        parent: NodeIndex,
        child: NodeIndex,
        label: str,
        index: NodeIndex | None = None,
        origin: EdgeType = EdgeType.AST,
    ) -> None:
        self.graph.add_edge(
            parent, child, {"label": label, "index": index, "from": origin}
        )
        if label == "":
            self.graph.add_edge(
                child, parent, {"label": "invisible", "index": "", "from": origin}
            )

    def find_index_by_name(
        self, node_name: str, scope: FuncName | None = None
    ) -> Generator[NodeIndex, None, None]:
        def matches(node: NodeDict) -> bool:
            return node["name"] == node_name and (
                scope is None or node["scope"] == scope
            )

        for node in self.graph.nodes():
            if matches(node):
                yield node["node_index"]

    def get_node_by_index(self, index: NodeIndex) -> NodeDict:
        return self.graph[index]

    def in_edges(self, node: NodeIndex) -> list[tuple[NodeIndex, NodeIndex]]:
        return self.graph.in_edges(node)

    def out_edges(self, node: NodeIndex) -> list[tuple[NodeIndex, NodeIndex]]:
        return self.graph.out_edges(node)

    def remove_edge(self, parent: NodeIndex, child: NodeIndex) -> None:
        self.graph.remove_edge(parent, child)

    def successors(self, node: NodeIndex) -> list[NodeIndex]:
        return self.graph.successors(node)

    def bfs_successors(
        self, node: NodeIndex
    ) -> Generator[tuple[NodeIndex, list[NodeIndex]], None, None]:
        return rx.bfs_successors(self.graph, node)

    def remove_nodes_from(self, nodes: list[NodeIndex]) -> None:
        self.graph.remove_nodes_from(nodes)

    def node_indices(self) -> list[NodeIndex]:
        return self.graph.node_indices()

    def neighbors(self, node: NodeIndex) -> list[NodeIndex]:
        return self.graph.neighbors(node)
