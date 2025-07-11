from collections.abc import Generator
from pathlib import Path

import rustworkx as rx
from pycparser import c_generator, parse_file

from .ast_visitor import ASTVisitor
from .custom_types import FuncName, HoasBuildRet, NodeDict, NodeIndex, VarAndType
from .drawer import Drawer
from .g_filter import GraphFilterer
from .hoas_builder import HoasBuilder
from .params_n_globals import ParamsNGlobalsParser
from .parse_decl_n_init import DeclAndInitParser
from .parse_func_calls import FuncCallsParser
from .rustworkX import GraphRx


def matches(node: NodeDict, node_name: str, scope: FuncName | None) -> bool:
    return node["name"] == node_name and (scope is None or node["scope"] == scope)


def find_index_by_name(
    graph: rx.PyDiGraph, node_name: str, scope: FuncName | None = None
) -> Generator[NodeIndex, None, None]:
    for node in graph.nodes():
        if matches(node, node_name, scope):
            yield node["node_index"]


def is_symbolic(
    graph: rx.PyDiGraph,
    op_nodes: dict[str, Generator[NodeIndex, None, None]],
    operations: list[str],
    index: NodeIndex,
) -> bool:
    return any(
        rx.has_path(graph, op_node, index)
        for op in operations
        for op_node in op_nodes[op]
    )


def is_var_symbolic(
    graph: rx.PyDiGraph,
    operations: list[str],
    index: NodeIndex | None,
) -> bool:
    if index is None:
        return False
    op_nodes = {op: find_index_by_name(graph, op) for op in operations}

    return is_symbolic(graph, op_nodes, operations, index)


def symbolic_vars(
    pos_sym_vars: list[VarAndType], graph: rx.PyDiGraph, operations: list[str]
) -> list[VarAndType]:
    return list(
        filter(
            lambda v: is_var_symbolic(graph, operations, v["var_dict"]["node_index"]),
            pos_sym_vars,
        )
    )


def build_hoas(
    file_path: Path,
    ansatz: str | None,
    includes: list[str] = [],
    operations: list[str] = [],
    draw: bool = False,
) -> HoasBuildRet:
    ast = parse_file(
        file_path,
        use_cpp=True,
        cpp_path="clang",
        cpp_args=["-E", "-I."],
    )

    # ast.show(showcoord=True)

    # P1: Make AST rustworkx graph
    graph = GraphRx()
    visitor = ASTVisitor(graph)
    visitor.visit(ast, "Global")
    drawer1 = Drawer(file_path, visitor.graph, "ast", ansatz, operations, draw)
    drawer1.draw_graph()

    # P1.5: Get file content with scope reducedn and global variables
    parser1_5 = ParamsNGlobalsParser(visitor.graph, ansatz)
    parser1_5.get_globals_n_params()

    # P2: Separating initialization and declaration
    parser2 = DeclAndInitParser(visitor.graph)
    parser2.parse_decl_and_init()
    drawer2 = Drawer(
        file_path, parser2.graph, "p2_parseDeclNInit", ansatz, operations, draw
    )
    drawer2.draw_graph()

    # P3: Parsing function calls, adding an assignation
    parser3 = FuncCallsParser(parser2.graph, ansatz)
    parser3.make_params_name_unique()
    parser3.add_assign_arg_param()
    drawer3 = Drawer(
        file_path, parser3.graph, "p3_parseFuncCall", ansatz, operations, draw
    )
    drawer3.draw_graph()

    # P4: Filter irrelevant nodes
    parser4 = GraphFilterer(parser3.graph, ansatz, ast, includes)
    parser4.filter_graph()
    drawer4 = Drawer(file_path, parser4.graph, "p4_filter", ansatz, operations, draw)
    drawer4.draw_graph()

    # P5: Make Hoas
    parser5 = HoasBuilder(parser4.graph, ansatz, includes)
    parser5.make_hoas()
    drawer5 = Drawer(file_path, parser5.graph, "p5_hoas", ansatz, operations, draw)
    drawer5.draw_graph()

    generator = c_generator.CGenerator()
    reduced_file = generator.visit(parser4.get_subtree())

    return HoasBuildRet(
        parser5.graph.graph,
        reduced_file,
        parser1_5.global_vars,
        parser1_5.ansatz_params,
    )
