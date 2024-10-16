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
int CONSTANT;
int pascual(int input)
{
  while (input <= -CONSTANT)
  {
    input--;
    if (input == INT_MIN)
    {
      printf("Underflow in while: %d\n", input);
      input--;
      break;
    }
  }

  printf("Result: %d\n", input);

  return 0;
}

// Section4: the main(), setup() and teardown() functions
static void setup()
{
  CONSTANT = 1000000;
}
int main()
{
  int i;
  klee_make_symbolic(&i, sizeof(i), "i");
  return pascual(i);
}