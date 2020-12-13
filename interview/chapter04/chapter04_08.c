#include <stdio.h>
#include <string.h>

void test1()
{
    char string[11];//字符数组长度为11，多分配一个
    char *str1 = "0123456789";
    strcpy(string, str1);
}

void test2()
{
    char string[11], str1[11];//字符数组长度都为11，均多分配一个
    int i;
    for(i = 0; i < 10; i++)
    {
        str1[i] = 'a';
    }
    str1[10] = '\0';//初始化str1为空字符串
    strcpy(string, str1);
}

void test3(char *str1)
{
    char string[10];
    if(strlen(str1) < 10)//不能用<=
    {
        strcpy(string, str1);
    }
}

int main()
{
    test1();
    test2();
    test3("1234");

    return 0;
}
