#include <stdio.h>

int main()
{
    char *str[] = {"Welcom", "to", "Fortemedia", "Nanjing"};
    char **p = str + 1;//pָ��str[1]�ĵ�ַ
    str[0] = (*p++) + 2;//++���Ż�������*��  ��ʱpָ����str[2]�ĵ�ַ
    str[1] = *(p+1);
    str[2] = p[1] + 3;//pָ�����str[2]�ĵ�ַ��str[2]�ĵ�ַ���ˣ�����pָ��ĵ�ַҲ���Ÿ��޸��ˣ�p[0] = "jing"
    str[3] = p[0] + (str[2] - str[1]);
    printf(" str[0] = %s\n", str[0]);
    printf(" str[1] = %s\n", str[1]);
    printf(" str[2] = %s\n", str[2]);
    printf(" str[3] = %s\n", str[3]);

    return 0;
}
