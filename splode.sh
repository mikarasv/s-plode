#!/bin/bash

# Check if a directory was provided as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <directory>"
  exit 1
fi

# Get the input directory
input_dir="$1"

# Check if the input directory exists
if [ ! -d "$input_dir" ]; then
  echo "Error: $input_dir not found or is not a directory!"
  exit 1
fi

# Loop through all .c files in the directory
for c_file in "$input_dir"/*.c; do
  # Check if there are any .c files
  if [ ! -e "$c_file" ]; then
    echo "No .c files found in $input_dir."
    exit 1
  fi
done

# Compile the C file
docker run --rm -it  -v ./$input_dir:/home/klee/sample -v ./entry.sh:/home/klee/entrypoint.sh --entrypoint /home/klee/entrypoint.sh --ulimit='stack=-1:-1' klee/klee:3.0 

# docker run --rm -it --volume ./$input_dir:/home/klee/sample --ulimit='stack=-1:-1' mi-imagen