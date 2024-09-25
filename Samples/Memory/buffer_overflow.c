#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "This is a long text that will overflow the buffer");

    printf("Buffer: %s\n", buffer);
    return 0;
}