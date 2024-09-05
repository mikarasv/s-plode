#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Int number not provided.\n");
        return 1;
    }

    int input = atoi(argv[1]);

    int underflow_example = input < 0 ? INT_MIN + input : INT_MIN;
    printf("Underflow result: %d\n", underflow_example);

    return 0;
}
