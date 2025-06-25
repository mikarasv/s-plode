from pathlib import Path
from typing import Annotated

import rustworkx as rx
import typer

from .custom_types import FuncName, VarAndType
from .main import build_hoas, symbolic_vars

app = typer.Typer()


def print_symbolic_analysis(
    title: str, vars_list: list[VarAndType], graph: rx.PyDiGraph, operations: list[str]
) -> None:
    all_vars = ", ".join(var["var_dict"]["name"] for var in vars_list)
    symbolic = ", ".join(
        var["var_dict"]["name"] for var in symbolic_vars(vars_list, graph, operations)
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
    hoas_graph, _, sym_global_vars, sym_params = build_hoas(
        file_path, ansatz, includes, operations, draw
    )

    if no_operations_provided(operations):
        print("No ansatz nor operations provided. Finished analyzing graph.")
        return

    print_summary(ansatz, operations)
    print_symbolic_analysis("global variables", sym_global_vars, hoas_graph, operations)
    if ansatz is not None:
        print_symbolic_analysis(
            f"{ansatz}'s arguments", sym_params, hoas_graph, operations
        )


if __name__ == "__main__":
    app()
