int g;
int g2; // Only symbolic
int g3;

int f(int x) { return x + g3; }

void fun()
{
  int a, b, c, d, e, h;
  a = g + 1;
  b = f(a);
  c = a + b % 3;
  c = -c;
  d = 10 * c;

  h = g2 + 5;
  e = 5 / h;
}
