from .custom_types import EdgeLabel, NodeIndex, NodeType
from .rustworkX import GraphRx


class DeclAndInitParser:
    def __init__(self, graph: GraphRx) -> None:
        self.graph = graph

    def get_assignee_name(self, decl: NodeIndex) -> str:
        assignee_edge = self.graph.out_edge_with_index(decl, 0)
        if assignee_edge is None:
            raise ValueError(f"Declaration {decl} has no assignee edge.")
        assignee_idx = assignee_edge["node_b"]
        assignee_name = self.graph.get_name_by_index(assignee_idx)
        while assignee_name == "PtrDecl":
            assignee_edge = self.graph.out_edge_with_index(assignee_idx, 0)
            if assignee_edge is None:
                raise ValueError(f"Declaration {decl} has no assignee edge.")
            assignee_idx = assignee_edge["node_b"]
            assignee_name = self.graph.get_name_by_index(assignee_idx)
        return assignee_name

    def add_Body2Assign_edge(self, decl: NodeIndex) -> NodeIndex | None:
        body_edge = self.graph.in_edge_with_index(decl, 0)
        if body_edge is None:
            return None
        body_node = body_edge["node_a"]
        decl_scope = self.graph.get_scope_by_index(decl)
        assign_node = self.graph.add_node("Assign", decl_scope)
        self.graph.add_edge(body_node, assign_node, EdgeLabel.UNIDIR)
        return assign_node

    def add_assignee2Assign_edge(self, decl: NodeIndex, assign_node: NodeIndex) -> None:
        decl_scope = self.graph.get_scope_by_index(decl)

        assignee_name = self.get_assignee_name(decl)
        assignee_node = self.graph.add_node(assignee_name, decl_scope, NodeType.ID)
        self.graph.add_edge(assignee_node, assign_node, EdgeLabel.UNIDIR)

    def add_Assign2Expr_edge(self, decl: NodeIndex, assign_node: NodeIndex) -> None:
        expr_edge = self.graph.out_edges(decl)[1]
        if expr_edge is None:
            raise ValueError(
                f"Declaration {self.graph.get_name_by_index(decl)} has no expression edge."
            )
        expr_node = expr_edge["node_b"]
        self.graph.add_edge(assign_node, expr_node, EdgeLabel.UNIDIR)
        self.graph.remove_edge(decl, expr_node)

    def parse_decl_and_init(self) -> None:
        for decl in self.graph.find_index_by_name("Decl"):
            # The declaration has an initializer ([assignee] = [expr])
            if len(self.graph.out_edges(decl)) == 2:
                # Add Body -> Assign edge
                new_assign_node = self.add_Body2Assign_edge(decl)
                if new_assign_node is None:
                    continue

                # Add [assignee] node and [assignee] -> Assgin edge
                self.add_assignee2Assign_edge(decl, new_assign_node)

                # Add Assign -> [expr] edge
                self.add_Assign2Expr_edge(decl, new_assign_node)
