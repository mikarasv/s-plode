// Section1: includes
#include <string.h>
#include <stdlib.h>
// fixed includes
#include <klee/klee.h>

// Section2: generated mocks
int printf(const char *arg1, ...)
{
  return 0;
}

// Section3: ansatz + extracted code from subgraph
int CONSTANT;
int CONDITION;
int jose(int condition)
{

  int *ptr = malloc(sizeof(int));
  *ptr = CONSTANT;

  condition == CONDITION ? free(ptr) : (void)0;

  if (condition == CONDITION)
  {
    int a = *ptr;
  }
  else
  {
    free(ptr);
  }

  return 0;
}

// Section4: the main(), setup() and teardown() functions
static void setup()
{
  CONSTANT = 10;
  CONDITION = 1;
}

static void teardown()
{
}

int main()
{
  setup();
  int i;
  klee_make_symbolic(&i, sizeof(i), "i");
  int ret = jose(i);
  teardown();
  return ret;
}
