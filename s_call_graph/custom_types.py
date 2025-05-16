from enum import Enum, auto
from typing import NamedTuple, Optional, TypeAlias, TypedDict

import rustworkx as rx


class EdgeType(Enum):
    AST = auto()
    HOAS = auto()


class NodeType(Enum):
    ID = auto()
    NONE = ""


NodeIndex: TypeAlias = int

FuncName: TypeAlias = str


class NodeDict(TypedDict):
    name: str
    scope: FuncName
    node_type: NodeType
    node_index: Optional[NodeIndex]


class GlobalVar(TypedDict):
    g_var: NodeDict
    var_type: NodeDict


class SymbolicGlobal(NamedTuple):
    global_var: GlobalVar
    is_symbolic: bool


class HoasBuildRet(NamedTuple):
    hoas_graph: rx.PyDiGraph
    reduced_file: str
    global_vars: list[GlobalVar]


class EdgeLabel(Enum):
    UNIDIR = "unidir"
    BIDIR = ""
    INVIS = "invisible"


class EdgeData(TypedDict):
    label: EdgeLabel
    edge_index: Optional[int]
    from_: EdgeType


class EdgeDict(TypedDict):
    node_a: NodeIndex
    node_b: NodeIndex
    data: EdgeData


class BFSSuccessor(NamedTuple):
    node: NodeDict
    successors: list[NodeDict]
