int g;
int f1(int x, int y)
{
  int a = x + 1;
  return y * a;
}

int f2(int *x) { return &x; }

int f3()
{
  int b, c = 1;
  int x;
  int *p = &g;
  x = f1(g, 3);
  int a = 5 / x;
  b = a + f2(p);
}