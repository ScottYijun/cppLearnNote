#include <stdio.h>

int main()
{
    int ival    = 1024;
    int ival2   = 2048;
    int *pi1    = &ival;
    int *pi2    = &ival2;
    int **pi3   = 0;

    ival    = *pi3; //�������ival��int�ͣ�*pi3�� int*���ͣ�������ʽת��
    *pi2    = *pi3; //�������*pi2��int�ͣ�*pi3�� int*���ͣ�������ʽת��
    ival    = pi2;  //�������ival��int�ͣ�pi2�� int*���ͣ�������ʽת��
    pi2     = *pi1; //�������pi2��int*�ͣ�*pi1�� int���ͣ�������ʽת��
    pi1     = *pi3; //����ʱ����pi3��NULLָ�룬��ͼ�õ�*pi3��ֵ�ᷢ�����д���
    ival    = *pi1;
    pi1     = ival; //�������pi1��int*�ͣ�ival�� int���ͣ�������ʽת��
    pi3     = &pi2;

    return 0;
}











