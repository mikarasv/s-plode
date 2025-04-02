import os
import sys

import pydot
import rustworkx as rx
from pycparser import c_ast, parse_file


def add_node(graph, name, scope, node_type=""):
    index = graph.add_node({"name": name, "scope": scope, "type": node_type})
    graph[index]["index"] = index
    return index


def add_edge(graph, parent, child, label, index="", origin="AST"):
    graph.add_edge(parent, child, {"label": label, "index": index, "from": origin})
    if label == "":
        graph.add_edge(
            parent, child, {"label": "invisible", "index": "", "from": origin}
        )


class ASTVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.graph = rx.PyDiGraph()

    def visit(self, node, scope):
        method_name = f"visit_{node.__class__.__name__.lower()}"
        method = getattr(self, method_name, self.default_visit)
        return method(node, scope)

    def default_visit(self, node, scope):
        node_id = add_node(self.graph, node.__class__.__name__, scope)
        return self._visit_children(node, node_id, scope)

    # ---- Specific Visitors ---- #
    def visit_id(self, node, scope):
        return add_node(self.graph, node.name, scope, "ID")

    def visit_typedecl(self, node, scope):
        node_id = add_node(self.graph, node.declname, scope, "ID")
        return self._visit_children(node, node_id, scope)

    def visit_constant(self, node, scope):
        return add_node(self.graph, node.value, scope)

    def visit_unaryop(self, node, scope):
        node_id = add_node(self.graph, node.op, scope)
        return self._visit_children(node, node_id, scope)

    def visit_binaryop(self, node, scope):
        node_id = add_node(self.graph, node.op, scope)
        child_l = self.visit(node.left, scope)
        child_r = self.visit(node.right, scope)

        add_edge(self.graph, node_id, child_l, "", "0")
        add_edge(self.graph, node_id, child_r, "", "1")

        return node_id

    def visit_identifiertype(self, node, scope):
        return add_node(self.graph, " ".join(node.names), scope)

    def visit_compound(self, node, scope):
        node_id = add_node(self.graph, "Body", scope)
        return self._visit_children(node, node_id, scope)

    def visit_funcdef(self, node, scope):
        node_id = add_node(self.graph, node.decl.name, scope, "ID")

        fun_type_node = add_node(
            self.graph, " ".join(node.decl.type.type.type.names), node.decl.name
        )

        add_edge(self.graph, node_id, fun_type_node, "unidir", "0")

        # Add function params
        if node.decl.type.args is not None:
            params_root = add_node(self.graph, "Params", node.decl.name)

            add_edge(self.graph, node_id, params_root, "unidir", "1")
            for index, param in enumerate(node.decl.type.args.params):
                add_edge(
                    self.graph,
                    params_root,
                    self.visit(param, scope=node.decl.name),
                    "unidir",
                    str(index),
                )

        body_id = self.visit(node.body, node.decl.name)
        add_edge(self.graph, node_id, body_id, "unidir", "2")

        return node_id

    def visit_decl(self, node, scope):
        node_id = add_node(self.graph, "Decl", scope)
        return self._visit_children(node, node_id, scope)

    def visit_assignment(self, node, scope):
        node_id = add_node(self.graph, "Assign", scope)
        child_l = self.visit(node.children()[0][1], scope)
        child_r = self.visit(node.children()[1][1], scope)
        add_edge(self.graph, child_l, node_id, "unidir", "")
        add_edge(self.graph, node_id, child_r, "unidir", "")
        return node_id

    # ---- Helper Function ---- #
    def _visit_children(self, node, node_id, scope):
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
            add_edge(self.graph, node_id, child_id, label, str(index))

        return node_id


def find_index_by_name(graph, node_name, scope=None):
    for index in graph.node_indices():
        if graph[index]["name"] == node_name and (
            scope is None or graph[index]["scope"] == scope
        ):
            yield index


