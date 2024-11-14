#!/bin/bash
set -eu

sut_file_location="$1"

config_file_location="$2"

generate=$(find /home/ -type f -name "generate.py")

if [ -z "$generate" ]; then
    echo "ENTRYPOINT ERROR: generate.py not found"
    exit 1
fi

# Remove directory path from sut_file_location
sut_file_name="${sut_file_location##*/}"
config_file_name="${config_file_location##*/}"
# execute generate.py with config file and sut_file_location as arguments
python3 "$generate" "/home/klee/sample/${config_file_name}" "/home/klee/sample/${sut_file_name}"

sut_name=$(python3 -c "import yaml; print(yaml.safe_load(open('/home/klee/sample/${config_file_name}'))['ansatz-call']['name'])")

# Remove file extension from sut_file_name
sut_file_name="${sut_file_name%.c}"
splode_file=$(find "." -type f -wholename "*${sut_file_name}_${sut_name}_splode.c")

BOLD='\033[1m'
GREEN='\033[0;32m'
UNDERLINE='\033[4m'
RED='\033[0;31m'
NC='\033[0m'

if [ -n "$splode_file" ]; then
    clang -I klee_src/ -emit-llvm -c -g -Wno-macro-redefined -fsanitize=signed-integer-overflow -ferror-limit=1000 "$splode_file" -o /home/klee/sample/code.bc
    klee /home/klee/sample/code.bc
    if [ -n "$(find /home/klee/sample/klee-last/ -type f -name "*.err")" ]; then
        echo -e "\n${BOLD}${UNDERLINE}${GREEN}SPLODED!!${NC}\n"
        cat /home/klee/sample/klee-last/*.err
    else
        echo -e "${BOLD}${RED}No splode."
    fi

else
    echo "Could not find *_splode.c file"
fi
