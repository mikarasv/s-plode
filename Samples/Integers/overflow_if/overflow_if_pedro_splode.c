// This file was generated from /home/klee/sample/Samples/Integers/overflow_if/overflow_if.c and config file /home/klee/sample/Samples/Integers/overflow_if/overflow_if.yml

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
