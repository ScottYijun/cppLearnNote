#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *commonstring(char *str1, char *str2)
{
    int i, j;
    char *shortstr, *longstr;
    char *substr;

    if (str1 == NULL || str2 == NULL)               //�ж������ַ�����Ч��
    {
        return NULL;
    }

    if (strlen(str1) <= strlen(str2))               //shortstr��longstr�ֱ�ָ��϶̺ͽϳ����ַ���
    {
        shortstr = str1;
        longstr = str2;
    }
    else {
        shortstr = str2;
        longstr = str1;
    }

    if (strstr(longstr, shortstr) != NULL)          //����ڽϳ����ַ������ҵ���С���ַ�����
    {                                               //�򷵻ض��ַ���
        return shortstr;
    }

    substr = (char *)malloc(sizeof(char)*(strlen(shortstr) + 1));//���� ���ڴ� ��ŷ��ؽ��
    //ѭ��ȡ�̴����Ӵ�������ڴ棬����strstr������鳤�����Ƿ��������Ӵ�������У��򷵻ض��ڴ档����̴����Ȳ��ϼ��ٵ�
    for (i = strlen(shortstr) - 1; i > 0; i--)
    {
        for (j = 0; j <= strlen(shortstr) - i; j++)
        {
            memcpy(substr, &shortstr[j], i);        //�����ַ�����һ���ָ��Ƶ�substr��
            substr[i] = '\0';                       //�䳤���𽥼�С
            if (strstr(longstr, substr) != NULL)    //�����lognstr���ҵ�substr���򷵻�substr
                return substr;
        }
    }

    return NULL;
}

int main()
{
    char *str1 = (char *)malloc(256);               //������ڴ����ַ���str1��str2
    char *str2 = (char *)malloc(256);
    char *common = NULL;

    gets_s(str1,20);                                //���ն�����str1��str2
    gets_s(str2,20);

    common = commonstring(str2, str1);              //ȡ������ͬ�Ӵ�

    printf("the longest common string is:%s\n", common);

    return 0;
}
