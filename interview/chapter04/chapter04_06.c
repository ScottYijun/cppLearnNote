#include <stdio.h>
#include <assert.h>

void *memcpy2(void *memTo, const void *memFrom, size_t size)
{
    assert((memTo != NULL) && (memFrom != NULL));   //memTo��memFrom������Ч
    char *tempFrom = (char *)memFrom;               //����memFrom���׵�ַ
    char *tempTo = (char *)memTo;                   //����memTo���׵�ַ

    while (size-- > 0) {                            //ѭ��size�Σ�����memFrom��ֵ��memTo��
        *tempTo++ = *tempFrom++;
    }
    return memTo;
}

int main()
{
    char strSrc[] = "Hello World";                  //�������Ƶ��ַ�����
    char strDest[20];                               //Ŀ���ַ�����

    memcpy2(strDest, strSrc, 4);                    //����strSrc��ǰ4���ַ���strDest��
    strDest[4] = '\0';                              //��strDest�ĵ�5��Ԫ�ظ�Ϊ������'\0'
    printf("strDest:%s\n", strDest);

    return 0;
}

