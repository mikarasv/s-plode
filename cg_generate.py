import networkx as nx
from pycparser import c_ast, c_generator, parse_file


class CallGraphVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.graph = nx.DiGraph()
        self.current_function = None

    def visit_Decl(self, node):
        if isinstance(node.type, c_ast.TypeDecl) and not self.current_function:
            generator = c_generator.CGenerator()
            decl_code = generator.visit(node)
            self.graph.add_node(node.name, type="global", content=decl_code + ";")
        self.generic_visit(node)

    def visit_FuncDef(self, node):
        func_name = node.decl.name
        generator = c_generator.CGenerator()
        func_code = generator.visit(node)
        if not self.graph.has_node(func_name):
            self.graph.add_node(func_name, content=func_code, type="function")

        self.current_function = func_name
        self.visit(node.body)
        self.current_function = None

    def visit_FuncCall(self, node):
        if isinstance(node.name, c_ast.ID):
            called_function = node.name.name

            if self.current_function:
                if not self.graph.has_node(called_function):
                    self.graph.add_node(called_function, content="", type="function")

                self.graph.add_edge(self.current_function, called_function, type="call")

        if node.args is not None:
            for arg in node.args.exprs:
                self.handle_argument(arg)
        self.generic_visit(node)

    def handle_argument(self, arg):
        if isinstance(arg, c_ast.ID):
            var_name = arg.name
            if (
                self.graph.has_node(var_name)
                and self.graph.nodes[var_name]["type"] == "global"
            ):
                self.graph.add_edge(self.current_function, var_name, type="use-global")

        self.generic_visit(arg)

    def visit_ID(self, node):
        if self.current_function and self.graph.has_node(node.name):
            if self.graph.nodes[node.name]["type"] == "global":
                self.graph.add_edge(self.current_function, node.name, type="use-global")

        self.generic_visit(node)


def build_cg(file_path, includes):
    ast = parse_file(
        file_path,
        use_cpp=True,
        cpp_path="gcc",
        cpp_args=["-E", r"-Iutils/fake_libc_include " + includes],
    )
    visitor = CallGraphVisitor()
    visitor.visit(ast)

    return visitor.graph


def function_calls_function(G, f1, f2):
    return nx.has_path(G, f1, f2)


def extract_ansatz_sg(G, f):
    ansatz_edges = list(nx.dfs_edges(G, source=f))
    return G.edge_subgraph(ansatz_edges)
