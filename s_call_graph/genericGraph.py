from abc import ABC, abstractmethod
from typing import Generic, TypeVar

import networkx as nx
import rustworkx as rx
from neo4j import GraphDatabase

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex, NodeType

GraphType = TypeVar("GraphType", rx.PyDiGraph, nx.DiGraph, GraphDatabase)


class GenericGraph(Generic[GraphType], ABC):
    def __init__(self) -> None:
        self.graph: GraphType = self.initialize_graph()

    @abstractmethod
    def initialize_graph(self) -> GraphType:
        pass

    @abstractmethod
    def add_node(
        self,
        name: str,
        scope: FuncName,
        node_type: NodeType = NodeType.NONE,
    ) -> NodeIndex:
        pass

    @abstractmethod
    def add_edge(
        self,
        parent: NodeIndex,
        child: NodeIndex,
        label: EdgeLabel,
        index: NodeIndex | None = None,
        origin: EdgeType = EdgeType.AST,
    ) -> None:
        pass

    @abstractmethod
    def get_name_by_index(self, index: NodeIndex) -> str:
        pass
        pass