def parse_decl_and_init(graph):
    decl_nodes = find_index_by_name(graph, "Decl") or []
    if decl_nodes is None:
        return graph
    for decl in decl_nodes:
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

            res_node = add_node(graph, res_name, decl_scope, "ID")
            add_edge(graph, res_node, assign_node, "unidir")
            add_edge(graph, assign_node, graph.out_edges(decl)[0][1], "unidir")
            graph.remove_edge(decl, graph.out_edges(decl)[0][1])
    return graph


def make_params_name_unique(graph, ansatz):
    funs_not_ansatz = [
        node for node in graph.successors(0) if node["name"] not in [ansatz, "Decl"]
    ]
    for f in funs_not_ansatz:
        unique_successors = set()
        for _, successors in rx.bfs_successors(graph, f["index"]):
            for succ in successors:
                unique_successors.add(succ["index"])
        function_nodes = list(unique_successors)

        param_node = graph.out_edges(f["index"])[1][1]
        if graph[param_node]["name"] != "Params":  # No params
            break

        unique_successors = set()
        for _, successors in rx.bfs_successors(graph, param_node):
            for succ in successors:
                if succ["type"] == "ID":
                    unique_successors.add(succ["name"])

        fun_params_names = list(unique_successors)

        for node in function_nodes:
            if node is not None and graph[node]["name"] in fun_params_names:
                graph[node]["name"] = f"_{graph[node]["scope"]}_{graph[node]["name"]}"


def get_func_params(graph, func):
    params_node = graph.out_edges(func)[1][1]
    if graph[params_node]["name"] == "Params":
        for _, successors in rx.bfs_successors(graph, params_node):
            for succ in successors:
                if succ["type"] == "ID":
                    yield succ


def get_func_args(graph, args):
    if graph[args]["name"] == "ExprList":
        for _, successors in rx.bfs_successors(graph, args):
            for succ in successors:
                if succ["type"] == "ID":
                    yield succ


def add_assign_arg_param(graph):
    call_nodes = find_index_by_name(graph, "FuncCall") or []
    if call_nodes is None:
        return graph
    for call in call_nodes:
        func_call_node = graph[call]
        scope = func_call_node["scope"]

        func = next(
            (
                node[1]
                for node in graph.out_edges(call)
                if graph[node[1]]["type"] == "ID"
            ),
            None,
        )
        func_decl = next(find_index_by_name(graph, graph[func]["name"], "Global"), None)
        param_nodes = get_func_params(graph, func_decl)

        args_node = next(
            (
                node[1]
                for node in graph.out_edges(call)
                if graph[node[1]]["name"] == "ExprList"
            ),
            None,
        )
        args_nodes = get_func_args(graph, args_node)

        body_node = next(
            (
                node
                for node in find_index_by_name(graph, "Body")
                if graph[node]["scope"] == scope
            ),
            None,
        )
        for param, arg in zip(param_nodes, args_nodes):
            assign_node = add_node(graph, "Assign", scope)
            add_edge(graph, body_node, assign_node, "unidir")

            param_node = add_node(graph, param["name"], scope, "ID")
            add_edge(graph, param_node, assign_node, "unidir")

            arg_node = add_node(graph, arg["name"], scope, "ID")
            add_edge(graph, assign_node, arg_node, "unidir")
            arg["name"] = param["name"]
    return graph


def filter_graph(graph, ansatz):
    filtered_graph = graph.copy()
    ansatz_index = next(find_index_by_name(graph, ansatz), None)
    if ansatz_index is None:
        return filtered_graph
    ansatz_children = list(graph.successor_indices(ansatz_index))
    ansatz_decls = [
        index
        for index in list(graph.successor_indices(ansatz_children[0]))
        if graph[index]["name"] == "Decl"
    ]
    exclude_nodes = [
        find_index_by_name(graph, node)
        for node in ["FileAST", "ExprList", "Params", ansatz]
    ]
    exclude_nodes = [x for xs in exclude_nodes for x in xs]  # flatten
    filtered_graph.remove_nodes_from(exclude_nodes + ansatz_children + ansatz_decls)

    return filtered_graph


