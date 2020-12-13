#include <stdio.h>
#include <string.h>
//str���ַ��� pos:�Ӹ�λ�ÿ�ʼ len:ɾ���ĳ���
char  *deleteChars(char *str, int pos, int len)
{
    char *p = str + pos - 1;                //ָ��posλ���ַ�
    int tt = strlen(str);                   //�����ַ�����

    if ((pos < 1) || (p - str) > tt)        //���pos�Ƿ񲻴���1
    {                                       //����pos�����ַ�������
        return str;
    }

    if ((p + len - str) > tt)               //len����pos��ʣ����ַ�����
    {                                       //ֻ���posλ�ø�'\0'
        *p = '\0';
        return str;
    }

    //ɾ��len���ַ�
    while (*p &&*(p + len))                 //lenС�ڻ����pos��ʣ����ַ�����
    {                                       //ɾ���м�len���ַ�
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
