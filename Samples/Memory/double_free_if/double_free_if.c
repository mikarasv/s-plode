#include <stdlib.h>

int jorge(int condition)
{
    int *ptr = malloc(sizeof(int));
    free(ptr);

    if (condition > 0)
    {
        free(ptr);
    }

    return 0;
}