def make_hoas(graph):
    for u, v in ((u, v) for u in graph.node_indices() for v in graph.node_indices()):
        if (
            u != v
            and graph[u]["type"] == "ID"
            and graph[v]["type"] == "ID"
            and graph[u]["name"] == graph[v]["name"]
        ):
            if u > v:
                label = ""
            else:
                label = "invisible"
            add_edge(graph, u, v, label, origin="HOAS")
    return graph


def symbolic_globals(ast, graph, operations):
    root_id = next(find_index_by_name(ast, "FileAST"), None)
    if root_id is None:
        return None
    file_ast_children = ast.neighbors(root_id)
    decl_nodes = [node for node in file_ast_children if ast[node]["name"] == "Decl"]
    global_vars = [child for decl in decl_nodes for child in ast.neighbors(decl)]
    result = {v: False for v in global_vars}

    for v in global_vars:
        for op in operations:
            for op_node in find_index_by_name(graph, op) or []:
                if rx.has_path(graph, op_node, v):
                    result[v] = True  # Needs to be symbolic
                    break
    return result


def build_hoas(file_path, ansatz, operations, includes=""):
    ast = parse_file(
        file_path,
        use_cpp=True,
        cpp_path="gcc",
        cpp_args=["-E", r"-Iutils/fake_libc_include " + includes],
    )
    visitor = ASTVisitor()

    # P1: Make AST rustworkx graph
    visitor.visit(ast, "Global")
    draw_graph(visitor.graph, file_path, "p1_ast", operations)

    # P2: Separating initialization and declaration
    parsed_graph = parse_decl_and_init(visitor.graph)
    draw_graph(parsed_graph, file_path, "p2_parseDeclNInit", operations)

    # P3: Parsing function calls, adding an assignation
    make_params_name_unique(visitor.graph, ansatz)
    parsed_graph = add_assign_arg_param(visitor.graph)
    draw_graph(parsed_graph, file_path, "p3_parseFuncCall", operations)

    # P4:
    filtered_graph = filter_graph(parsed_graph, ansatz)
    draw_graph(filtered_graph, file_path, "p4_filter", operations)

    # P5
    hoas_graph = make_hoas(filtered_graph)
    draw_graph(hoas_graph, file_path, "p5_hoas", operations)

    return visitor.graph, hoas_graph


def edge_attr(data):
    if data["from"] == "AST":
        style = "solid"
    if data["from"] == "HOAS":
        style = "dotted"
    if data["label"] == "invisible":
        return {"style": style, "label": data["index"], "style": "invis"}
    if data["label"] == "unidir":
        return {"style": style, "label": data["index"], "dir": "forward"}
    return {"style": style, "label": data["index"], "dir": "both"}


def node_attr_factory(operations):
    def node_attr(data):
        if data["name"] in operations:
            color = "gray"
        elif data["scope"] == "Global" and data["type"] == "ID":
            color = "lightblue"
        else:
            color = "pink"
        return {
            "label": data["name"],
            "color": "gray",
            "fillcolor": color,
            "style": "filled",
        }

    return node_attr


def draw_graph(G, file_path, end="_dat", operations=[]):
    node_attr_func = node_attr_factory(operations)
    dot_str = G.to_dot(
        node_attr=node_attr_func,
        edge_attr=edge_attr,
    )
    dot = pydot.graph_from_dot_data(dot_str)[0]
    folder_path = os.path.splitext(file_path)[0]
    os.makedirs(folder_path, exist_ok=True)
    dot.write_png(folder_path + "/" + end + ".png")


def main():
    if len(sys.argv) != 4:
        print(f"Arguments must be: [file_path] [ansatz] [operations]")
    else:
        # file_path = "evaluation/func_call.c"
        file_path = sys.argv[1]
        ansatz = sys.argv[2]
        operations = sys.argv[3]
        parsed_ast, hoas_graph = build_hoas(file_path, ansatz, operations)
        global_vars = symbolic_globals(parsed_ast, hoas_graph, operations)
        print(
            "Symbolic Global Vars: ",
            [
                f"{hoas_graph[var]["name"]}: {value}"
                for var, value in global_vars.items()
            ],
        )


if __name__ == "__main__":
    main()
