#include <limits.h>
#include "../mocks.h"

int CONSTANT;
int pascual(int input)
{
    while (input <= -CONSTANT)
    {
        input--;
        if (input == INT_MIN)
        {
            input--;
            break;
        }
    }

    return 0;
}
