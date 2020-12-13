#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_int = 435;
    double num_double = 435.10f;
    char str_int[30];
    char str_double[30];

    itoa(num_int, str_int, 10);//把整数num_int转成字符串str_int
    gcvt(num_double, 8, str_double);//把浮点数num_double转换成字符串str_double

    printf("str_int: %s\n", str_int);
    printf("str_double: %s\n", str_double);

    return 0;
}
