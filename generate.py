import os
import re
import sys

import yaml
from jinja2 import Environment, FileSystemLoader


def extract_fun_recursive(c_file, ret_type, func_name, extracted_funcs=None):
    # Avoid infinite recursion
    if extracted_funcs is None:
        extracted_funcs = set()

    if func_name in extracted_funcs:
        return ""  # Avoids reextraction of functions

    extracted_funcs.add(func_name)

    with open(c_file, "r") as f:
        file_content = f.read()

    start_pattern = (
        rf"\b{ret_type}\b(?:\s+\w+)?\s+\b{func_name}\b\s*\([^)]*\)\s*\{{(.*?)\}}"
    )

    # found function declaration
    start_match = re.search(start_pattern, file_content, re.DOTALL)
    if start_match:
        start_index = start_match.start()
        bracket_count = 1
        end_index = start_match.end()

        in_switch = False
        while end_index < len(file_content) and bracket_count > 0:
            char = file_content[end_index]

            if file_content[end_index : end_index + 6] == "switch":
                in_switch = True

            if char == "{":
                bracket_count += 1
            elif char == "}":
                bracket_count -= 1
                if in_switch and bracket_count == 1:
                    in_switch = False
            elif in_switch and file_content[end_index : end_index + 4] in [
                "case",
                "default",
            ]:
                end_index += 4
                continue
            elif in_switch and file_content[end_index : end_index + 6] == "return":
                in_switch = False

            end_index += 1

        if bracket_count == 0:
            function_code = file_content[start_index:end_index]

            # Detect other function calls
            call_pattern = r"\b(\w+)\s*\([^)]*\);"  # Captures called name function
            calls = re.findall(call_pattern, function_code)

            for call in calls:
                if call not in extracted_funcs:
                    # Attempt to extract the function
                    nested_func_code = extract_fun_recursive(
                        c_file, ".*", call, extracted_funcs
                    )
                    function_code += "\n" + nested_func_code

            return function_code

    return ""


def is_yml(file_name):
    _, extension = os.path.splitext(file_name)
    return extension in [".yml", ".yaml"]


if len(sys.argv) != 3:
    # Should never happen
    sys.exit(1)

yml_file = sys.argv[1]
splode_file_location = sys.argv[2]

if not os.path.exists(splode_file_location):
    print(f"Splode file ({splode_file_location}) does not exist")
    sys.exit(1)
if not os.path.exists(yml_file):
    print("Input file does not exist")
    sys.exit(1)
if not is_yml(yml_file):
    print("Input file must be .yaml or .yml file")
    sys.exit(1)

with open(yml_file) as yml_file:
    config = yaml.safe_load(yml_file)

ansatz_name = config["ansatz-call"]["name"]
ansatz_type = config["ansatz-call"]["type"]
extracted_ansatz = extract_fun_recursive(splode_file_location, ansatz_type, ansatz_name)

if extracted_ansatz is None:
    raise ValueError(f"Ansatz {ansatz_name} not found in {splode_file_location}")

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


output_code = template.render(
    prologue=config["prologue"],
    ansatz=config["ansatz-call"],
    function=extracted_ansatz,
    symbolic_globals=config["symbolic-globals"],
    main_set_up=config["main-set-up"],
    main_tear_down=config["main-tear-down"],
)

with open(
    splode_file_location[:-2] + "_" + ansatz_name + "_splode.c",
    "w",
) as f:
    f.write(output_code)
