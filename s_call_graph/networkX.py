from typing import Any, cast, override

import networkx as nx

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex, NodeType
from .genericGraph import GenericGraph


class GraphNx(GenericGraph):
    @override
    def __init__(self) -> None:
        self.graph = self.initialize_graph()
        self.index = 0

    @override
    def initialize_graph(self) -> nx.DiGraph:
        return nx.DiGraph()

    @override
    def add_node(
        self,
        name: str,
        scope: FuncName,
        node_type: NodeType = NodeType.NONE,
    ) -> NodeIndex:
        self.graph.add_node(
            self.index, name=name, scope=scope, type=node_type, index=self.index
        )
        self.index += 1
        return self.index - 1

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
            parent,
            child,
            label=label,
            index=index if index is not None else self.index,
            origin=origin,
        )

    @override
    def get_name_by_index(self, index: NodeIndex) -> str:
        return self.graph.nodes[index]["name"]
