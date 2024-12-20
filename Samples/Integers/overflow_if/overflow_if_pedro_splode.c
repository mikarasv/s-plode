#include <limits.h>
#include "../mocks.h"

#include <klee/klee.h>

// Ansatz file


int pedro(int input)
{
    int overflow_example = INT_MAX;
    if (input > 0)
    {
        overflow_example += input;
        print("Overflow result: %d\n", overflow_example);
    }
    return 0;
}

// End ansatz file



int main() {

  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  pedro(i);

  return 0;
}
