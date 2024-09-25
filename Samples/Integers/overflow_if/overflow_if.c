int pedro(int input)
{
    int overflow_example = INT_MAX;
    if (input > 0)
    {
        overflow_example += input;
        printf("Overflow result: %d\n", overflow_example);
    }
    return 0;
}
