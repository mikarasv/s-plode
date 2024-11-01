int CONSTANT;
int juan(int size)
{
    char buffer[CONSTANT];

    for (int i = 0; i < size; i++)
    {
        buffer[i] = 'A';
    }

    buffer[CONSTANT - 1] = '\0';
    printf("Buffer content: %s\n", buffer);

    return 0;
}
