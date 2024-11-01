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
int juan(int size)
{
  char buffer[CONSTANT];

  for (int i = 0; i < size; i++)
  {
    buffer[i] = 'A';
  }

  buffer[CONSTANT - 1] = '\0';
  printf("Buffer content: %s\n", buffer);

  return 0;
}

// Section4: the main(), setup() and teardown() functions
static void setup()
{
  CONSTANT = 5;
}

static void teardown()
{
}

int main()
{
  setup();
  int i;
  klee_make_symbolic(&i, sizeof(i), "i");
  int ret = juan(i);
  teardown();
  return ret;
}
