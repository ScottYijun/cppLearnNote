#include <stdio.h>

int main()
{
    int ival    = 1024;
    int ival2   = 2048;
    int *pi1    = &ival;
    int *pi2    = &ival2;
    int **pi3   = 0;

    ival    = *pi3; //编译错误，ival是int型，*pi3是 int*类型，不能隐式转换
    *pi2    = *pi3; //编译错误，*pi2是int型，*pi3是 int*类型，不能隐式转换
    ival    = pi2;  //编译错误，ival是int型，pi2是 int*类型，不能隐式转换
    pi2     = *pi1; //编译错误，pi2是int*型，*pi1是 int类型，不能隐式转换
    pi1     = *pi3; //运行时错误，pi3是NULL指针，试图得到*pi3的值会发生运行错误
    ival    = *pi1;
    pi1     = ival; //编译错误，pi1是int*型，ival是 int类型，不能隐式转换
    pi3     = &pi2;

    return 0;
}











