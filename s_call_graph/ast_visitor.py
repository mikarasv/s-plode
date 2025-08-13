from typing import Generic

from pycparser import c_ast

from .custom_types import EdgeLabel, FuncName, NodeIndex, NodeType
from .genericGraph import GraphType


class ASTVisitor(c_ast.NodeVisitor):  # type: ignore
    def __init__(self, graph: Generic[GraphType]) -> None:
        self.graph = graph

    def visit(self, node: c_ast.Node, scope: FuncName) -> NodeIndex:
        method_name = f"visit_{node.__class__.__name__.lower()}"
        method = getattr(self, method_name, self.default_visit)
        return method(node, scope)

    def default_visit(self, node: c_ast.Node, scope: FuncName) -> NodeIndex:
        node_id = self.graph.add_node(node.__class__.__name__, scope)
        return self._visit_children(node, node_id, scope)

    # ---- Specific Visitors ---- #
    def visit_id(self, node: c_ast.ID, scope: FuncName) -> NodeIndex:
        return self.graph.add_node(node.name, scope, NodeType.ID)

    def visit_constant(self, node: c_ast.Constant, scope: FuncName) -> NodeIndex:
        return self.graph.add_node(node.value, scope)

    def visit_typedecl(self, node: c_ast.TypeDecl, scope: FuncName) -> NodeIndex:
        name = node.declname
        if node.declname is None:
            name = "None"
        node_id = self.graph.add_node(name, scope, NodeType.ID)
        return self._visit_children(node, node_id, scope)

    def visit_unaryop(self, node: c_ast.UnaryOp, scope: FuncName) -> NodeIndex:
        node_id = self.graph.add_node(node.op, scope)
        return self._visit_children(node, node_id, scope)

    def visit_binaryop(self, node: c_ast.BinaryOp, scope: FuncName) -> NodeIndex:
        node_id = self.graph.add_node(node.op, scope)
        child_l = self.visit(node.left, scope)
        child_r = self.visit(node.right, scope)

        self.graph.add_edge(node_id, child_l, EdgeLabel.UNIDIR, 0)
        self.graph.add_edge(node_id, child_r, EdgeLabel.UNIDIR, 1)

        return node_id

    def visit_identifiertype(
        self, node: c_ast.IdentifierType, scope: FuncName
    ) -> NodeIndex:
        return self.graph.add_node(" ".join(node.names), scope)

    def visit_compound(self, node: c_ast.Compound, scope: FuncName) -> NodeIndex:
        node_id = self.graph.add_node("Body", scope)
        return self._visit_children(node, node_id, scope)

    def visit_funcdef(self, node: c_ast.FuncDef, scope: FuncName) -> NodeIndex:
        node_id = self.graph.add_node(node.decl.name, scope, NodeType.ID)

        actual_node_type = node.decl
        while not isinstance(actual_node_type, c_ast.IdentifierType):
            actual_node_type = actual_node_type.type

        fun_type_node = self.graph.add_node(
            " ".join(actual_node_type.names), node.decl.name
        )

        self.graph.add_edge(node_id, fun_type_node, EdgeLabel.UNIDIR, 0)

        # Add function params
        if node.decl.type.args is not None:
            params_root = self.graph.add_node("Params", node.decl.name)

            # Ensures that Params node always has index 1
            self.graph.add_edge(node_id, params_root, EdgeLabel.UNIDIR, 1)
            for index, param in enumerate(node.decl.type.args.params):
                self.graph.add_edge(
                    params_root,
                    self.visit(param, scope=node.decl.name),
                    EdgeLabel.UNIDIR,
                    index,
                )

        body_id = self.visit(node.body, node.decl.name)
        self.graph.add_edge(node_id, body_id, EdgeLabel.UNIDIR, 2)

        return node_id

    def visit_decl(self, node: c_ast.Decl, scope: FuncName) -> NodeIndex:
        node_id = self.graph.add_node("Decl", scope)
        return self._visit_children(node, node_id, scope)

    def visit_assignment(self, node: c_ast.Assignment, scope: FuncName) -> NodeIndex:
        node_id = self.graph.add_node("Assign", scope)
        child_l = self.visit(node.children()[0][1], scope)
        child_r = self.visit(node.children()[1][1], scope)
        self.graph.add_edge(child_l, node_id, EdgeLabel.UNIDIR, 0)
        self.graph.add_edge(node_id, child_r, EdgeLabel.UNIDIR, 0)
        return node_id

    # ---- Helper Function ---- #
    def _visit_children(
        self, node: c_ast.Node, node_id: NodeIndex, scope: FuncName
    ) -> NodeIndex:
        unidir = self.graph.get_name_by_index(node_id) in [
            "Body",
            "FileAST",
            "Decl",
            "Params",
            "FuncCall",
            "ExprList",
            "Typedef",
            "PtrDecl",
        ]
        for index, (_, child) in enumerate(node.children()):
            child_id = self.visit(child, scope)
            label = EdgeLabel.BIDIR
            if unidir:
                label = EdgeLabel.UNIDIR

            self.graph.add_edge(node_id, child_id, label, index)

        return node_id
