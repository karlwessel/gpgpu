#!/bin/bash

# directory where this script is located
# taken from https://stackoverflow.com/questions/59895/how-do-i-get-the-directory-where-a-bash-script-is-located-from-within-the-script
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

LD_LIBRARY_PATH=/opt/intel/oneapi/2024.0/lib/ $SCRIPT_DIR/saxpy $1
