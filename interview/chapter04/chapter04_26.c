#include <stdio.h>

char *deleteChar(char *str, char c)
{
    char *head = NULL;                  //head��p������Ϊͷ�ڵ��Ǳ�
    char *p = NULL;

    if (str == NULL)                    //���str����Ч��
    {
        return NULL;
    }

    head = p = str;                     //ָ���ַ���ͷ��׼������

    while (*p++)
    {
        if (*p != c)                    //���������c��ֵ������str�м�¼
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
    deleteChar(string, c);              //ɾ�����е�c
    printf("after delete:%s\n", string);

    return 0;
}
