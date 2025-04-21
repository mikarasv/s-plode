import os
import sys
from collections import defaultdict
from typing import Any, Callable, Dict, Final, Generator, List, Set

import pydot
import rustworkx as rx
from custom_types import (
    EdgeType,
    HoasBuildRet,
    NodeDict,
    NodeIndex,
    NodeType,
    ParsedASTRet,
    ParsedGlobalVars,
    Scope,
    SymbolicGlobal,
)
from pycparser import c_ast, parse_file


def add_node(
    graph: rx.PyDiGraph, name: str, scope: Scope, node_type: NodeType = NodeType.NONE
) -> NodeIndex:
    node_data: NodeDict = {
        "name": name,
        "scope": scope,
        "node_type": node_type,
    }
    index = graph.add_node(node_data)

    # index = graph.add_node(NodeDict(name, scope, node_type))
    graph[index]["node_index"] = index
    return index


def add_edge(
    graph: rx.PyDiGraph,
    parent: NodeIndex,
    child: NodeIndex,
    label: str,
    index: NodeIndex | None = None,
    origin: EdgeType = EdgeType.AST,
) -> None:
    graph.add_edge(parent, child, {"label": label, "index": index, "from": origin})
    if label == "":
        graph.add_edge(
            child, parent, {"label": "invisible", "index": "", "from": origin}
        )


class ASTVisitor(c_ast.NodeVisitor):  # type: ignore
    def __init__(self) -> None:
        self.graph: rx.PyDiGraph = rx.PyDiGraph()

    def visit(self, node: c_ast.Node, scope: Scope) -> NodeIndex:
        method_name = f"visit_{node.__class__.__name__.lower()}"
        method = getattr(self, method_name, self.default_visit)
        return method(node, scope)

    def default_visit(self, node: c_ast.Node, scope: Scope) -> NodeIndex:
        node_id = add_node(self.graph, node.__class__.__name__, scope)
        return self._visit_children(node, node_id, scope)

    # ---- Specific Visitors ---- #
    def visit_id(self, node: c_ast.ID, scope: Scope) -> NodeIndex:
        return add_node(self.graph, node.name, scope, NodeType.ID)

    def visit_constant(self, node: c_ast.Constant, scope: Scope) -> NodeIndex:
        return add_node(self.graph, node.value, scope)

    def visit_typedecl(self, node: c_ast.TypeDecl, scope: Scope) -> NodeIndex:
        name = node.declname
        if node.declname is None:
            name = "None"
        node_id = add_node(self.graph, name, scope, NodeType.ID)
        return self._visit_children(node, node_id, scope)

    def visit_unaryop(self, node: c_ast.UnaryOp, scope: Scope) -> NodeIndex:
        node_id = add_node(self.graph, node.op, scope)
        return self._visit_children(node, node_id, scope)

    def visit_binaryop(self, node: c_ast.BinaryOp, scope: Scope) -> NodeIndex:
        node_id = add_node(self.graph, node.op, scope)
        child_l = self.visit(node.left, scope)
        child_r = self.visit(node.right, scope)

        add_edge(self.graph, node_id, child_l, "", 0)
        add_edge(self.graph, node_id, child_r, "", 1)

        return node_id

    def visit_identifiertype(
        self, node: c_ast.IdentifierType, scope: Scope
    ) -> NodeIndex:
        return add_node(self.graph, " ".join(node.names), scope)

    def visit_compound(self, node: c_ast.Compound, scope: Scope) -> NodeIndex:
        node_id = add_node(self.graph, "Body", scope)
        return self._visit_children(node, node_id, scope)

    def visit_funcdef(self, node: c_ast.FuncDef, scope: Scope) -> NodeIndex:
        node_id = add_node(self.graph, node.decl.name, scope, NodeType.ID)

        fun_type_node = add_node(
            self.graph, " ".join(node.decl.type.type.type.names), node.decl.name
        )

        add_edge(self.graph, node_id, fun_type_node, "unidir", 0)

        # Add function params
        if node.decl.type.args is not None:
            params_root = add_node(self.graph, "Params", node.decl.name)

            add_edge(self.graph, node_id, params_root, "unidir", 1)
            for index, param in enumerate(node.decl.type.args.params):
                add_edge(
                    self.graph,
                    params_root,
                    self.visit(param, scope=node.decl.name),
                    "unidir",
                    index,
                )

        body_id = self.visit(node.body, node.decl.name)
        add_edge(self.graph, node_id, body_id, "unidir", 2)

        return node_id

    def visit_decl(self, node: c_ast.Decl, scope: Scope) -> NodeIndex:
        node_id = add_node(self.graph, "Decl", scope)
        return self._visit_children(node, node_id, scope)

    def visit_assignment(self, node: c_ast.Assignment, scope: Scope) -> NodeIndex:
        node_id = add_node(self.graph, "Assign", scope)
        child_l = self.visit(node.children()[0][1], scope)
        child_r = self.visit(node.children()[1][1], scope)
        add_edge(self.graph, child_l, node_id, "unidir", 0)
        add_edge(self.graph, node_id, child_r, "unidir", 0)
        return node_id

    # ---- Helper Function ---- #
    def _visit_children(
        self, node: c_ast.Node, node_id: NodeIndex, scope: Scope
    ) -> NodeIndex:
        for index, (_, child) in enumerate(node.children()):
            child_id = self.visit(child, scope)
            unidir = self.graph[node_id]["name"] in [
                "Body",
                "FileAST",
                "Decl",
                "Params",
                "FuncCall",
                "ExprList",
            ]
            label = ""
            if unidir:
                label = "unidir"
            add_edge(self.graph, node_id, child_id, label, index)

        return node_id


