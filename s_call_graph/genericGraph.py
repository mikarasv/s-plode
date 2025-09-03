from abc import ABC, abstractmethod

import networkx as nx
import rustworkx as rx

# import pygraph as pyg
# from neo4j import GraphDatabase
from typing_extensions import Generic, TypeVar

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex, NodeType

# GraphType = TypeVar(
#     "GraphType", rx.PyDiGraph, nx.DiGraph, GraphDatabase, pyg.DirectedGraph
# )
GraphType = TypeVar("GraphType", rx.PyDiGraph, nx.DiGraph)


class GenericGraph(Generic[GraphType], ABC):
    def __init__(self) -> None:
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
