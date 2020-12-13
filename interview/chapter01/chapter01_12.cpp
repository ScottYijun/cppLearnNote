#include<stdlib.h>                          //使用atexit()函数必须包含头文件stdlib.h
#include<stdio.h>

void fn1(void);
void fn2(void);

int main(void)
{
    atexit(fn1);                            //使用atexit注册fn1()函数
    atexit(fn2);                            //使用atexit注册fn2()函数
    printf("main exit...\n");
    return 0;
}

void fn1()
{
    printf("calling fn1()...\n");           //fn1()函数打印内容
}

void fn2()
{
    printf("calling fn2()...\n");           //fn2()函数打印内容
}
