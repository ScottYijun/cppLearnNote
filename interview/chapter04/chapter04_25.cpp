#include <stdio.h>
#include <stdlib.h>

//ð�������㷨
void mysort(char *str, int num)
{
    int i, j;
    int temp = 0;

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (str[i] < str[j])            //�����һ��ֵ�ȵ�ǰֵ��
            {                               //�򽻻�����Ԫ��ֵ
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

char *foo(char *str)
{
    int len = 0;
    char *start = NULL;

    if (str == NULL)                        //������str����Ч��
    {
        return NULL;
    }

    start = str;                            //����ͷ��λ��
    while (*str++);
    len = str - start - 1;                  //�����ַ�������
    len = len / 2;                          //������Ҫ������ַ�����
    str = start;

    mysort(str, len);                       //�Ӵ�С����

    return str;
}

int main()
{
    char string[] = "ADZDDJKJFIEJHGI";
    printf("before transformation:%s\n", string);
    foo(string);                            //����ð�����򷽷���������
    printf("after transformation:%s\n", string);

    return 0;
}
