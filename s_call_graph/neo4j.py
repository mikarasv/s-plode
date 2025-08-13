from typing import override

from neo4j import GraphDatabase, Transaction

from .custom_types import EdgeLabel, EdgeType, FuncName, NodeIndex, NodeType
from .genericGraph import GenericGraph


class GraphN4j(GenericGraph):
    @override
    def __init__(self) -> None:
        self.uri = "bolt://localhost:7687"
        self.index = 0
        self.driver = GraphDatabase.driver(self.uri, auth=None)

    def delete_all(self) -> None:
        with self.driver.session() as session:
            session.run("MATCH (n) DETACH DELETE n")

    @override
    def initialize_graph(self) -> GraphDatabase:
        pass

    @override
    def add_node(
        self,
        name: str,
        scope: FuncName,
        node_type: NodeType = NodeType.NONE,
    ) -> NodeIndex:
        with self.driver.session() as session:
            self.index += 1
            session.execute_write(self._add_node, name, scope, node_type)
            return self.index

    def _add_node(
        self,
        tx: Transaction,
        name: str,
        scope: FuncName,
        node_type: NodeType = NodeType.NONE,
    ) -> None:
        tx.run(
            "CREATE (n:Node {name: $name, scope: $scope, node_type: $node_type, node_index: $index})",
            name=name,
            scope=scope,
            node_type=node_type.value,
            index=self.index,
        )

    @override
    def add_edge(
        self,
        parent: NodeIndex,
        child: NodeIndex,
        label: EdgeLabel,
        index: NodeIndex | None = None,
        origin: EdgeType = EdgeType.AST,
    ) -> None:
        with self.driver.session() as session:
            session.execute_write(self._add_edge, parent, child, label, index, origin)

    def _add_edge(
        self,
        tx: Transaction,
        parent: NodeIndex,
        child: NodeIndex,
        label: EdgeLabel,
        index: NodeIndex | None = None,
        origin: EdgeType = EdgeType.AST,
    ) -> None:
        if label == EdgeLabel.BIDIR:
            tx.run(
                f"""MATCH (a:Node {{node_index: $parent}}), (b:Node {{node_index: $child}})
                CREATE (a)-[r:Edge {{label: $label, edge_index: $index, from_: $origin}}]->(b)
                CREATE (b)-[r2:Edge {{label: $label, edge_index: $index, from_: $origin}}]->(a)""",
                parent=parent,
                child=child,
                label=label.value,
                index=index,
                origin=origin.value,
            )
        else:
            tx.run(
                f"""MATCH (a:Node {{node_index: $parent}}), (b:Node {{node_index: $child}})
                CREATE (a)-[r:Edge {{label: $label, edge_index: $index, from_: $origin}}]->(b)""",
                parent=parent,
                child=child,
                label=label.value,
                index=index,
                origin=origin.value,
            )

    @override
    def get_name_by_index(self, index: NodeIndex) -> str:
        with self.driver.session() as session:
            return session.execute_read(self._get_name_by_index, index)

    def _get_name_by_index(self, tx: Transaction, index: NodeIndex) -> str:
        result = tx.run(
            "MATCH (n:Node {node_index: $index}) RETURN n.name AS name",
            index=index,
        )
        record = result.single()
        if record:
            return record["name"]
        return ""
