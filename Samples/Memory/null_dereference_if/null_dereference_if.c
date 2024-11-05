int jairo(int input)
{
    int *ptr = NULL;

    if (input == 1)
    {
        ptr = malloc(sizeof(int));
    }

    if (ptr == NULL)
    {
        printf("Pointer value (NULL): %d\n", *ptr); // Null dereference
    }
    else
    {
        *ptr = 10;
        printf("Assigned value: %d\n", *ptr);
        free(ptr);
    }

    return 0;
}
