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
int INCREMENT;

int pepe(int input)
{
  int result;

  switch (input)
  {
  case 1: // Overflow
    result = INT_MAX;
    result += INCREMENT;
    printf("Overflow result: %d\n", result);
    break;
  case -1: // Underflow
    result = INT_MIN;
    result -= INCREMENT;
    printf("Underflow result: %d\n", result);
    break;
  default:
    printf("1 for overflow or -1 for underflow.\n");
  }

  return 0;
}

// Section4: the main(), setup() and teardown() functions
static void setup()
{
  INCREMENT = 1;
}

static void teardown()
{
}

int main()
{
  setup();
  int i;
  klee_make_symbolic(&i, sizeof(i), "i");
  int ret = pepe(i);
  teardown();
  return ret;
}
