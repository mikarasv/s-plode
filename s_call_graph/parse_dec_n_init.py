from typing import List, Set

from .custom_types import NodeIndex, NodeType
from .rustworkX import GraphRx


class DeclAndInitParser:
    def __init__(self, graph: GraphRx) -> None:
        self.graph = graph

    def parse_decl_and_init(self) -> None:
        for decl in self.graph.find_index_by_name("Decl"):
            if len(self.graph.out_edges(decl)) == 2:
                decl_scope = self.graph.get_node_by_index(decl)["scope"]

                parent_node = self.graph.in_edges(decl)[0][0]
                assign_node = self.graph.add_node("Assign", decl_scope)
                self.graph.add_edge(parent_node, assign_node, "unidir")

                res = self.graph.get_node_by_index(self.graph.out_edges(decl)[1][1])
                res_index = self.graph.out_edges(decl)[1][1]
                if res["name"] == "PtrDecl":
                    res_name = self.graph.get_node_by_index(
                        self.graph.out_edges(res_index)[0][1]
                    )["name"]
                else:
                    res_name = res["name"]

                res_node = self.graph.add_node(res_name, decl_scope, NodeType.ID)
                self.graph.add_edge(res_node, assign_node, "unidir")
                self.graph.add_edge(
                    assign_node, self.graph.out_edges(decl)[0][1], "unidir"
                )
                self.graph.remove_edge(decl, self.graph.out_edges(decl)[0][1])
