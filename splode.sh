#!/bin/bash
set -eu

# FLAGS
HELP_FLAG="-h"
SUT_FILE_FLAG="--source-file"
CONFIG_FILE_FLAG="--rule-file"

while [ $# -gt 0 ]; do
    case "$1" in
        $HELP_FLAG)
          echo "Usage: $0 [--source-file <file>] [--rule-file <file>]"
          exit 0
          ;;
        $SUT_FILE_FLAG)
            shift
            sut_file_location="$1"
            ;;
        $CONFIG_FILE_FLAG)
            shift
            config_file_location="$1"
            ;;
        *)
            echo "ENTRYPOINT ERROR: Unknown argument: $1"
            exit 1
            ;;
    esac
    shift
done

if [ -z "$sut_file_location" ]; then
  echo "SINTAX ERROR: ${sut_file_location} not found."
  exit 1
fi

if [ -z "$config_file_location" ]; then
  echo "SINTAX ERROR: ${config_file_location} not found."
  exit 1
fi

sut_directory=$(dirname $sut_file_location)
docker run --rm -it --volume ./$sut_directory:/home/klee/sample --ulimit='stack=-1:-1' splode-image $sut_file_location $config_file_location