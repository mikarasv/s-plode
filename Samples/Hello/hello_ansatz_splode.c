// This file was generated from /home/klee/ and config file /home/klee/


#include <klee/klee.h>

// Ansatz file
int i;
int ret_f;
int f()
{
  return ret_f;
}


int Divide(int a, int b)
{
  return a / (b * f());
}


int ansatz(void)
{
  int j = Divide(10, i);
  return 0;
}


// End ansatz file


void set_globals(int global_1) {

  i = global_1;
}


int main() {

  int global_1;
  klee_make_symbolic(&global_1, sizeof(global_1), "global_1");

  set_globals(global_1);

  ansatz();

  return 0;
}
