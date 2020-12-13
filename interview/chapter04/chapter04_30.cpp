#include <iostream>
using namespace std;

void Calculate(const char *str, int *max0, int *max1)
{
    int temp0 = 0;                          //����������'0'����󳤶�
    int temp1 = 0;                          //����������'1'����󳤶�

    while (*str)                            //�����ַ���
    {
        if (*str == '0')                    //��ǰ�ַ�Ϊ��0��
        {
            (*max0)++;                      //��0���ļ��㳤�ȼ�1
            if (*(++str) == '1')            //�����һ���ַ���'1'
            {
                if (temp0 < *max0)          //�жϵ�ǰ��󳤶��Ƿ���Ҫ����
                {
                    temp0 = *max0;
                }
                *max0 = 0;
            }
        }
        else if (*str == '1')               //��ǰ�ַ��ǡ�1��
        {
            (*max1)++;                      //��1���ļ��㳤�ȼ�1
            if (*(++str) == '0')            //�����һ���ַ��ǡ�0��
            {
                if (temp1 < *max1)          //�жϵ�ǰ��󳤶��Ƿ���Ҫ����
                {
                    temp1 = *max1;
                }
                *max1 = 0;
            }
        }
    }

    *max0 = temp0;                          //��0������󳤶ȷ���max0
    *max1 = temp1;                          //��1������󳤶ȷ���max1
}

int main()
{
    char string[] = "00001110110000001100110101101001010101011111010";

    int max0 = 0;                           //����������'0'����󳤶�
    int max1 = 0;                           //����������'1'����󳤶�

    Calculate(string, &max0, &max1);
    cout << "max0 = " << max0 << endl;
    cout << "max1 = " << max1 << endl;

    return 0;
}

