import pygraph as pyg
from typing_extensions import override

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex, NodeType
from .genericGraph import GenericGraph


class GraphPg(GenericGraph[pyg.DirectedGraph]):
    @override
    def __init__(self) -> None:
        self.graph = pyg.DirectedGraph()
        self.index = 1

    @override
    def add_node(
        self,
        _: str,
        __: FuncName,
        ___: NodeType = NodeType.NONE,
    ) -> NodeIndex:
        self.graph.new_node()
        self.index += 1
        return self.index - 1

    @override
    def add_edge(
        self,
        parent: NodeIndex,
        child: NodeIndex,
        label: EdgeLabel,
        _: NodeIndex | None = None,
        __: EdgeType = EdgeType.AST,
    ) -> None:
        self.graph.new_edge(parent, child)
        if label == EdgeLabel.BIDIR:
            self.graph.new_edge(child, parent)

    @override
    def get_name_by_index(self, _: NodeIndex) -> str:
        return ""
