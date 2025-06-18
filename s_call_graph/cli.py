from pathlib import Path
from typing import Annotated

import typer

from .custom_types import SymbolicVar
from .main import build_hoas, symbolic_vars

app = typer.Typer()


@app.command()
def main(
    file_path: Annotated[Path, typer.Argument()],
    operations: Annotated[list[str], typer.Option("--operation", "-o")] = [],
    draw: Annotated[bool, typer.Option("--draw", "-d")] = False,
    ansatz: Annotated[str | None, typer.Option("--ansatz", "-a")] = None,
    includes: Annotated[list[str], typer.Option("--includes", "-i")] = [],
) -> list[SymbolicVar] | None:
    hoas_graph, _, pos_sym_vars = build_hoas(
        file_path, ansatz, includes, operations, draw
    )
    if ansatz is not None and operations != []:
        vars_value = symbolic_vars(pos_sym_vars, hoas_graph, operations)
        print(
            f"Ansatz: {ansatz}\nOperations: {', '.join(operations)}\n"
            "The following variables are considered symbolic:"
        )
        for var in vars_value:
            print(f"   - {var.var_n_type["var_dict"]["name"]}: {var.is_symbolic}")
        return vars_value
    else:
        print("No ansatz or operations provided. Finished analyzing graph.")
    return None


if __name__ == "__main__":
    app()