# TODO: change it to find_node
def find_index_by_name(
    graph: rx.PyDiGraph, node_name: str, scope: Scope | None = None
) -> Generator[int, None, None]:
    def matches(index: int) -> bool:
        return graph[index]["name"] == node_name and (
            scope is None or graph[index]["scope"] == scope
        )

    for index in graph.node_indices():
        if matches(index):
            yield index


def parse_globals(graph: rx.PyDiGraph) -> ParsedGlobalVars:
    def get_root_id() -> NodeIndex | None:
        return next(find_index_by_name(graph, "FileAST"), None)

    def get_decl_nodes(root_id: NodeIndex) -> List[NodeIndex]:
        return [
            node for node in graph.neighbors(root_id) if graph[node]["name"] == "Decl"
        ]

    def collect_global_vars(decl_nodes: List[NodeIndex]) -> Set[NodeIndex]:
        return {
            graph[child]["node_index"]
            for decl in decl_nodes
            for child in graph.neighbors(decl)
        }

    def collect_global_var_types(global_vars_idxs: Set[NodeIndex]) -> Set[NodeIndex]:
        return {
            succ["node_index"]
            for var_idx in global_vars_idxs
            for _, successors in rx.bfs_successors(graph, var_idx)
            for succ in successors
        }

    root_id = get_root_id()
    if root_id is None:
        return ParsedGlobalVars(global_vars=set(), types=set())

    decl_nodes = get_decl_nodes(root_id)
    global_vars = collect_global_vars(decl_nodes)
    global_vars_type = collect_global_var_types(global_vars)

    return ParsedGlobalVars(global_vars, types=global_vars_type)


def get_called_func_nodes(graph: rx.PyDiGraph, ansatz: str) -> Set[NodeIndex]:
    def collect_func_body(func_idx: NodeIndex) -> Set[NodeIndex]:
        return {
            succ["node_index"]
            for _, successors in rx.bfs_successors(graph, func_idx)
            for succ in successors
        }

    def find_local_func_calls() -> List[NodeIndex]:
        return [
            node
            for node in find_index_by_name(graph, "FuncCall") or []
            if graph[node]["scope"] == ansatz
        ]

    def get_called_func_index(call: NodeIndex) -> NodeIndex | None:
        edges = graph.out_edges(call)
        if len(edges) < 2:
            return None
        name = graph[edges[1][1]]["name"]
        return next(find_index_by_name(graph, name, "Global"), None)

    def resolve_called_funcs(func_calls: List[NodeIndex]) -> Set[NodeIndex]:
        result = set()
        for call in func_calls:
            called_idx = get_called_func_index(call)
            if called_idx is None:
                continue
            result.add(called_idx)
            result.update(collect_func_body(called_idx))
        return result

    func_calls = find_local_func_calls()
    return resolve_called_funcs(func_calls)


