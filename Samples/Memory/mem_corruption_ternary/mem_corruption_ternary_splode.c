// Section1: includes
#include <stdio.h>
#include <stdlib.h>
// fixed includes
#include <klee/klee.h>

// Section2: generated mocks
int printf(const char *arg1, ...)
{
  return 0;
}

// Section3: ansatz + extracted code from subgraph
int jaime(int index)
{
  int *array = malloc(5 * sizeof(int));

  switch (index)
  {
  case 6:
    array[6] = 20;
    printf("Value assigned out of limits\n");
    break;
  default:
    array[0] = 10;
    break;
  }

  free(array);
  return 0;
}

// Section4: the main() function
int main()
{
  int i;
  klee_make_symbolic(&i, sizeof(i), "i");
  return jaime(i);
}
