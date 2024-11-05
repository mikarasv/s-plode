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

// Section4: the main() function
int main()
{
  int i;
  klee_make_symbolic(&i, sizeof(i), "i");
  return jairo(i);
}
