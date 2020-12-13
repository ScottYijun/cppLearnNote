#include <stdio.h>

char *strcpy(char *strDest, const char * strSrc)    //ʵ��strSrc��strDest�ĸ���
{
    if ((strDest == NULL) || (strSrc == NULL))      //�жϲ���strDest��strSrc��Ч�ԣ��Ƿ�Ϊ��
    {
        return NULL;
    }
    char *strDestCopy = strDest;                    //����Ŀ���ַ������׵�ַ
    while ((*strDest++ = *strSrc++) != '\0')        //��strSrc�ַ��������ݸ��Ƶ�strDest��
        ;
    return strDestCopy;
}

int getStrLen(const char *strSrc)                   //ʵ�ֻ�ȡstrSrc�ַ����ĳ���
{
    int len = 0;                                    //���泤��
    while (*strSrc++ != '\0')                       //ѭ��ֱ������������'\0'Ϊֹ
    {
        len++;
    }
    return len;
}

int main()
{
    char strSrc[] = "Hello World";                  //Ҫ�����Ƶ�Դ�ַ���
    char strDest[20];                               //Ҫ���Ƶ���Ŀ���ַ�����
    int len = 0;                                    //����Ŀ���ַ��������ַ��ĳ���

    len = getStrLen(strcpy(strDest, strSrc));       //��ʽ���ʽ���ȸ����ټ��㳤��
    printf("strDest:%s\n", strDest);
    printf("Length of strDest:%d\n", len);

    return 0;
}
