// This file was generated from /home/klee/sample/Samples/Integers/underflow_while/underflow_while.c and config file /home/klee/sample/Samples/Integers/underflow_while/underflow_while.yml

#include <limits.h>
#include "../mocks.h"

#include <klee/klee.h>

// Ansatz file


int CONSTANT;
int pascual(int input)
{
    while (input <= -CONSTANT)
    {
        input--;
        if (input == INT_MIN)
        {
            input--;
            break;
        }
    }

    return 0;
}

// End ansatz file



int main() {

  CONSTANT = 2147483644;


  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  pascual(i);

  return 0;
}
