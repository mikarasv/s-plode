// This file was generated from /home/klee/sample/Samples/Memory/use_after_free_ternary/use_after_free_ternary.c and config file /home/klee/sample/Samples/Memory/use_after_free_ternary/use_after_free_ternary.yml

#include <string.h>
#include <stdlib.h>

#include <klee/klee.h>

// Ansatz file


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

// End ansatz file



int main() {

  CONSTANT = 10;
  CONDITION = 1;


  int i;
  klee_make_symbolic(&i, sizeof(i), "i");

  jose(i);

  return 0;
}
