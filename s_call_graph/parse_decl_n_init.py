from .custom_types import EdgeLabel, NodeType
from .rustworkX import GraphRx


class DeclAndInitParser:
    def __init__(self, graph: GraphRx) -> None:
        self.graph = graph

    def parse_decl_and_init(self) -> None:
        for decl in self.graph.find_index_by_name("Decl"):
            if len(self.graph.out_edges(decl)) == 2:
                decl_scope = self.graph.get_scope_by_index(decl)

                parent_node = self.graph.in_edges(decl)[0]["node_a"]
                assign_node = self.graph.add_node("Assign", decl_scope)
                self.graph.add_edge(parent_node, assign_node, EdgeLabel.UNIDIR)

                var_name = self.graph.get_name_by_index(
                    self.graph.out_edges(decl)[1]["node_b"]
                )
                res_index = self.graph.out_edges(decl)[1]["node_b"]
                if var_name == "PtrDecl":
                    res_name = self.graph.get_name_by_index(
                        self.graph.out_edges(res_index)[0]["node_b"]
                    )
                else:
                    res_name = var_name

                res_node = self.graph.add_node(res_name, decl_scope, NodeType.ID)
                self.graph.add_edge(res_node, assign_node, EdgeLabel.UNIDIR)
                self.graph.add_edge(
                    assign_node,
                    self.graph.out_edges(decl)[0]["node_b"],
                    EdgeLabel.UNIDIR,
                )
                self.graph.remove_edge(decl, self.graph.out_edges(decl)[0]["node_b"])
