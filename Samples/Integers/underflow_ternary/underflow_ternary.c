int pancho(int input)
{
    int underflow_example = input < 0 ? INT_MIN + input : INT_MIN;
    printf("Underflow result: %d\n", underflow_example);

    return 0;
}
