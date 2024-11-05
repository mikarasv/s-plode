// Section1: includes
#include <limits.h>
// fixed includes
#include <klee/klee.h>

// Section2: generated mocks
int printf(const char *arg1, ...)
{
  return 0;
}

// Section3: ansatz + extracted code from subgraph
int pedro(int input)
{
  int overflow_example = INT_MAX;
  if (input > 0)
  {
    overflow_example += input;
    printf("Overflow result: %d\n", overflow_example);
  }
  return 0;
}

// Section4: the main() function
int main()
{
  int i;
  klee_make_symbolic(&i, sizeof(i), "i");
  return pedro(i);
}
