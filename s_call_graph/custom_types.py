from enum import Enum, auto

from typing_extensions import TypeAlias, TypedDict


class EdgeType(Enum):
    AST = auto()
    NAME_RES = auto()


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


class EdgeLabel(Enum):
    UNIDIR = "unidir"
    BIDIR = ""
    INVIS = "invisible"


class EdgeData(TypedDict):
    label: EdgeLabel
    edge_index: int | None
    from_: EdgeType


class FuncVar(TypedDict):
    var: NodeDict
    index: int


class EdgeDict(TypedDict):
    node_a: NodeIndex
    node_b: NodeIndex
    data: EdgeData
