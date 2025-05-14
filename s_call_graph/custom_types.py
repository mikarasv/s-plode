from enum import Enum, auto
from typing import NamedTuple, TypeAlias

import rustworkx as rx


class EdgeType(Enum):
    AST = auto()
    HOAS = auto()


class NodeType(Enum):
    ID = auto()
    NONE = ""


NodeIndex: TypeAlias = int

FuncName: TypeAlias = str


class NodeDict(NamedTuple):
    name: str
    node_index: NodeIndex | None
    scope: FuncName
    node_type: NodeType


class GlobalVar(NamedTuple):
    g_var: NodeDict
    var_type: NodeDict


class SymbolicGlobal(NamedTuple):
    global_var: GlobalVar
    is_symbolic: bool


class HoasBuildRet(NamedTuple):
    hoas_graph: rx.PyDiGraph
    reduced_file: str
    global_vars: set[GlobalVar]


class EdgeLabel(Enum):
    UNIDIR = "unidir"
    BIDIR = ""
    INVIS = "invisible"


class EdgeData(NamedTuple):
    label: str
    index: int | None
    from_: EdgeType


class EdgeDict(NamedTuple):
    node_a: NodeIndex
    node_b: NodeIndex
    data: EdgeData
