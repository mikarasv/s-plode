int CONSTANT;
int CONDITION;
int jose(int condition)
{

    int *ptr = malloc(sizeof(int));
    *ptr = CONSTANT;

    condition == CONDITION ? free(ptr) : (void)0;

    if (condition == CONDITION)
    {
        int a = *ptr;
    }
    else
    {
        free(ptr);
    }

    return 0;
}
