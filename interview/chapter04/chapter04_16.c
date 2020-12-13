#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *commonstring(char *str1, char *str2)
{
    int i, j;
    char *shortstr, *longstr;
    char *substr;

    if (str1 == NULL || str2 == NULL)               //判断两个字符的有效性
    {
        return NULL;
    }

    if (strlen(str1) <= strlen(str2))               //shortstr和longstr分别指向较短和较长的字符串
    {
        shortstr = str1;
        longstr = str2;
    }
    else {
        shortstr = str2;
        longstr = str1;
    }

    if (strstr(longstr, shortstr) != NULL)          //如果在较长的字符串中找到较小的字符串，
    {                                               //则返回短字符串
        return shortstr;
    }

    substr = (char *)malloc(sizeof(char)*(strlen(shortstr) + 1));//申请 堆内存 存放返回结果
    //循环取短串的子串放入堆内存，调用strstr函数检查长串中是否包含这个子串，如果有，则返回堆内存。这个短串长度不断减少的
    for (i = strlen(shortstr) - 1; i > 0; i--)
    {
        for (j = 0; j <= strlen(shortstr) - i; j++)
        {
            memcpy(substr, &shortstr[j], i);        //将短字符串的一部分复制到substr，
            substr[i] = '\0';                       //其长度逐渐减小
            if (strstr(longstr, substr) != NULL)    //如果在lognstr中找到substr，则返回substr
                return substr;
        }
    }

    return NULL;
}

int main()
{
    char *str1 = (char *)malloc(256);               //分配堆内存存放字符串str1和str2
    char *str2 = (char *)malloc(256);
    char *common = NULL;

    gets_s(str1,20);                                //从终端输入str1和str2
    gets_s(str2,20);

    common = commonstring(str2, str1);              //取最大的相同子串

    printf("the longest common string is:%s\n", common);

    return 0;
}
