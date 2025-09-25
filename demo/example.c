int global;

int division(int x) { return 2 / x; }

int ansatz(int x)
{
  int a = division(x);
  return a + global;
}
