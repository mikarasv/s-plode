import os

import pydot
import rustworkx as rx
from pycparser import c_ast, parse_file


class ASTVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.graph = rx.PyDiGraph()

    def visit(self, node, scope):
        method_name = f"visit_{node.__class__.__name__.lower()}"
        method = getattr(self, method_name, self.default_visit)
        return method(node, scope)

    def default_visit(self, node, scope):
        node_id = self.graph.add_node(
            {"type": "not", "name": node.__class__.__name__, "scope": scope}
        )
        return self._visit_children(node, node_id, scope)

    # ---- Specific Visitors ---- #
    def visit_id(self, node, scope):
        return self.graph.add_node({"type": "ID", "name": node.name, "scope": scope})

    def visit_typedecl(self, node, scope):
        node_id = self.graph.add_node(
            {"type": "ID", "name": node.declname, "scope": scope}
        )
        return self._visit_children(node, node_id, scope)

    def visit_constant(self, node, scope):
        return self.graph.add_node({"type": "not", "name": node.value, "scope": scope})

    def visit_unaryop(self, node, scope):
        node_id = self.graph.add_node({"type": "not", "name": node.op, "scope": scope})
        return self._visit_children(node, node_id, scope)

    def visit_binaryop(self, node, scope):
        node_id = self.graph.add_node({"type": "not", "name": node.op, "scope": scope})
        child_l = self.visit(node.left, scope)
        child_r = self.visit(node.right, scope)
        self.graph.add_edge(
            node_id, child_l, {"from": "AST", "label": "", "index": "0"}
        )
        self.graph.add_edge(
            node_id, child_r, {"from": "AST", "label": "", "index": "1"}
        )

        self.graph.add_edge(
            child_l, node_id, {"from": "AST", "label": "invisible", "index": ""}
        )
        self.graph.add_edge(
            child_r, node_id, {"from": "AST", "label": "invisible", "index": ""}
        )

        return node_id

    def visit_identifiertype(self, node, scope):
        return self.graph.add_node(
            {"type": "not", "name": " ".join(node.names), "scope": scope}
        )

    def visit_compound(self, node, scope):
        node_id = self.graph.add_node({"type": "not", "name": "Body", "scope": scope})
        return self._visit_children(node, node_id, scope)

    def visit_funcdef(self, node, scope):
        node_id = self.graph.add_node(
            {"type": "ID", "name": node.decl.name, "scope": scope}
        )
        self.graph.add_child(  # Add function type
            node_id,
            {
                "type": "not",
                "name": " ".join(node.decl.type.type.type.names),
                "scope": node.decl.name,
            },
            {"from": "AST", "label": "unidir", "index": "0"},
        )

        # Add function params
        if node.decl.type.args is not None:
            params_root = self.graph.add_node(
                {"type": "not", "name": "Params", "scope": node.decl.name}
            )
            self.graph.add_edge(
                node_id, params_root, {"from": "AST", "label": "unidir", "index": "1"}
            )
            for index, param in enumerate(node.decl.type.args.params):
                child_id = self.visit(param, scope=node.decl.name)
                self.graph.add_edge(
                    params_root,
                    child_id,
                    {"from": "AST", "label": "", "index": str(index)},
                )

        child_id = self.visit(node.body, node.decl.name)
        self.graph.add_edge(
            node_id, child_id, {"from": "AST", "label": "unidir", "index": "2"}
        )

        return node_id

    def visit_decl(self, node, scope):
        node_id = self.graph.add_node({"type": "not", "name": "Decl", "scope": scope})
        if len(node.children()) == 1:
            child = self.visit(node.children()[0][1], scope)
            self.graph.add_edge(
                node_id, child, {"from": "AST", "label": "", "index": ""}
            )
            self.graph.add_edge(
                child, node_id, {"from": "AST", "label": "invisible", "index": ""}
            )
        else:
            child_l = self.visit(node.children()[0][1], scope)
            child_r = self.visit(node.children()[1][1], scope)
            self.graph.add_edge(
                child_l, node_id, {"from": "AST", "label": "unidir", "index": ""}
            )
            self.graph.add_edge(
                node_id, child_r, {"from": "AST", "label": "unidir", "index": ""}
            )
        return node_id

    def visit_assignment(self, node, scope):
        node_id = self.graph.add_node({"type": "not", "name": "Assign", "scope": scope})
        child_l = self.visit(node.children()[0][1], scope)
        child_r = self.visit(node.children()[1][1], scope)
        self.graph.add_edge(
            child_l, node_id, {"from": "AST", "label": "unidir", "index": ""}
        )
        self.graph.add_edge(
            node_id, child_r, {"from": "AST", "label": "unidir", "index": ""}
        )
        return node_id

    # ---- Helper Function ---- #
    def _visit_children(self, node, node_id, scope, double=True):
        for index, (_, child) in enumerate(node.children()):
            child_id = self.visit(child, scope)
            self.graph.add_edge(
                node_id, child_id, {"from": "AST", "label": "", "index": str(index)}
            )
            if double:
                self.graph.add_edge(
                    child_id,
                    node_id,
                    {"from": "AST", "label": "invisible", "index": ""},
                )
        return node_id


