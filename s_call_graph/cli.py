from pathlib import Path
from typing import List, Optional

import typer
from typing_extensions import Annotated

from .custom_types import SymbolicGlobal
from .main import build_hoas, symbolic_globals

app = typer.Typer()


@app.command()
def main(
    file_path: Annotated[Path, typer.Argument()],
    operations: Annotated[List[str], typer.Option("--operation", "-o")],
    draw: Annotated[bool, typer.Option("--draw", "-d")] = True,
    ansatz: Annotated[Optional[str], typer.Option("--ansatz", "-a")] = None,
    includes: Annotated[str, typer.Option("--includes", "-i")] = "",
) -> List[SymbolicGlobal]:
    if ansatz == "":
        ansatz = None
    hoas_graph, _, global_vars = build_hoas(
        file_path, ansatz, includes, operations, draw
    )
    global_vars_value = symbolic_globals(global_vars, hoas_graph, operations)
    print("Global variables:")
    for g_var in global_vars_value:
        print(f"  {g_var.global_var.g_var.name}: {g_var.is_symbolic}")
    return global_vars_value


if __name__ == "__main__":
    app()
