#include <stdio.h>
#include <stdlib.h>

char *mystrcat(char *dest, const char *src)
{
    char *ret;

    ret = dest;                             //����Ŀ���ַ����׵�ַ�Ա㷵��
    while (*dest++);
    dest--;                                 //��ʱdestָ���ַ���������
    while (*dest++ = *src++);               //ѭ������

    return ret;
}

int main()
{
    char *dest = NULL;
    char *str1 = "Hello ";
    char *str2 = "World!";

    dest = (char *)malloc(256);
    *dest = '\0';                           //Ϊ��Ŀ���ַ�����Ϊ�գ��������������俪ͷ
    mystrcat(mystrcat(dest, str1), str2);   //��ʽ���ʽ����str1��str2
    printf("dest:%s\n", dest);
    free(dest);
    dest = NULL;

    return 0;
}
