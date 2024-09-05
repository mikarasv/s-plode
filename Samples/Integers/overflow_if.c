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

    int overflow_example = INT_MAX;
    if (input > 0)
    {
        overflow_example += input;
        printf("Overflow result: %d\n", overflow_example);
    }
    return 0;
}
