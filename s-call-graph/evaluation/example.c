#include <stdio.h>

char *global_string = "Hello, World!";

void funcA(int x);
void funcB(int y);
void funcC(int z);
void funcD(int w);
void funcE(int u);

void funcA(int x)
{
  funcB(x);
}

void funcB(int y)
{
  funcC(y);
}

void funcC(int z)
{
  funcD(z);
  funcE(z + 1);
}

void funcD(int w)
{
  funcE(w);
  global_string = "Hello, Universe!";
}

void funcE(int u)
{
  printf("%s\n", global_string);
}

int main()
{
  funcA(5);
  return 0;
}