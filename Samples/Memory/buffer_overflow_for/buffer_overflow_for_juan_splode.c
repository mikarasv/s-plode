#include <string.h>
#include <stdlib.h>

#include <klee/klee.h>

// Ansatz file
int CONSTANT;
int juan(int size)
{
    char buffer[CONSTANT];

    for (int i = 0; i < size; i++)
    {
        buffer[i] = 'A';
    }

    buffer[CONSTANT - 1] = '\0';

    return 0;
}

// End ansatz file



int main() {

  CONSTANT = 5;


  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  juan(i);

  return 0;
}
