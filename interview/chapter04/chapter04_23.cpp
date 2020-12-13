#include <stdio.h>
#include <stdlib.h>

void loopMove(char *str, int n)
{
    int i = 0;
    char *temp = NULL;
    int strLen = 0;
    char *head = str;                       //ָ���ַ���ͷ

    while (*str++);                         //���str�ߵ��ַ���ĩβ��
    strLen = str - head - 1;                //�����ַ�������
    n = n % strLen;                         //�����ַ���β���Ƶ�ͷ�����ַ�
    temp = (char *)malloc(n);               //�����ڴ�
    for (i = 0; i < n; i++)
    {
        temp[i] = head[strLen - n + i];     //��ʱ��Ŵ�β���Ƶ�ͷ�����ַ�
    }
    for (i = strLen - 1; i >= n; i--)
    {
        head[i] = head[i - n];              //��ͷ���ַ��Ƶ�β��
    }
    for (i = 0; i < n; i++)
    {
        head[i] = temp[i];                  //����ʱ�ڴ�������β���ַ�
    }

    free(temp);                             //�ͷ��ڴ�
}

int main()
{
    char string[] = "123456789";
    int steps = 0;

    printf("string:%s\n", string);
    printf("input step:");
    scanf("%d", &steps);
    loopMove(string, steps);                //����ѭ����λ
    printf("after loopMove %d:%s\n", steps, string);

    return 0;
}
