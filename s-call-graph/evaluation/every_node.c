
// Typedefs
typedef unsigned int uint;
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

// Enum
enum Color
{
  RED,
  GREEN,
  BLUE
};

// Global Variable
int global_var = 10;

// Function Declaration
void print_message(char *message);

// Function Definition
int compute(int a, int b)
{
  int result;

  if (a > b)
  {
    result = a - b;
  }
  else
  {
    result = a + b;
  }

  while (result < 100)
  {
    result += 10;
  }

  for (int i = 0; i < 5; i++)
  {
    result += i;
  }

  do
  {
    result--;
  } while (result > 50);

  switch (result)
  {
  case 60:
    result += 2;
    break;
  case 70:
    result += 3;
    break;
  default:
    result += 5;
  }

  return result;
}

// Function with Pointers
void process(Node *node)
{
  Node *temp = node;
  while (temp != NULL)
  {
    printf("Data: %d\n", temp->data);
    temp = temp->next;
  }
}

// Main Function
int main()
{
  // Variables and Constants
  const float pi = 3.14;
  char c = 'A';
  int arr[5] = {1, 2, 3, 4, 5};
  Node node1 = {42, NULL};

  // Function Call
  print_message("Hello, World!");

  // Pointer Operations
  int x = 5;
  int *ptr = &x;
  *ptr = 10;

  // Struct and Enum Usage
  Node node2 = {99, &node1};
  enum Color myColor = RED;

  // Type Casting
  double y = (double)x;

  return compute(arr[1], node2.data);
}

// Function Implementation
void print_message(char *message)
{
  printf("%s\n", message);
}
