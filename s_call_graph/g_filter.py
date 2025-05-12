from typing import Generator, List

from .custom_types import FuncName, NodeIndex
from .rustworkX import GraphRx


class GraphFilterer:
    def __init__(self, graph: GraphRx, ansatz: FuncName | None):
        self.graph = graph
        self.ansatz = ansatz

    def get_ansatz_decls(self, ansatz_child: NodeIndex) -> List[NodeIndex]:
        return [
            index
            for index in list(self.graph.successor_indices(ansatz_child))
            if self.graph[index]["name"] == "Decl"
        ]

    def get_list_of_irrelevant_nodes(
        self, irrelevant_nodes: List[str]
    ) -> Generator[NodeIndex, None, None]:
        return (
            self.graph.find_index_by_name(self.graph, irrelevant_node)
            for irrelevant_node in irrelevant_nodes
        )

    def get_excluded_nodes(self) -> List[NodeIndex]:
        irrelevant_list = ["Params", "Decl", "Typedef", "Typename"]
        if self.ansatz:
            irrelevant_list.append(self.ansatz)
        return [
            x for xs in self.get_list_of_irrelevant_nodes(irrelevant_list) for x in xs
        ]

    def filter_graph(self) -> None:
        filtered_graph = self.graph
        if not self.ansatz:
            exclude_nodes = self.get_excluded_nodes()
            filtered_graph.remove_nodes_from(exclude_nodes)
        else:
            ansatz_index = next(
                self.graph.find_index_by_name(self.graph, self.ansatz), None
            )
            if ansatz_index is None:
                return filtered_graph
            ansatz_children = list(self.graph.successor_indices(ansatz_index))
            ansatz_decls = self.get_ansatz_decls(ansatz_children[0])
            exclude_nodes = self.get_excluded_nodes()

            filtered_graph.remove_nodes_from(
                exclude_nodes + ansatz_children + ansatz_decls
            )
