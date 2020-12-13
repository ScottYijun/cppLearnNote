#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOUNT 2*100

char *transformation(char *str)
{
    int len = strlen(str);
    char *buf = new char[len + 1];          //申请llen(str)+1个堆内存来存放字符串数字相关的信息

    char *p = str;
    char *q = p + 1;
    int count = 1;
    while (*q)
    {                                       //如果前一个和后一个相等，指针后移，计数增加
        if (*p == *q)
        {
            count++;
            p++;
            q++;
        }
        else
        {                                   //如果不等
            itoa(count, buf, 10);           //把整数转成字符串
            int nbits = strlen(buf);
            strcat(buf, q);                 //buf里面保存3b
            *q = 0;
            strcat(str, buf);               //str里面保存aaa
            q = q + nbits;
            p = q;
            q = p + 1;
            count = 1;
        }
    }

    itoa(count, buf, 10);
    strcat(str, buf);

    delete[]buf;                            //释放堆内存
    buf = NULL;
    return str;
}

int main()
{
    char str[MAXCOUNT];

    printf("please input a string:");
    scanf("%s", &str);
    printf("before transformation:%s\n", str);
    char *pstr = transformation(str);
    printf("after transformation:%s\n", pstr);

    return 0;
}
