#include <stdio.h>
#include <assert.h>

int strlen1(const char* src)
{
    assert(NULL != src);                    //src������Ч
    int len = 0;                            //����src�׵�ַ
    while (*src++ != '\0')                  //����������'\0'ʱ�˳�ѭ��
        len++;                              //ÿѭ��һ�Σ�len��1
    return len;
}

int strlen2(const char* src)
{
    assert(NULL != src);                    //src������Ч
    const char *temp = src;                 //����src�׵�ַ
    while (*src++ != '\0');                 //����������'\0'ʱ�˳�ѭ��
    return (src - temp - 1);                //����β��ָ����ͷָ��֮�������
}

int main()
{
    char p[] = "Hello World!";
    printf("strlen1 len:%d\n", strlen1(p)); //��ӡ����1�õ��Ľ��
    printf("strlen2 len:%d\n", strlen2(p)); //��ӡ����2�õ��Ľ��

    return 0;
}
