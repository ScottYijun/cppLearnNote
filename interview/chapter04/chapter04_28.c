#include <stdio.h>
#include <stdlib.h>

char *mystrcat(char *dest, const char *src)
{
    char *ret;

    ret = dest;                             //保存目的字符串首地址以便返回
    while (*dest++);
    dest--;                                 //此时dest指向字符串结束符
    while (*dest++ = *src++);               //循环复制

    return ret;
}

int main()
{
    char *dest = NULL;
    char *str1 = "Hello ";
    char *str2 = "World!";

    dest = (char *)malloc(256);
    *dest = '\0';                           //为把目标字符串置为空，将结束符放在其开头
    mystrcat(mystrcat(dest, str1), str2);   //链式表达式连接str1和str2
    printf("dest:%s\n", dest);
    free(dest);
    dest = NULL;

    return 0;
}
