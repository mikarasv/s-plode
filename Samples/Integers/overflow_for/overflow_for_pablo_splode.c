// This file was generated from /home/klee/sample/Samples/Integers/overflow_for/overflow_for.c and config file /home/klee/sample/Samples/Integers/overflow_for/overflow_for.yml

#include <limits.h>

#include <klee/klee.h>

// Ansatz file

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

    return 0;
}

// End ansatz file



int main() {

  INCREMENT = 1;
  CONSTANT = 5;


  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  pablo(i);

  return 0;
}
