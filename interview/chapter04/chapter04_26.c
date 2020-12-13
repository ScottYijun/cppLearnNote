#include <stdio.h>

char *deleteChar(char *str, char c)
{
    char *head = NULL;                  //head与p都设置为头节点那边
    char *p = NULL;

    if (str == NULL)                    //检查str的有效性
    {
        return NULL;
    }

    head = p = str;                     //指向字符串头，准备遍历

    while (*p++)
    {
        if (*p != c)                    //如果不等于c的值，则在str中记录
        {
            *str++ = *p;
        }
    }
    *str = '\0';

    return head;
}

int main()
{
    char string[] = "cabcdefcgchci";
    char c = 0;

    printf("input char:");
    scanf("%c", &c);
    printf("before delete:%s\n", string);
    deleteChar(string, c);              //删除所有的c
    printf("after delete:%s\n", string);

    return 0;
}
