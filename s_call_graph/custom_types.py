from enum import Enum, auto
from typing import List, NamedTuple, NotRequired, Set, TypeAlias, TypedDict

import rustworkx as rx


class EdgeType(Enum):
    AST = auto()
    HOAS = auto()


class NodeType(Enum):
    ID = auto()
    NONE = ""


NodeIndex: TypeAlias = int

Scope: TypeAlias = str


class NodeDict(TypedDict):
    name: str
    node_index: NotRequired[NodeIndex]
    scope: Scope
    node_type: NodeType


class ParsedASTRet(NamedTuple):
    subgraph: rx.PyDiGraph
    global_vars: List[NodeDict]


class SymbolicGlobal(NamedTuple):
    global_var: NodeDict
    is_symbolic: bool


class ParsedGlobalVars(NamedTuple):
    global_vars: Set[NodeIndex]
    types: Set[NodeIndex]


class HoasBuildRet(NamedTuple):
    hoas_graph: rx.PyDiGraph
    global_vars: List[NodeDict]
