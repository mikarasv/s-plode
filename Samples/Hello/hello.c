int i;
int ret_f;
int f() { return ret_f; }

int Divide(int a, int b)
{
  return a / (b * f());
}

int ansatz(void)
{
  int j = Divide(10, i);
  return 0;
}
