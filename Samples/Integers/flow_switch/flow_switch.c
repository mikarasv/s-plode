int INCREMENT;
int pepe(int input)
{
    int result;

    switch (input)
    {
    case 1: // Overflow
        result = INT_MAX;
        result += INCREMENT;
        printf("Overflow result: %d\n", result);
        break;
    case -1: // Underflow
        result = INT_MIN;
        result -= INCREMENT;
        printf("Underflow result: %d\n", result);
        break;
    default:
        printf("1 for overflow or -1 for underflow.\n");
    }

    return 0;
}
