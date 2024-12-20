#include <limits.h>
#include "../mocks.h"

#include <klee/klee.h>

// Ansatz file

int INCREMENT;
int pepe(int input)
{
    int result;

    switch (input)
    {
    case 1: // Overflow
        result = INT_MAX;
        result += INCREMENT;
        print("Overflow result: %d\n", result);
        break;
    case -1: // Underflow
        result = INT_MIN;
        result -= INCREMENT;
        print("Underflow result: %d\n", result);
        break;
    default:
        break;
        print("1 for overflow or -1 for underflow.\n");
    }

    return result;
}

// End ansatz file



int main() {

  INCREMENT = 1;


  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  pepe(i);

  return 0;
}
