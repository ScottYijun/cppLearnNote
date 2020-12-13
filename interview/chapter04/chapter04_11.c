#include <stdio.h>
#include <assert.h>

int strlen1(const char* src)
{
    assert(NULL != src);                    //src必须有效
    int len = 0;                            //保持src首地址
    while (*src++ != '\0')                  //遇到结束符'\0'时退出循环
        len++;                              //每循坏一次，len加1
    return len;
}

int strlen2(const char* src)
{
    assert(NULL != src);                    //src必须有效
    const char *temp = src;                 //保存src首地址
    while (*src++ != '\0');                 //遇到结束符'\0'时退出循环
    return (src - temp - 1);                //返回尾部指针与头指针之差，即长度
}

int main()
{
    char p[] = "Hello World!";
    printf("strlen1 len:%d\n", strlen1(p)); //打印方法1得到的结果
    printf("strlen2 len:%d\n", strlen2(p)); //打印方法2得到的结果

    return 0;
}
