#include <limits.h>

int CONSTANT;
int INCREMENT;

int pablo(int input)
{
    int result;

    result = INT_MAX - CONSTANT;
    for (int i = 0; i < input; ++i)
    {
        result += INCREMENT;
    }

    return 0;
}
