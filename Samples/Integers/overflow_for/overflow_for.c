int CONSTANT;
int INCREMENT;

int pablo(int input)
{
    int result;

    result = INT_MAX - CONSTANT;
    for (int i = 0; i < input; ++i)
    {
        result += INCREMENT;
    }
    printf("Result in bucle: %d + %d = %d\n", INT_MAX - 3, input, result);

    return 0;
}
