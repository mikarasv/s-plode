from enum import Enum, auto
from typing import NamedTuple, Optional, Set, TypeAlias

import rustworkx as rx
from pycparser import c_ast


class EdgeType(Enum):
    AST = auto()
    HOAS = auto()


class NodeType(Enum):
    ID = auto()
    NONE = ""


NodeIndex: TypeAlias = int

Scope: TypeAlias = str


class NodeDict(NamedTuple):
    name: str
    node_index: Optional[NodeIndex]
    scope: Scope
    node_type: NodeType


class GlobalVar(NamedTuple):
    g_var: NodeDict
    var_type: NodeDict


class ParsedASTRet(NamedTuple):
    subtree: c_ast.FileAST
    global_vars: Set[GlobalVar]


class SymbolicGlobal(NamedTuple):
    global_var: GlobalVar
    is_symbolic: bool


class HoasBuildRet(NamedTuple):
    hoas_graph: rx.PyDiGraph
    reduced_file: str
    global_vars: Set[GlobalVar]