def get_subgraph(graph: rx.PyDiGraph, ansatz: str) -> ParsedASTRet:
    def get_ansatz_body() -> Set[NodeIndex]:
        return {node["node_index"] for node in graph.nodes() if node["scope"] == ansatz}

    def map_globals(sg: rx.PyDiGraph, g_vars_index: Set[NodeIndex]) -> List[NodeDict]:
        result: Final[List[NodeDict]] = []
        for i in g_vars_index:
            name = graph[i]["name"]
            for idx in find_index_by_name(sg, name, "Global"):
                for edge in sg.out_edges(idx):
                    if edge[2]["index"] == 0:
                        result.append(
                            NodeDict(
                                name=sg[edge[1]]["name"],
                                node_index=idx,
                                node_type=NodeType.ID,
                                scope="Global",
                            )
                        )
        return result

    g_vars_index, g_vars_type_index = parse_globals(graph)
    called_funcs = get_called_func_nodes(graph, ansatz)

    ansatz_index = next(find_index_by_name(graph, ansatz), None)
    if ansatz_index is None:
        return ParsedASTRet(graph, [])

    ansatz_body = get_ansatz_body()
    sub_nodes = (
        {ansatz_index} | ansatz_body | called_funcs | g_vars_index | g_vars_type_index
    )
    subgraph = graph.subgraph(list(sub_nodes))

    global_vars = map_globals(subgraph, g_vars_index)
    return ParsedASTRet(subgraph, global_vars)


def parse_decl_and_init(graph: rx.PyDiGraph) -> rx.PyDiGraph:
    for decl in find_index_by_name(graph, "Decl"):
        decl_node = graph[decl]
        if len(graph.out_edges(decl)) == 2:
            decl_scope = decl_node["scope"]

            parent_node = graph.in_edges(decl)[0][0]
            assign_node = add_node(graph, "Assign", decl_scope)
            add_edge(graph, parent_node, assign_node, "unidir")

            res = graph[graph.out_edges(decl)[1][1]]
            res_index = graph.out_edges(decl)[1][1]
            if res["name"] == "PtrDecl":
                res_name = graph[graph.out_edges(res_index)[0][1]]["name"]
            else:
                res_name = res["name"]

            res_node = add_node(graph, res_name, decl_scope, NodeType.ID)
            add_edge(graph, res_node, assign_node, "unidir")
            add_edge(graph, assign_node, graph.out_edges(decl)[0][1], "unidir")
            graph.remove_edge(decl, graph.out_edges(decl)[0][1])
    return graph


def make_params_name_unique(graph: rx.PyDiGraph, ansatz: str) -> None:
    def is_valid_func(node: NodeDict) -> bool:
        name = node["name"]
        ret_value: Final[bool] = name != ansatz and name != "Decl"
        return ret_value

    def get_param_idx(func_node: NodeDict) -> NodeIndex | None:
        edges = graph.out_edges(func_node["node_index"])
        if len(edges) < 2:
            return None
        param_idx = edges[1][1]
        if graph[param_idx]["name"] != "Params":
            return None
        return param_idx

    def collect_param_names(param_idx: NodeIndex) -> set[str]:
        return {
            node["name"]
            for _, successors in rx.bfs_successors(graph, param_idx)
            for node in successors
            if node["node_type"] == NodeType.ID
        }

    def rename_if_match(func_node: NodeDict, param_names: set[str]) -> None:
        for _, successors in rx.bfs_successors(graph, func_node["node_index"]):
            for node in successors:
                if node["name"] in param_names:
                    node["name"] = f"_{node['scope']}_{node['name']}"

    for func_node in filter(is_valid_func, graph.successors(0)):
        param_idx = get_param_idx(func_node)
        if param_idx is None:
            continue
        param_names = collect_param_names(param_idx)
        rename_if_match(func_node, param_names)


def get_params_nodes(
    g: rx.PyDiGraph, call: NodeIndex
) -> Generator[NodeDict, None, None]:
    def get_func_index() -> NodeIndex | None:
        called_func_index = next(
            (
                node[1]
                for node in g.out_edges(call)
                if g[node[1]]["node_type"] == NodeType.ID
            ),
            None,
        )
        if called_func_index is None:
            return None

        func_index = next(
            find_index_by_name(g, g[called_func_index]["name"], "Global"), None
        )
        if func_index is None:
            return None
        return func_index

    def get_param_node(params_node: NodeIndex) -> Generator[NodeDict, None, None]:
        return (
            succ
            for _, successors in rx.bfs_successors(g, params_node)
            for succ in successors
            if succ["node_type"] == NodeType.ID
        )

    func_index = get_func_index()
    if func_index is None:
        return None

    params_node = g.out_edges(func_index)[1][1]
    if g[params_node]["name"] == "Params":
        yield from get_param_node(params_node)


