int jorge(int condition)
{
    int *ptr = malloc(sizeof(int));
    free(ptr);

    if (condition > 0)
    {
        free(ptr);
        printf("Double free attempt.\n");
    }

    return 0;
}
