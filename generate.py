import os
import sys

import yamale
import yaml
from jinja2 import Environment, FileSystemLoader
from pycparser import parse_file

from s_call_graph.main import build_s_graph, symbolic_vars
from s_call_graph.params_n_globals import ParamsNGlobalsParser


def is_yml(file_name):
    _, extension = os.path.splitext(file_name)
    return extension in [".yml", ".yaml"]


if len(sys.argv) != 4 and len(sys.argv) != 3:
    # Should never happen
    print("Usage: python3 generate.py <splode_file_location> <yml_file> [<draw>]")
    sys.exit(1)


splode_file_location = sys.argv[1]
yml_file = sys.argv[2]
if len(sys.argv) == 4:
    if sys.argv[3].lower() == "true":
        draw = True
    else:
        draw = False
else:
    draw = False

if not os.path.exists(splode_file_location):
    print(f"Splode file ({splode_file_location}) does not exist")
    sys.exit(1)
if not os.path.exists(yml_file):
    print("Input file does not exist")
    sys.exit(1)
if not is_yml(yml_file):
    print("Input file must be .yaml or .yml file")
    sys.exit(1)

with open(yml_file, "r") as file:
    config = yamale.make_data(file.name)

schema = yamale.make_schema("schema.yaml")

try:
    yamale.validate(schema, config)
except ValueError as e:
    print("Validation failed!\n%s" % str(e))
    exit(1)

with open(yml_file) as file:
    config = yaml.safe_load(file)

env = Environment(loader=FileSystemLoader("."))

template = env.get_template("template.c.jinja2")


if config.get("prologue") is None:
    config["prologue"] = ""

if config.get("symbolic-globals") is None:
    config["symbolic-globals"] = False

if config.get("main-set-up") is None:
    config["main-set-up"] = False

if config.get("main-tear-down") is None:
    config["main-tear-down"] = False

if config.get("operations") is None:
    config["operations"] = []
if config.get("include-funcs") is None:
    config["include-funcs"] = []

ast = parse_file(
    splode_file_location,
    use_cpp=True,
    cpp_path="clang",
    cpp_args=["-E", "-I."],
)

ast_graph, s_graph, reduced_file = build_s_graph(
    ast,
    splode_file_location,
    config["ansatz-call"]["name"],
    config["include-funcs"],
    config["operations"],
    draw,
)

source_getter = ParamsNGlobalsParser(ast_graph, config["ansatz-call"]["name"])
source_getter.get_globals_n_params()


symbolic_globals = [
    {"name": var["var_dict"]["name"], "type": var["var_type"]["name"]}
    for var in symbolic_vars(
        source_getter.global_vars, s_graph.graph, config["operations"]
    )
]

if config["symbolic-globals"]:
    symbolic_globals.extend([var for var in config["symbolic-globals"]])

sym_params = [
    {"name": var["var_dict"]["name"], "type": var["var_type"]["name"]}
    for var in symbolic_vars(
        source_getter.ansatz_params, s_graph.graph, config["operations"]
    )
]

if config["ansatz-call"].get("arguments") is not None:
    sym_params.extend(
        [
            {"name": arg["name"], "type": arg["type"]}
            for arg in config["ansatz-call"]["arguments"]
            if arg.get("symbolic")
        ]
    )

output_code = template.render(
    file_name=splode_file_location.split("sample/")[-1],
    config_file_name=yml_file.split("sample/")[-1],
    prologue=config["prologue"],
    ansatz=config["ansatz-call"],
    symbolic_params=sym_params,
    file=reduced_file,
    symbolic_globals=symbolic_globals,
    main_set_up=config["main-set-up"],
    main_tear_down=config["main-tear-down"],
)

print(output_code)
