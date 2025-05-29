from enum import Enum, auto
from typing import NamedTuple, TypeAlias, TypedDict

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
    node_index: NodeIndex | None


class VarAndType(TypedDict):
    var_dict: NodeDict
    var_type: NodeDict


class SymbolicVar(NamedTuple):
    var_n_type: VarAndType
    is_symbolic: bool


class HoasBuildRet(NamedTuple):
    hoas_graph: rx.PyDiGraph
    reduced_file: str
    may_be_sym_vars: list[VarAndType]


class EdgeLabel(Enum):
    UNIDIR = "unidir"
    BIDIR = ""
    INVIS = "invisible"


class EdgeData(TypedDict):
    label: EdgeLabel
    edge_index: int | None
    from_: EdgeType


class EdgeDict(TypedDict):
    node_a: NodeIndex
    node_b: NodeIndex
    data: EdgeData
