#include <iostream>
using namespace std;
//���ַ���ת��Ϊ����
int str2int(const char *str)
{
    int temp = 0;
    const char *ptr = str;                  //ptr����str�ַ�����ͷ

    if (*str == '-' || *str == '+')         //�����һ���ַ��������ţ����Ƶ���һ���ַ�
    {
        str++;
    }
    while (*str != 0)
    {
        if ((*str < '0') || (*str > '9'))   //�����ǰ�ַ��������֣����˳�ѭ��
        {
            break;
        }
        temp = temp * 10 + (*str - '0');	//�����ǰ�ַ������֣��������ֵ��
        str++;                              //�Ƶ���һ���ַ�
    }
    if (*ptr == '-')                        //����ַ�����'-'��ͷ���򻻳��෴��
    {
        temp = -temp;
    }

    return temp;
}

int main()
{
    int n = 0;
    char p[10] = "";

    cin.getline(p, 20);                     //���ն˻�ȡһ���ַ���
    n = str2int(p);                         //���ַ���ת����������

    cout << n << endl;

    return 0;
}
