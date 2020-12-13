#include <stdio.h>

char getChar(int x, int y)
{
    char c;
    unsigned int a = x;

    (a + y > 10) ? (c = 1): (c = 2);
    return c;
}

int main(void)
{
    char c1 = getChar(7, 4);
    char c2 = getChar(7, 3);
    char c3 = getChar(7, -7);
    char c4 = getChar(7, -8);

    printf("c1 = %d\n", c1);//1
    printf("c2 = %d\n", c2);//2
    printf("c3 = %d\n", c3);//2
    printf("c4 = %d\n", c4);//1
    return 0;
}
