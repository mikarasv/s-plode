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
    int result;

    switch (input)
    {
    case 1: // Overflow
        result = INT_MAX;
        result += 1;
        printf("Overflow result: %d\n", result);
        break;
    case -1: // Underflow
        result = INT_MIN;
        result -= 1;
        printf("Underflow result: %d\n", result);
        break;
    default:
        printf("1 for overflow or -1 for underflow.\n");
    }

    return 0;
}
