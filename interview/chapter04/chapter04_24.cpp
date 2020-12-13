#include <stdio.h>
#include <string.h>
//str：字符串 pos:从该位置开始 len:删除的长度
char  *deleteChars(char *str, int pos, int len)
{
    char *p = str + pos - 1;                //指向pos位置字符
    int tt = strlen(str);                   //计算字符长度

    if ((pos < 1) || (p - str) > tt)        //检查pos是否不大于1
    {                                       //或者pos超出字符串长度
        return str;
    }

    if ((p + len - str) > tt)               //len大于pos后剩余的字符个数
    {                                       //只需对pos位置赋'\0'
        *p = '\0';
        return str;
    }

    //删除len个字符
    while (*p &&*(p + len))                 //len小于或等于pos后剩余的字符个数
    {                                       //删除中间len个字符
        *p = *(p + len);
        p++;
    }
    *p = '\0';

    return str;
}

int main()
{
    char string[] = "abcdefg";
    int pos = 0;
    int len = 0;
    int steps = 0;
    printf("string:%s\n", string);
    printf("input pos:");
    scanf_s("%d", &pos);
    printf("input len:");
    scanf("%d", &len);
    deleteChars(string, pos, len);
    printf("after delete %d chars behind pos %d:%s\n", len, pos, string);

    return 0;
}
