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
int pancho(int input)
{
  int underflow_example = input < 0 ? INT_MIN + input : INT_MIN;
  printf("Underflow result: %d\n", underflow_example);

  return 0;
}

// Section4: the main() function
int main()
{
  int i;
  klee_make_symbolic(&i, sizeof(i), "i");
  return pancho(i);
}
