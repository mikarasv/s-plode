int jaime(int index)
{
    int *array = malloc(5 * sizeof(int));

    switch (index)
    {
    case 6:
        array[6] = 20;
        printf("Value assigned out of limits\n");
        break;
    default:
        array[0] = 10;
        break;
    }

    free(array);
    return 0;
}