def add_hoas_edges(graph):
    for u, v in ((u, v) for u in graph.node_indices() for v in graph.node_indices()):
        if (
            u > v
            and graph[u].get("type") == "ID"
            and graph[v].get("type") == "ID"
            and graph[u].get("name") == graph[v].get("name")
            and (
                graph[u].get("scope") == graph[v].get("scope")
                or graph[u].get("scope") == "Global"
                or graph[v].get("scope") == "Global"
            )
        ):
            graph.add_edge(u, v, {"from": "HOAS", "label": "", "index": ""})
    return graph


def build_hoas(file_path):
    ast = parse_file(
        file_path,
        use_cpp=True,
        cpp_path="gcc",
        cpp_args=["-E", r"-Iutils/fake_libc_include"],
    )
    ast.show(showcoord=True)
    visitor = ASTVisitor()
    visitor.visit(ast, "Global")
    hoas_graph = add_hoas_edges(visitor.graph)
    return hoas_graph


def find_node_index_in_scope(graph, node_name, scope):
    result = []
    for index, data in enumerate(graph.nodes()):
        if data == node_name and (scope is None or graph[index].get("scope") == scope):
            result.append(index)
    if len(result) == 0:
        result = None
    return result


def filter_graph(G, ansatz):
    filtered_graph = G.copy()
    ansatz_index = find_node_index_in_scope(G, ansatz)[0]
    ansatz_children = list(G.successor_indices(ansatz_index))
    exclude_nodes = [
        find_node_index_in_scope(G, node) for node in ["FileAST", "Decl", ansatz]
    ]
    exclude_nodes = [x for xs in exclude_nodes for x in xs]  # flatten
    filtered_graph.remove_nodes_from(exclude_nodes + ansatz_children)

    return filtered_graph


# TODO: Determine if its possible to look a path
# from sensitive operation to global variables without using undirected graph
def symbolic_globals(G, operations):
    root_id = find_node_index_in_scope(G, "FileAST")[0]
    file_ast_children = G.neighbors(root_id)
    decl_nodes = [node for node in file_ast_children if G[node] == "Decl"]
    global_vars = [child for decl in decl_nodes for child in G.neighbors(decl)]
    print(f"{[G[a] for a in global_vars]}")
    result = {v: False for v in global_vars}

    filtered_graph = filter_graph(G, "fun")
    for v in global_vars:
        for op in operations:
            for op_node in find_node_index_in_scope(filtered_graph, op):
                print("asd", op_node)
                if rx.has_path(filtered_graph, op_node, v, as_undirected=True):
                    result[v] = True  # Needs to be symbolic
                    print(f"Global variable {G[v]}, ({v}) is symbolic")
                    break
    return result


def edge_attr(data):
    if data["from"] == "AST":
        style = "solid"
    if data["from"] == "HOAS":
        style = "dotted"
    if data["label"] != "unidir" and data["label"] != "invisible":
        return {"style": style, "label": data["index"], "dir": "both"}
    if data["label"] == "invisible":
        return {"style": "invis", "label": data["index"]}
    return {"style": style, "label": data["index"]}


def draw_graph(G, file_path):
    dot_str = G.to_dot(
        node_attr=lambda node: dict(
            label=node.get("name"),
            color="gray",
            fillcolor="pink",
            style="filled",
        ),
        edge_attr=edge_attr,
    )
    dot = pydot.graph_from_dot_data(dot_str)[0]
    dot.write_png(os.path.splitext(file_path)[0] + "_dag.png")


file_path = "evaluation/func_call.c"
hoas_graph = build_hoas(file_path)
draw_graph(hoas_graph, file_path)
