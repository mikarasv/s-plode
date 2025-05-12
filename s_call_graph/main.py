from typing import List, Optional, Set

import rustworkx as rx
from pycparser import c_generator, parse_file

from .ast_visitor import ASTVisitor
from .custom_types import GlobalVar, HoasBuildRet, NodeIndex, SymbolicGlobal
from .drawer import Drawer
from .g_filter import GraphFilterer
from .hoas_builder import HoasBuilder
from .parse_dec_n_init import DeclAndInitParser
from .parse_func_calls import FuncCallsParser
from .rustworkX import GraphRx
from .subtree_n_globals import SubtreeNGlobalsParser


def is_global_symbolic(graph: GraphRx, operations: List[str], index: NodeIndex) -> bool:
    op_nodes = {op: graph.find_index_by_name(graph, op) for op in operations}
    return any(
        rx.has_path(graph, op_node, index)
        for op in operations
        for op_node in op_nodes[op]
    )


def symbolic_globals(
    global_vars: Set[GlobalVar], graph: GraphRx, operations: List[str]
) -> Set[SymbolicGlobal]:
    return {
        SymbolicGlobal(
            g,
            is_global_symbolic(graph, operations, g.g_var.node_index),
        )
        for g in global_vars
    }


def build_hoas(
    file_path: str,
    ansatz: Optional[str],
    includes: str = "",
    operations: List[str] = [],
    draw: bool = True,
) -> HoasBuildRet:
    ast = parse_file(
        file_path,
        use_cpp=True,
        cpp_path="gcc",
        cpp_args=["-E", r"-Iutils/fake_libc_include " + includes],
    )

    # ast.show(showcoord=True)

    # P1: Make AST rustworkx graph
    graph = GraphRx()
    visitor = ASTVisitor(graph)
    visitor.visit(ast, "Global")
    drawer1 = Drawer(file_path, visitor.graph, "ast", operations, draw)
    drawer1.draw_graph()

    # P2: Separating initialization and declaration
    parser2 = DeclAndInitParser(visitor.graph)
    parser2.parse_decl_and_init()
    drawer2 = Drawer(file_path, parser2.graph, "p2_parseDeclNInit", operations, draw)
    drawer2.draw_graph()

    # P3: Parsing function calls, adding an assignation
    parser3 = FuncCallsParser(parser2.graph, ansatz)
    parser3.add_assign_arg_param()
    drawer3 = Drawer(file_path, parser3.graph, "p3_parseFuncCall", operations, draw)
    drawer3.draw_graph()

    # P4:
    parser4 = GraphFilterer(parser3.graph, ansatz)
    parser4.filter_graph()
    drawer4 = Drawer(file_path, parser4.graph, "p4_filter", operations, draw)
    drawer4.draw_graph()

    # P5
    parser5 = HoasBuilder(parser4.graph)
    parser5.make_hoas()
    drawer5 = Drawer(file_path, parser5.graph, "p5_hoas", operations, draw)
    drawer5.draw_graph()

    # P6: Get file content with scope reducedn and global variables
    parser6 = SubtreeNGlobalsParser(parser5.graph, ast, ansatz)
    global_vars = parser6.get_subtree_and_globals()

    generator = c_generator.CGenerator()
    reduced_file = generator.visit(parser6.ast)

    return HoasBuildRet(parser6.graph, reduced_file, global_vars)
