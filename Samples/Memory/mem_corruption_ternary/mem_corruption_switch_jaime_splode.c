#include <stdlib.h>

#include <klee/klee.h>

// Ansatz file
int jaime(int index)
{
    int *array = malloc(5 * sizeof(int));

    switch (index)
    {
    case 6:
        array[6] = 20;
        break;
    default:
        array[0] = 10;
        break;
    }

    free(array);
    return 0;
}

// End ansatz file



int main() {

  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  jaime(i);

  return 0;
}
