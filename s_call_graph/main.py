import sys
from typing import List

from custom_types import SymbolicGlobal
from rustworkX import build_hoas, symbolic_globals


def main() -> List[SymbolicGlobal]:
    if len(sys.argv) == 5 or len(sys.argv) == 4:
        file_path = sys.argv[1]
        operations = sys.argv[2].split(",")
        includes = sys.argv[3]
        ansatz = None
        if len(sys.argv) == 5:
            ansatz = sys.argv[5]
    else:
        raise ValueError(
            "Arguments must be: [file_path] [operations] [includes] [ansatz] or [file_path] [operations] [includes]"
        )

    hoas_graph, _, global_vars = build_hoas(file_path, ansatz, includes, operations)
    global_vars_value = symbolic_globals(global_vars, hoas_graph, operations)
    print("Global variables:")
    for g_var in global_vars_value:
        print(f"  {g_var.global_var.g_var.name}: {g_var.is_symbolic}")
    return global_vars_value


if __name__ == "__main__":
    main()
