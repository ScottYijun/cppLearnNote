#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
char *get2String(long num)                  //�õ���������ʽ���ַ���
{
    int i = 0;
    char *buffer;
    char* temp;
    //long��������4���ֽڣ�ÿ��8λ��һ��32λ��������33���ֽ�(����'\0')�Ķ��ڴ��Ž��
    buffer = (char*)malloc(33);
    temp = buffer;                          //temp
    for (i = 0; i < 32; i++)
    {                                       //�������32��Ԫ�ظ�ֵ0����1
        temp[i] = num&(1 << (31 - i));
        temp[i] = temp[i] >> (31 - i);
        temp[i] = (temp[i] == 0) ? '0' : '1';
    }
    buffer[32] = '\0';                      //�ַ���������
    return buffer;
}

char *get16String(long num)                 //�õ�ʮ��������ʽ���ַ���
{
    int i = 0;
    char *buffer = (char*)malloc(11);
    char *temp;

    buffer[0] = '0';
    buffer[1] = 'x';
    buffer[10] = '\0';                      //�ַ���������
    temp = buffer + 2;

    for (i = 0; i < 8; i++)
    {                                       //�������8��Ԫ�ظ�ֵ
        temp[i] = (char)(num << 4 * i >> 28);
        temp[i] = temp[i] >= 0 ? temp[i] : temp[i] + 16;
        temp[i] = temp[i] < 10 ? temp[i] + 48 : temp[i] + 55;
    }
    return buffer;
 }

int main()
{
    char *p = NULL;
    char *q = NULL;
    int num = 0;

    printf("input num:");                   //��������
    scanf_s("%d", &num);

    p = get16String(num);                   //�õ�ʮ�����Ƶ��ַ���
    q = get2String(num);                    //�õ���������ʽ���ַ���

    printf("%s\n", p);
    printf("%s\n", q);

    return 0;
}

