#include <stdio.h>
#include <stdlib.h>

void loopMove(char *str, int n)
{
    int i = 0;
    char *temp = NULL;
    int strLen = 0;
    char *head = str;                       //指向字符串头

    while (*str++);                         //这边str走到字符串末尾了
    strLen = str - head - 1;                //计算字符串长度
    n = n % strLen;                         //计算字符串尾部移到头部的字符
    temp = (char *)malloc(n);               //分配内存
    for (i = 0; i < n; i++)
    {
        temp[i] = head[strLen - n + i];     //临时存放从尾部移到头部的字符
    }
    for (i = strLen - 1; i >= n; i--)
    {
        head[i] = head[i - n];              //从头部字符移到尾部
    }
    for (i = 0; i < n; i++)
    {
        head[i] = temp[i];                  //从临时内存区复制尾部字符
    }

    free(temp);                             //释放内存
}

int main()
{
    char string[] = "123456789";
    int steps = 0;

    printf("string:%s\n", string);
    printf("input step:");
    scanf("%d", &steps);
    loopMove(string, steps);                //向右循环移位
    printf("after loopMove %d:%s\n", steps, string);

    return 0;
}
