#include <limits.h>
#include "../mocks.h"

int pedro(int input)
{
    int overflow_example = INT_MAX;
    if (input > 0)
    {
        overflow_example += input;
        print("Overflow result: %d\n", overflow_example);
    }
    return 0;
}
