#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* addBigInt(char* num1, char* num2)
{
    int c = 0;                                  //cΪ��λ����ʼ��ͽ�λΪ0;
    int i = strlen(num1) - 1;                   //iָ���һ�����������λ
    int j = strlen(num2) - 1;                   //jָ��ڶ������������λ
                                                //�������нϴ�����λ��
    int maxLength = strlen(num1) >= strlen(num2) ? strlen(num1) + 1 : strlen(num2) + 1;
    char* rst = (char*)malloc(maxLength + 1);   //�������
    int k;
    if (rst == NULL)                            //����ж�������ڴ��Ƿ�ɹ�
    {
        printf("malloc error!\n");
        exit(1);
    }

    rst[maxLength] = '\0';                      //�ַ������һλΪ'\0'
    k = strlen(rst) - 1;                        //ָ������������λ
    while ((i >= 0) && (j >= 0))
    {
        rst[k] = ((num1[i] - '0') + (num2[j] - '0') + c) % 10 + '0';
        c = ((num1[i] - '0') + (num2[j] - '0') + c) / 10;
        --i;
        --j;
        --k;
    }
    while (i >= 0)                              //����Ǹ��ֲ�
    {
        rst[k] = ((num1[i] - '0') + c) % 10 + '0';
        c = ((num1[i] - '0') + c) / 10;
        --i;
        --k;
    }
    while (j >= 0)                              //����Ǹ��ֲ�
    {
        rst[k] = ((num1[j] - '0') + c) % 10 + '0';
        c = ((num2[j] - '0') + c) / 10;
        --j;
        --k;
    }
    rst[0] = c + '0';

    if (rst[0] != '0')                          //���������λ������0����������
    {
        return rst;
    }
    else
    {
        return rst + 1;
    }
}

int main()
{
    char num1[] = "123456789323";
    char num2[] = "45671254563123";
    char *result = NULL;

    result = addBigInt(num1, num2);
    printf("%s + %s = %s\n", num1, num2, result);

    return 0;
}

