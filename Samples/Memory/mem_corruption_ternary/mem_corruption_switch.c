#include <stdlib.h>

int jaime(int index)
{
    int *array = malloc(5 * sizeof(int));

    switch (index)
    {
    case 6:
        array[6] = 20;
        break;
    default:
        array[0] = 10;
        break;
    }

    free(array);
    return 0;
}
