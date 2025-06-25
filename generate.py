import os
import sys

import yamale
import yaml
from jinja2 import Environment, FileSystemLoader

from s_call_graph.main import build_hoas, symbolic_vars


def is_yml(file_name):
    _, extension = os.path.splitext(file_name)
    return extension in [".yml", ".yaml"]


if len(sys.argv) != 3:
    # Should never happen
    print("Usage: python3 generate.py <splode_file_location> <yml_file>")
    sys.exit(1)


splode_file_location = sys.argv[1]
yml_file = sys.argv[2]


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

hoas_graph, reduced_file, global_vars, ansatz_params = build_hoas(
    splode_file_location,
    config["ansatz-call"]["name"],
    config["include-funcs"],
    config["operations"],
)

symb_global_vars = symbolic_vars(global_vars, hoas_graph, config["operations"])

symbolic_globals = [
    {"name": var["var_dict"]["name"], "type": var["var_type"]["name"]}
    for var in symb_global_vars
]

if config["symbolic-globals"]:
    symbolic_globals.extend([var for var in config["symbolic-globals"]])

sym_params = [
    {"name": var["var_dict"]["name"], "type": var["var_type"]["name"]}
    for var in symbolic_vars(ansatz_params, hoas_graph, config["operations"])
]

output_code = template.render(
    file_name=splode_file_location.split("sample/")[0],
    config_file_name=yml_file.split("sample/")[0],
    prologue=config["prologue"],
    ansatz=config["ansatz-call"],
    symbolic_params=sym_params,
    file=reduced_file,
    symbolic_globals=symbolic_globals,
    main_set_up=config["main-set-up"],
    main_tear_down=config["main-tear-down"],
)

print(output_code)
