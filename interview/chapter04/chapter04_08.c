#include <stdio.h>
#include <string.h>

void test1()
{
    char string[11];//�ַ����鳤��Ϊ11�������һ��
    char *str1 = "0123456789";
    strcpy(string, str1);
}

void test2()
{
    char string[11], str1[11];//�ַ����鳤�ȶ�Ϊ11���������һ��
    int i;
    for(i = 0; i < 10; i++)
    {
        str1[i] = 'a';
    }
    str1[10] = '\0';//��ʼ��str1Ϊ���ַ���
    strcpy(string, str1);
}

void test3(char *str1)
{
    char string[10];
    if(strlen(str1) < 10)//������<=
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
