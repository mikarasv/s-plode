#!/bin/bash
set -eu

# Buscar el archivo que termine en splode.c
archivo=$(find /home/klee/sample/ -type f -name "*splode.c")

if [ -n "$archivo" ]; then
    clang -I klee_src/ -debug-mode -emit-llvm -c -g -Wno-macro-redefined -fsanitize=signed-integer-overflow -ferror-limit=1000 "$archivo" -o /home/klee/sample/code.bc
    klee /home/klee/sample/code.bc
    if [ -n "$(find /home/klee/sample/klee-last/ -type f -name "*.err")" ]; then
        echo "SPLODED!!"
        cat /home/klee/sample/klee-last/*.err
    else 
        echo "NO SPLODE"
    fi

else
    echo "No se encontró ningún archivo terminado en splode.c"
fi
