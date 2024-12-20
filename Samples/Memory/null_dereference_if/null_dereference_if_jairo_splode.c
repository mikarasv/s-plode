// This file was generated from /home/klee/sample/Samples/Memory/null_dereference_if/null_dereference_if.c and config file /home/klee/sample/Samples/Memory/null_dereference_if/null_dereference_if.yml

#include <stdlib.h>
#include <stdio.h>

#include <klee/klee.h>

// Ansatz file


int jairo(int input)
{
    int *ptr = NULL;

    if (input == 1)
    {
        ptr = malloc(sizeof(int));
    }

    if (ptr == NULL)
    {
        printf("Pointer value (NULL): %d\n", *ptr); // Null dereference
    }
    else
    {
        *ptr = 10;
        printf("Assigned value: %d\n", *ptr);
        free(ptr);
    }

    return 0;
}

// End ansatz file



int main() {

  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  jairo(i);

  return 0;
}
