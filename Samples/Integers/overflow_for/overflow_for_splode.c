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
int INCREMENT;
int pablo(int input)
{
  int result;

  result = INT_MAX - CONSTANT;
  for (int i = 0; i < input; ++i)
  {
    result += INCREMENT;
  }
  printf("Result in bucle: %d + %d = %d\n", INT_MAX - 3, input, result);

  return 0;
}

// Section4: the main(), setup() and teardown() functions
static void setup()
{
  CONSTANT = 5;
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
  int ret = pablo(i);
  teardown();
  return ret;
}
