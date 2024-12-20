// This file was generated from /home/klee/sample/Samples/Memory/double_free_if/double_free_if.c and config file /home/klee/sample/Samples/Memory/double_free_if/double_free_if.yml

#include <stdlib.h>

#include <klee/klee.h>

// Ansatz file

int jorge(int condition)
{
    int *ptr = malloc(sizeof(int));
    free(ptr);

    if (condition > 0)
    {
        free(ptr);
    }

    return 0;
}

// End ansatz file



int main() {

  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  jorge(i);

  return 0;
}