def get_func_args(
    graph: rx.PyDiGraph, call: NodeIndex
) -> Generator[NodeDict, None, None]:
    def get_arg_node() -> NodeIndex | None:
        node = next(
            (
                node[1]
                for node in graph.out_edges(call)
                if graph[node[1]]["name"] == "ExprList"
            ),
            None,
        )
        if node is None:
            None
        return node

    def get_arg_node_index(arg_node: NodeIndex) -> Generator[NodeDict, None, None]:
        return (
            succ
            for _, successors in rx.bfs_successors(graph, arg_node)
            for succ in successors
            if succ["node_type"] == NodeType.ID
        )

    arg_node = get_arg_node()
    if arg_node is None:
        return None

    node = graph[arg_node]
    if node["name"] == "ExprList":
        yield from get_arg_node_index(arg_node)


def add_assign_arg_param(g: rx.PyDiGraph) -> rx.PyDiGraph:
    def get_body_node_in_scope(scope: str) -> NodeIndex | None:
        return next(
            (
                node
                for node in find_index_by_name(g, "Body")
                if g[node]["scope"] == scope
            ),
            None,
        )

    def add_assign_nodes(
        scope: str,
        body_node: NodeIndex,
        param: NodeDict,
        arg: NodeDict,
    ) -> None:
        assign_node = add_node(g, "Assign", scope)
        add_edge(g, body_node, assign_node, "unidir")

        param_node = add_node(g, param["name"], scope, NodeType.ID)
        add_edge(g, param_node, assign_node, "unidir")

        arg_node = add_node(g, arg["name"], scope, NodeType.ID)
        add_edge(g, assign_node, arg_node, "unidir")

        arg["name"] = param["name"]

    def process_func_call(call: NodeIndex) -> None:
        func_call_node = g[call]
        scope = func_call_node["scope"]

        param_nodes = get_params_nodes(g, call)
        if not param_nodes:
            return

        args_nodes = get_func_args(g, call)
        if not args_nodes:
            return

        body_node = get_body_node_in_scope(scope)
        if body_node is None:
            return

        for param, arg in zip(param_nodes, args_nodes):
            add_assign_nodes(scope, body_node, param, arg)

    call_nodes = find_index_by_name(g, "FuncCall")
    if not call_nodes:
        return g

    for call in call_nodes:
        process_func_call(call)

    return g


def filter_graph(graph: rx.PyDiGraph, ansatz: str) -> rx.PyDiGraph:
    def get_ansatz_decls(ansatz_child: NodeIndex) -> List[NodeIndex]:
        return [
            index
            for index in list(graph.successor_indices(ansatz_child))
            if graph[index]["name"] == "Decl"
        ]

    def get_excluded_nodes() -> List[NodeIndex]:
        return [
            x
            for xs in [
                find_index_by_name(graph, irrelevant_node)
                # for irrelevant_node in ["ExprList", "Params", ansatz]
                for irrelevant_node in ["Params", "Decl", ansatz]
            ]
            for x in xs
        ]

    filtered_graph = graph.copy()
    ansatz_index = next(find_index_by_name(graph, ansatz), None)
    if ansatz_index is None:
        return filtered_graph
    ansatz_children = list(graph.successor_indices(ansatz_index))

    ansatz_decls = get_ansatz_decls(ansatz_children[0])
    exclude_nodes = get_excluded_nodes()
    filtered_graph.remove_nodes_from(exclude_nodes + ansatz_children + ansatz_decls)

    return filtered_graph


def make_hoas(graph: rx.PyDiGraph) -> rx.PyDiGraph:
    def group_id_nodes() -> Dict[str, List[NodeIndex]]:
        name_to_nodes = defaultdict(list)
        for node in graph.node_indices():
            if graph[node]["node_type"] == NodeType.ID:
                name_to_nodes[graph[node]["name"]].append(node)
        return name_to_nodes

    def connect_hoas_edges(name_to_nodes: Dict[str, List[NodeIndex]]) -> None:
        for nodes in name_to_nodes.values():
            nodes.sort()
            for i, u in enumerate(nodes):
                for v in nodes[i + 1 :]:
                    add_edge(graph, u, v, "", origin=EdgeType.HOAS)

    name_to_nodes = group_id_nodes()
    connect_hoas_edges(name_to_nodes)
    return graph


