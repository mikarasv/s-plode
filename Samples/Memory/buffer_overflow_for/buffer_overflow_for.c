#include <string.h>
#include <stdlib.h>

int CONSTANT;
int juan(int size)
{
    char buffer[CONSTANT];

    for (int i = 0; i < size; i++)
    {
        buffer[i] = 'A';
    }

    buffer[CONSTANT - 1] = '\0';

    return 0;
}
