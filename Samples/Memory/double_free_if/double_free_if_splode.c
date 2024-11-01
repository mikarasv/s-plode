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
int jorge(int condition)
{
  int *ptr = malloc(sizeof(int));
  free(ptr);

  if (condition > 0)
  {
    free(ptr);
    printf("Double free attempt.\n");
  }

  return 0;
}

// Section4: the main() function
int main()
{
  int i;
  klee_make_symbolic(&i, sizeof(i), "i");
  return jorge(i);
}
