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

    while (input <= 0 && input > INT_MIN)
    {
        input--;
        if (input == INT_MIN)
        {
            printf("Underflow in while: %d\n", input);
            input--;
            break;
        }
    }

    printf("Result: %d\n", input);

    return 0;
}
