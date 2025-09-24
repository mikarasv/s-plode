from pathlib import Path

import rustworkx as rx
import typer
from pycparser import parse_file
from typing_extensions import Annotated

from .custom_types import FuncName, VarAndType
from .main import build_s_graph, symbolic_vars
from .params_n_globals import ParamsNGlobalsParser

app = typer.Typer()


def print_symbolic_analysis(
    title: str, vars_list: list[VarAndType], graph: rx.PyDiGraph, operations: list[str]
) -> None:
    all_vars = ", ".join(var["var_dict"]["name"] for var in vars_list)
    symbolic = ", ".join(
        f"{var["var_dict"]["name"]} ({var["var_type"]["name"]})"
        for var in symbolic_vars(vars_list, graph, operations)
    )
    print(f"From the following {title}: {all_vars}")
    print(f"These are considered symbolic: {symbolic}")


def print_summary(ansatz: FuncName | None, operations: list[str]) -> None:
    if ansatz is not None:
        print(f"Ansatz: {ansatz}")
    print(f"Operations: {', '.join(operations)}")


def no_operations_provided(operations: list[str]) -> bool:
    return not operations


@app.command()
def main(
    file_path: Annotated[Path, typer.Argument()],
    operations: Annotated[list[str], typer.Option("--operation", "-o")] = [],
    draw: Annotated[bool, typer.Option("--draw", "-d")] = False,
    ansatz: Annotated[str | None, typer.Option("--ansatz", "-a")] = None,
    includes: Annotated[list[str], typer.Option("--includes", "-i")] = [],
) -> None:
    ast = parse_file(
        file_path,
        use_cpp=True,
        cpp_path="clang",
        cpp_args=["-E", "-I."],
    )
    ast_graph, s_graph, _ = build_s_graph(
        ast, file_path, ansatz, includes, operations, draw
    )

    # Get global variables and ansatz parameters
    source_getter = ParamsNGlobalsParser(ast_graph, ansatz)
    source_getter.get_globals_n_params()

    if no_operations_provided(operations):
        print("No ansatz nor operations provided. Finished analyzing graph.")
        return

    print_summary(ansatz, operations)
    print_symbolic_analysis(
        "global variables", source_getter.global_vars, s_graph.graph, operations
    )
    if ansatz is not None:
        print_symbolic_analysis(
            f"{ansatz}'s arguments",
            source_getter.ansatz_params,
            s_graph.graph,
            operations,
        )


if __name__ == "__main__":
    app()
