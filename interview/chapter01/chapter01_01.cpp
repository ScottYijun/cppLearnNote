#include <stdio.h>

int main(void)
{
    int x = 3, y, z;

    x *= (y = z = 4);                   printf("x = %d\n", x);//12

    z = 2;
    x = (y = z);                        printf("x = %d\n", x);//2
    x = (y == z);                       printf("x = %d\n", x);//1
    x = (y & z);                        printf("x = %d\n", x);//2
    x = (y && z);                       printf("x = %d\n", x);//1

    y = 4;
    x = (y | z);                        printf("x = %d\n", x);//6
    x = (y || z);                       printf("x = %d\n", x);//1

    x = (y == z)? 4: 5;                 printf("x = %d\n", x);//5

    x = (y == z)? 1: (y < z)? 2: 3;     printf("x = %d\n", x);//3

    return 0;
}
