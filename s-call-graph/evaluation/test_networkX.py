import time

import matplotlib.pyplot as plt
import networkx as nx
from pycparser import c_ast, parse_file


class CallGraphVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.graph = nx.DiGraph()
        self.current_function = None

    def visit_FuncDef(self, node):
        func_name = node.decl.name
        self.graph.add_node(func_name)
        self.current_function = func_name

        self.visit(node.body)
        self.current_function = None

    def visit_FuncCall(self, node):
        if isinstance(node.name, c_ast.ID):
            called_function = node.name.name

            if self.current_function:
                self.graph.add_node(called_function)
                self.graph.add_edge(self.current_function, called_function)

        self.generic_visit(node)


def function_calls_function(G, f1, f2):
    return nx.has_path(G, f1, f2)


def extract_ansatz(G, f):
    ansatz_edges = list(nx.dfs_edges(G, source=f))
    return G.edge_subgraph(ansatz_edges)


def build_cg(file_path):
    ast = parse_file(file_path)

    visitor = CallGraphVisitor()
    visitor.visit(ast)

    return visitor.graph


file_path = "examplePP.c"

# Performance
# start_time = time.time()
# for i in range(10**4):
#   call_graph = build_cg(file_path)
# end_time = time.time()
# execution_time = end_time - start_time
# print(f"Execution time: {execution_time:.6f} seconds")

call_graph = build_cg(file_path)


ansatz = extract_ansatz(call_graph, "funcB")
print(call_graph.nodes)

print("funcB calls print: ", function_calls_function(call_graph, "funcB", "printf"))
print("funcE calls funcC: ", function_calls_function(call_graph, "funcE", "funcC"))

print("Functions (nodes):", ansatz.nodes)
print("Calls (edges):", ansatz.edges)


plt.figure(figsize=(8, 6))
nx.draw_networkx(
    ansatz,
    with_labels=True,
    node_color="lightblue",
    edge_color="gray",
    font_size=10,
    font_weight="bold",
    pos=nx.spring_layout(ansatz, seed=7),
)
plt.title("Call Graph")
plt.show()
