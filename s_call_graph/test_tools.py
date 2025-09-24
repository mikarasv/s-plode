import cProfile
import io
import pstats
from pstats import SortKey

from pycparser import parse_file

from .ast_visitor import ASTVisitor
from .genericGraph import GraphType
from .neo4j import GraphN4j
from .networkX import GraphNx
from .pygraph import GraphPg
from .rustworkX import GraphRx

file_path = "s_call_graph/evaluation/uefi_smm_callout.c"
# file_path = "s_call_graph/evaluation/hello.c"

ast = parse_file(
    file_path,
    use_cpp=True,
    cpp_path="clang",
    cpp_args=["-E", "-I."],
)

sortby = SortKey.CUMULATIVE


def profile_visitor(visitor: ASTVisitor[GraphType]) -> str:
    pr = cProfile.Profile()
    pr.enable()
    visitor.visit(ast, "Global")
    pr.disable()
    s = io.StringIO()
    ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
    ps.print_stats()
    return s.getvalue()


graphNeo4j = GraphN4j()
graphNeo4j.delete_all()  # Clear the database before starting
visitorNeo4j = ASTVisitor(graphNeo4j)
print("Neo4j AST Visitor Profiling:")
print(profile_visitor(visitorNeo4j))


graphNx = GraphNx()
visitorNx = ASTVisitor(graphNx)
print(
    "Nx graph has ",
    len(list(graphNx.graph.nodes)),
    " nodes and ",
    len(list(graphNx.graph.edges)),
    " edges.",
)
print("NetworkX AST Visitor Profiling:")
print(profile_visitor(visitorNx))


graphPg = GraphPg()
visitorPg = ASTVisitor(graphPg)
print(
    "Pg graph has ",
    len(list(graphPg.graph.nodes)),
    " nodes and ",
    len(list(graphPg.graph.edges)),
    " edges.",
)
print("PyGraph AST Visitor Profiling:")
print(profile_visitor(visitorPg))

graphRx = GraphRx()
visitorRx = ASTVisitor(graphRx)
print(
    "Rx graph has ",
    len(graphRx.graph.nodes()),
    " nodes and ",
    len(graphRx.graph.edges()),
    " edges.",
)
print("RustworkX AST Visitor Profiling:")
print(profile_visitor(visitorRx))
