import os
import sys

import yamale
import yaml
from jinja2 import Environment, FileSystemLoader

from cg_generate import build_cg, extract_ansatz_sg


def is_yml(file_name):
    _, extension = os.path.splitext(file_name)
    return extension in [".yml", ".yaml"]


if len(sys.argv) != 4:
    # Should never happen
    sys.exit(1)

splode_file_location = sys.argv[1]
yml_file = sys.argv[2]
includes = sys.argv[3]

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

schema = yamale.make_schema("./schema.yaml")

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
    config["prologue"] = False

if config.get("symbolic-globals") is None:
    config["symbolic-globals"] = False

if config.get("main-set-up") is None:
    config["main-set-up"] = False

if config.get("main-tear-down") is None:
    config["main-tear-down"] = False


cg = build_cg(splode_file_location, includes)

ansatz_sg = extract_ansatz_sg(cg, config["ansatz-call"]["name"])
file_content = "\n".join(node[1]["content"] for node in ansatz_sg.nodes(data=True))

output_code = template.render(
    file_name=splode_file_location,
    config_file_name=yml_file,
    prologue=config["prologue"],
    ansatz=config["ansatz-call"],
    file=file_content,
    symbolic_globals=config["symbolic-globals"],
    main_set_up=config["main-set-up"],
    main_tear_down=config["main-tear-down"],
)

print(output_code)