def symbolic_globals(
    global_vars: List[NodeDict], graph: rx.PyDiGraph, operations: List[str]
) -> List[SymbolicGlobal]:
    def is_global_symbolic(index: NodeIndex) -> bool:
        return any(
            rx.has_path(graph, op_node, index)
            for op in operations
            for op_node in op_nodes[op]
        )

    op_nodes = {op: find_index_by_name(graph, op) for op in operations}
    return [
        SymbolicGlobal(
            v,
            is_global_symbolic(v["node_index"]),
        )
        for v in global_vars
    ]


def build_hoas(
    file_path: str, ansatz: str, includes: str = "", operations: List[str] = []
) -> HoasBuildRet:
    ast = parse_file(
        file_path,
        use_cpp=True,
        cpp_path="gcc",
        cpp_args=["-E", r"-Iutils/fake_libc_include " + includes],
    )

    # ast.show(showcoord=True)
    visitor = ASTVisitor()

    # P1: Make AST rustworkx graph
    visitor.visit(ast, "Global")
    draw_graph(visitor.graph, file_path, "p1_ast", operations)

    # P2: Separating initialization and declaration
    parsed_graph = parse_decl_and_init(visitor.graph)
    draw_graph(parsed_graph, file_path, "p2_parseDeclNInit", operations)

    # P3: Parsing function calls, adding an assignation
    make_params_name_unique(parsed_graph, ansatz)
    parsed_graph = add_assign_arg_param(parsed_graph)
    draw_graph(parsed_graph, file_path, "p3_parseFuncCall", operations)

    # P3.5: Get call-graph subgraph
    subgraph, global_vars = get_subgraph(parsed_graph, ansatz)
    draw_graph(subgraph, file_path, "p3.5_sg", operations)

    # P4:
    filtered_graph = filter_graph(subgraph, ansatz)
    draw_graph(filtered_graph, file_path, "p4_filter", operations)

    # P5
    hoas_graph = make_hoas(filtered_graph)
    draw_graph(hoas_graph, file_path, "p5_hoas", operations)

    return HoasBuildRet(hoas_graph, global_vars)


def edge_attr(data: Dict[str, Any]) -> Dict[str, str]:
    def get_style(source: EdgeType) -> str:
        match source:
            case EdgeType.HOAS:
                return "dotted"
            case _:  # default
                return "solid"

    style = get_style(data.get("from", ""))
    label = str(data["index"])

    label_type = data.get("label")
    if label_type == "invisible":
        return {"label": label, "style": "invis"}
    if label_type == "unidir":
        return {"style": style, "label": label, "dir": "forward"}

    return {"style": style, "label": label, "dir": "both", "fontcolor": "white"}


def node_attr_factory(
    operations: List[str],
) -> Callable[[NodeDict], Dict[str, str]]:
    def node_attr(data: NodeDict) -> Dict[str, str]:
        if data["name"] in operations:
            color = "red"
        elif data["scope"] == "Global" and data["node_type"] == NodeType.ID:
            color = "blue"
        else:
            color = "black"
        return {
            "label": str(data["name"]) + str(data["node_index"]),
            "color": "gray",
            "fillcolor": color,
            "style": "filled",
            "fontcolor": "white",
        }

    return node_attr


def draw_graph(
    graph: rx.PyDiGraph, file_path: str, end: str = "_dat", operations: List[str] = []
) -> None:

    node_attr_func = node_attr_factory(operations)
    dot_str = graph.to_dot(
        node_attr=node_attr_func,
        edge_attr=edge_attr,
    )
    if not dot_str:
        raise ValueError("dot_str is empty or None!")

    dot = pydot.graph_from_dot_data(dot_str)[0]
    folder_path = os.path.splitext(file_path)[0]
    os.makedirs(folder_path, exist_ok=True)
    dot.write_png(folder_path + "/" + end + ".png")


def main() -> None:
    if len(sys.argv) != 4:
        print("Arguments must be: [file_path] [ansatz] [operations]")
    else:
        file_path = sys.argv[1]
        ansatz = sys.argv[2]
        operations = sys.argv[3].split(",")
        hoas_graph, global_vars = build_hoas(file_path, ansatz, operations=operations)

        global_vars_value = symbolic_globals(global_vars, hoas_graph, operations)
        print(
            "Symbolic Global Vars: ",
            [
                f"{hoas_graph[var["node_index"]]["name"]}: {value}"
                for (var, value) in global_vars_value
            ],
        )


if __name__ == "__main__":
    main()
