int pascual(int input)
{
    while (input <= -100000)
    {
        input--;
        if (input == INT_MIN)
        {
            printf("Underflow in while: %d\n", input);
            input--;
            break;
        }
    }

    printf("Result: %d\n", input);

    return 0;
}
