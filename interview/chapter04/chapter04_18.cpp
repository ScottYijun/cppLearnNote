#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOUNT 2*100

char *transformation(char *str)
{
    int len = strlen(str);
    char *buf = new char[len + 1];          //����llen(str)+1�����ڴ�������ַ���������ص���Ϣ

    char *p = str;
    char *q = p + 1;
    int count = 1;
    while (*q)
    {                                       //���ǰһ���ͺ�һ����ȣ�ָ����ƣ���������
        if (*p == *q)
        {
            count++;
            p++;
            q++;
        }
        else
        {                                   //�������
            itoa(count, buf, 10);           //������ת���ַ���
            int nbits = strlen(buf);
            strcat(buf, q);                 //buf���汣��3b
            *q = 0;
            strcat(str, buf);               //str���汣��aaa
            q = q + nbits;
            p = q;
            q = p + 1;
            count = 1;
        }
    }

    itoa(count, buf, 10);
    strcat(str, buf);

    delete[]buf;                            //�ͷŶ��ڴ�
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
