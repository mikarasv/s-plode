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
