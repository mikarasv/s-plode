#!/bin/bash
set -eu

sut_file_location=""
config_file_location=""
keep_splode=false
draw=false

usage() {
    echo "Usage: $0 --file <file> --config <file> [--keep-splode <true|false>] [--draw <true|false>] [--help]"
    echo "Short flags are also supported: -f, -c, -k, -d, -h"
    exit 1
}

while [ $# -gt 0 ]; do
    case "$1" in
        -h|--help)
            usage
            ;;
        -f|--file)
            if [ $# -lt 2 ]; then usage; fi
            shift
            sut_file_location="$1"
            ;;
        -c|--config)
            if [ $# -lt 2 ]; then usage; fi
            shift
            config_file_location="$1"
            ;;
        -k|--keep-splode)
            if [ $# -lt 2 ]; then usage; fi
            shift
            if [[ "$1" == "true" || "$1" == "false" ]]; then
                keep_splode="$1"
            else
                echo "ENTRYPOINT ERROR: Invalid value for --keep-splode. Use 'true' or 'false'."
                exit 1
            fi
            ;;
        -d|--draw)
            if [ $# -lt 2 ]; then usage; fi
            shift
            if [[ "$1" == "true" || "$1" == "false" ]]; then
                draw="$1"
            else
                echo "ENTRYPOINT ERROR: Invalid value for --draw. Use 'true' or 'false'."
                exit 1
            fi
            ;;
        *)
            echo "ENTRYPOINT ERROR: Unknown argument: $1"
            usage
            ;;
    esac
    shift
done

if [ -z "$sut_file_location" ]; then
  echo "ENTRYPOINT ERROR: --file not provided."
  exit 1
fi

if [ -z "$config_file_location" ]; then
  echo "ENTRYPOINT ERROR: --config not provided."
  exit 1
fi

docker run --rm -it --volume ./:/home/klee/sample --ulimit='stack=-1:-1' splode-image \
    "$sut_file_location" "$config_file_location" "$keep_splode" "$draw"

