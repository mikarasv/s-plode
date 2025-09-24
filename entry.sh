#!/bin/bash
set -eu

sut_file_location="$1"
sut_directory=$(dirname $sut_file_location)

config_file_location="$2"

keep_splode="$3"
draw="$4"
generate=$(find /home -type f -path "/home/klee/sample/generate.py")

if [ -z "$generate" ]; then
    echo "ENTRYPOINT ERROR: generate.py not found"
    exit 1
fi

# Remove directory path from sut_file_location
sut_file_name="${sut_file_location##*/}"
config_file_name="${config_file_location##*/}"

# execute generate.py with config file and sut_file_location as arguments
splode_content=$(python3 "$generate" "/home/klee/sample/${sut_directory}/${sut_file_name}" "/home/klee/sample/${sut_directory}/${config_file_name}" "$draw")

sut_name=$(python3 -c "import yaml; print(yaml.safe_load(open('/home/klee/sample/${sut_directory}/${config_file_name}'))['ansatz-call']['name'])")

BOLD='\033[1m'
GREEN='\033[0;32m'
UNDERLINE='\033[4m'
RED='\033[0;31m'
NC='\033[0m'

# Remove file extension from sut_file_name
sut_file_name="${sut_file_name%.c}"

if [[ "$keep_splode" == "true" ]]; then
    splode_file="/home/klee/sample/${sut_directory}/${sut_file_name}_${sut_name}_splode.c"
    echo "$splode_content" > "$splode_file"
    clang -I klee_src/ -emit-llvm -c -g -Wno-macro-redefined -fno-sanitize=all -ferror-limit=1000 "$splode_file" -o /home/klee/sample/${sut_directory}/code.bc
else
    temp_file=$(mktemp "/home/klee/sample/${sut_directory}/${sut_file_name}_${sut_name}_splode.XXXXXX.c")
    echo "$splode_content" > "$temp_file"
    clang -I klee_src/ -emit-llvm -c -g -Wno-macro-redefined -fno-sanitize=all -ferror-limit=1000 ${temp_file} -o /home/klee/sample/${sut_directory}/code.bc
fi


klee /home/klee/sample/${sut_directory}/code.bc
if [ -n "$(find /home/klee/sample/${sut_directory}/klee-last/ -type f -name "*.err")" ]; then
    echo -e "\n${BOLD}${UNDERLINE}${GREEN}SPLODED!!${NC}\n"
    cat /home/klee/sample/${sut_directory}/klee-last/*.err
else
    echo -e "${BOLD}${RED}No splode."
fi

if [[ "$keep_splode" == "false" ]]; then
    rm "$temp_file"
fi

