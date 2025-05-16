from pathlib import Path
from typing import Annotated

import typer

from .custom_types import SymbolicGlobal
from .main import build_hoas, symbolic_globals

app = typer.Typer()


@app.command()
def main(
    file_path: Annotated[Path, typer.Argument()],
    operations: Annotated[list[str], typer.Option("--operation", "-o")],
    draw: Annotated[bool, typer.Option("--draw", "-d")] = False,
    ansatz: Annotated[str | None, typer.Option("--ansatz", "-a")] = None,
    includes: Annotated[str, typer.Option("--includes", "-i")] = "",
) -> list[SymbolicGlobal]:
    if ansatz == "":
        ansatz = None
    hoas_graph, _, global_vars = build_hoas(
        file_path, ansatz, includes, operations, draw
    )
    global_vars_value = symbolic_globals(global_vars, hoas_graph, operations)
    print("Global variables:")
    for g_var in global_vars_value:
        print(f"   {g_var.global_var["g_var"]["name"]}: {g_var.is_symbolic}")
    return global_vars_value


if __name__ == "__main__":
    app()
