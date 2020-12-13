#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
char *get2String(long num)                  //得到二进制形式的字符串
{
    int i = 0;
    char *buffer;
    char* temp;
    //long型整数是4个字节，每个8位，一共32位。申请了33个字节(包括'\0')的堆内存存放结果
    buffer = (char*)malloc(33);
    temp = buffer;                          //temp
    for (i = 0; i < 32; i++)
    {                                       //给数组的32个元素赋值0或者1
        temp[i] = num&(1 << (31 - i));
        temp[i] = temp[i] >> (31 - i);
        temp[i] = (temp[i] == 0) ? '0' : '1';
    }
    buffer[32] = '\0';                      //字符串结束符
    return buffer;
}

char *get16String(long num)                 //得到十六进制形式的字符串
{
    int i = 0;
    char *buffer = (char*)malloc(11);
    char *temp;

    buffer[0] = '0';
    buffer[1] = 'x';
    buffer[10] = '\0';                      //字符串结束符
    temp = buffer + 2;

    for (i = 0; i < 8; i++)
    {                                       //给数组的8个元素赋值
        temp[i] = (char)(num << 4 * i >> 28);
        temp[i] = temp[i] >= 0 ? temp[i] : temp[i] + 16;
        temp[i] = temp[i] < 10 ? temp[i] + 48 : temp[i] + 55;
    }
    return buffer;
 }

int main()
{
    char *p = NULL;
    char *q = NULL;
    int num = 0;

    printf("input num:");                   //输入整数
    scanf_s("%d", &num);

    p = get16String(num);                   //得到十六进制的字符串
    q = get2String(num);                    //得到二进制形式的字符串

    printf("%s\n", p);
    printf("%s\n", q);

    return 0;
}

