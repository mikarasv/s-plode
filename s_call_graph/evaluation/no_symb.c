int g;
void f(int v1, int v2)
{
  v2 = v1;
}

int main()
{
  int x = 5;
  f(g, x);
  int a = 5 / x;
}
