import networkx as nx
from typing_extensions import cast, override

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex, NodeType
from .genericGraph import GenericGraph


class GraphNx(GenericGraph[nx.DiGraph]):
    @override
    def __init__(self) -> None:
        self.graph = nx.DiGraph()
        self.index = 0

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
            index=index,
            origin=origin,
        )
        if label == EdgeLabel.BIDIR:
            self.graph.add_edge(child, parent, label=label, index=index, origin=origin)

    @override
    def get_name_by_index(self, index: NodeIndex) -> str:
        return cast(str, self.graph.nodes[index]["name"])
