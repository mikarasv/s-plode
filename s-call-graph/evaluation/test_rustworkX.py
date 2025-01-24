import time

import matplotlib.pyplot as plt
import rustworkx as rx
from pycparser import c_ast, parse_file
from rustworkx.visualization import mpl_draw


class CallGraphVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.graph = rx.PyDiGraph()
        self.node_indices = {}
        self.current_function = None

    def visit_FuncDef(self, node):
        func_name = node.decl.name

        if func_name not in self.node_indices:
            self.node_indices[func_name] = self.graph.add_node(func_name)

        self.current_function = func_name

        self.visit(node.body)
        self.current_function = None

    def visit_FuncCall(self, node):
        if isinstance(node.name, c_ast.ID):
            called_function = node.name.name

            if called_function not in self.node_indices:
                self.node_indices[called_function] = self.graph.add_node(
                    called_function
                )

            if self.current_function:
                self.graph.add_edge(
                    self.node_indices[self.current_function],
                    self.node_indices[called_function],
                    0,
                )

        self.generic_visit(node)


def build_cg(file_path):
    ast = parse_file(file_path)

    visitor = CallGraphVisitor()
    visitor.visit(ast)

    return visitor.graph


file_path = "examplePP.c"

start_time = time.time()

for i in range(10**4):
    call_graph = build_cg(file_path)

end_time = time.time()
execution_time = end_time - start_time
print(f"Execution time: {execution_time:.6f} seconds")

print("Functions (nodes):", call_graph.nodes())
print("Calls (edges):", call_graph.edges())

plt.figure(figsize=(8, 6))
mpl_draw(call_graph, with_labels=True, labels=lambda x: x)
plt.title("Call Graph")
plt.show()
