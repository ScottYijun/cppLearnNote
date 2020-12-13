#include <stdio.h>

int value = 0;

void printvalue()
{
    printf("value = %d\n", value);
}

int main()
{
    int value = 0;
    value = 1;
    printf("value = %d\n", value);
    ::value = 2;
    printvalue();
    return 0;
}
