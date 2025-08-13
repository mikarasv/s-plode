import cProfile
import io
import pstats
from pstats import SortKey

from pycparser import parse_file

from .ast_visitor import ASTVisitor
from .neo4j import GraphN4j
from .networkX import GraphNx
from .rustworkX import GraphRx

# file_path = "s_call_graph/evaluation/uefi_smm_callout.c"
file_path = "s_call_graph/evaluation/hello.c"

ast = parse_file(
    file_path,
    use_cpp=True,
    cpp_path="clang",
    cpp_args=["-E", "-I."],
)
pr = cProfile.Profile()
sortby = SortKey.CUMULATIVE

# graphRx = GraphRx()
# visitorRx = ASTVisitor(graphRx)

# pr.enable()
# visitorRx.visit(ast, "Global")
# pr.disable()
# s = io.StringIO()
# ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
# ps.print_stats()
# print("RustworkX AST Visitor Profiling:")
# print(s.getvalue())

# graphNx = GraphNx()
# visitorNx = ASTVisitor(graphNx)
# pr.enable()
# visitorNx.visit(ast, "Global")
# pr.disable()
# s = io.StringIO()
# ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
# ps.print_stats()
# print("NetworkX AST Visitor Profiling:")
# print(s.getvalue())


graphNeo4j = GraphN4j()
graphNeo4j.delete_all()  # Clear the database before starting
visitorNeo4j = ASTVisitor(graphNeo4j)
pr.enable()

visitorNeo4j.visit(ast, "Global")

pr.disable()
s = io.StringIO()
ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
ps.print_stats()
print("Neo4j AST Visitor Profiling:")
print(s.getvalue())
