int asd()
{
  return 10;
}

int add_one(int a) { return a + 1; }

void main(int b)
{
  int result = add_one(b + asd());
}