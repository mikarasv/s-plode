// This file was generated from /home/klee/sample/Samples/Integers/underflow_ternary/underflow_ternary.c and config file /home/klee/sample/Samples/Integers/underflow_ternary/underflow_ternary.yml

#include <limits.h>

#include <klee/klee.h>

// Ansatz file

int pancho(int input)
{
    int underflow_example = input < 0 ? INT_MIN + input : INT_MIN;

    return 0;
}

// End ansatz file



int main() {

  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  pancho(i);

  return 0;
}
