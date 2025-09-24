import copy
from collections.abc import Generator
from pathlib import Path

import rustworkx as rx
from pycparser import c_generator
from typing_extensions import NamedTuple, cast

from .ast_visitor import ASTVisitor
from .custom_types import NodeIndex, VarAndType
from .drawer import Drawer
from .g_filter import GraphFilterer
from .params_n_globals import ParamsNGlobalsParser
from .parse_decl_n_init import DeclAndInitParser
from .parse_func_calls import FuncCallsParser
from .rustworkX import GraphRx
from .s_graph_builder import SGraphBuilder


class SGraphBuildRet(NamedTuple):
    ast_graph: GraphRx
    s_graph: GraphRx
    reduced_file: str


def find_index_by_name(
    graph: rx.PyDiGraph, node_name: str
) -> Generator[NodeIndex, None, None]:
    for index in graph.node_indices():
        if graph[index]["name"] == node_name:
            yield index


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


def build_s_graph(
    ast: c_generator.CGenerator,
    file_path: Path,
    ansatz: str | None,
    includes: list[str] = [],
    operations: list[str] = [],
    draw: bool = False,
) -> SGraphBuildRet:

    # ast.show(showcoord=True)

    # P1: Make AST rustworkx graph
    graph = GraphRx()
    visitor = ASTVisitor[GraphRx](graph)
    visitor.visit(ast, "Global")
    original_ast = copy.deepcopy(visitor.graph)

    names_parser = ParamsNGlobalsParser(visitor.graph, ansatz)
    names_parser.get_globals_n_params()
    pos_symvars = names_parser.get_sym_var_names()
    drawer1 = Drawer(
        file_path,
        cast(GraphRx, visitor.graph),
        "ast",
        ansatz,
        operations,
        draw,
        pos_symvars,
    )
    drawer1.draw_graph()

    # P2: Separating initialization and declaration
    parser2 = DeclAndInitParser(cast(GraphRx, visitor.graph))
    parser2.parse_decl_and_init()
    drawer2 = Drawer(
        file_path,
        parser2.graph,
        "p2_parseDeclNInit",
        ansatz,
        operations,
        draw,
        pos_symvars,
    )
    drawer2.draw_graph()

    # P3: Parsing function calls, adding an assignation
    parser3 = FuncCallsParser(parser2.graph, ansatz)
    parser3.make_params_name_unique()
    parser3.add_assign_arg_param()
    drawer3 = Drawer(
        file_path,
        parser3.graph,
        "p3_parseFuncCall",
        ansatz,
        operations,
        draw,
        pos_symvars,
    )
    drawer3.draw_graph()

    # P4: Filter irrelevant nodes
    parser4 = GraphFilterer(parser3.graph, ansatz, ast, includes)
    parser4.filter_graph()
    drawer4 = Drawer(
        file_path, parser4.graph, "p4_filter", ansatz, operations, draw, pos_symvars
    )
    drawer4.draw_graph()

    # P5: Make Hoas
    parser5 = SGraphBuilder(parser4.graph, ansatz, includes)
    parser5.make_s_graph()
    drawer5 = Drawer(
        file_path, parser5.graph, "p5_hoas", ansatz, operations, draw, pos_symvars
    )
    drawer5.draw_graph()

    generator = c_generator.CGenerator()
    # TODO: Should be in a separate class
    reduced_file = generator.visit(parser4.get_subtree())

    return SGraphBuildRet(
        ast_graph=cast(GraphRx, original_ast),
        s_graph=parser5.graph,
        reduced_file=reduced_file,
    )
