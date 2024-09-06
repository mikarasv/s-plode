#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Int number not provided.\n");
        return 1;
    }

    int input = atoi(argv[1]);
    int result;

    result = INT_MAX - 3;
    for (int i = 0; i < input; ++i)
    {
        result += 1;
    }
    printf("Overflow result in bucle: %d\n", result);

    return 0;
}