from .custom_types import EdgeLabel, NodeIndex, NodeType
from .rustworkX import GraphRx


class DeclAndInitParser:
    def __init__(self, graph: GraphRx) -> None:
        self.graph = graph

    # Get the name of the left hand side of the declaration
    # (the assignee, e.g. in "int a = 5", the assignee is "a")
    def _get_assignee_name(self, decl: NodeIndex) -> str:
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

    def _add_Body2Assign_edge(self, decl: NodeIndex) -> NodeIndex | None:
        body_edge = self.graph.in_edge_with_index(decl, 0)
        if body_edge is None:
            return None
        body_node = body_edge["node_a"]
        decl_scope = self.graph.get_scope_by_index(decl)
        assign_node = self.graph.add_node("Assign", decl_scope)
        self.graph.add_edge(body_node, assign_node, EdgeLabel.UNIDIR, 100)
        return assign_node

    def _add_assignee2Assign_edge(
        self, decl: NodeIndex, assign_node: NodeIndex
    ) -> None:
        decl_scope = self.graph.get_scope_by_index(decl)

        assignee_name = self._get_assignee_name(decl)
        assignee_node = self.graph.add_node(assignee_name, decl_scope, NodeType.ID)
        self.graph.add_edge(assignee_node, assign_node, EdgeLabel.UNIDIR, 101)

    def _add_Assign2Expr_edge(self, decl: NodeIndex, assign_node: NodeIndex) -> None:
        expr_edge = self.graph.out_edge_with_index(decl, 1)
        if expr_edge is None:
            # TODO: Should not happen
            expr_edge = self.graph.out_edges(decl)[0]
        expr_node = expr_edge["node_b"]
        self.graph.add_edge(assign_node, expr_node, EdgeLabel.UNIDIR, 102)
        self.graph.remove_edge(decl, expr_node)

    def parse_decl_and_init(self) -> None:
        for decl in self.graph.find_index_by_name("Decl"):
            # The declaration has an initializer ([assignee] = [expr])
            if len(self.graph.out_edges(decl)) == 2:
                # Add Body -> Assign edge
                new_assign_node = self._add_Body2Assign_edge(decl)
                if new_assign_node is None:
                    continue

                # Add [assignee] node and [assignee] -> Assgin edge
                self._add_assignee2Assign_edge(decl, new_assign_node)

                # Add Assign -> [expr] edge
                self._add_Assign2Expr_edge(decl, new_assign_node)
