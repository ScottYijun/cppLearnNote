#include <iostream>
using namespace std;

int IsRevStr(char *str)
{
    int i, len;
    int found = 1;                              //1��ʾ�����ַ�����0��ʾ����

    if (str == NULL)                            //�ж�str����Ч��
    {
        return -1;
    }
    len = strlen(str);                          //��ȡ�ַ�������
    for (i = 0; i < len / 2; i++)
    {
        if (*(str + i) != *(str + len - i - 1)) //���������������Ӧ��ͷβ�ַ����ȣ����ַ������ǻ����ַ���
        {
            found = 0;
            break;
        }
    }
    return found;
}

int main()
{
    char str1[10] = "1234321";                  //�����ַ���
    char str2[10] = "1234221";                  //�ǻ����ַ���

    int test1 = IsRevStr(str1);                 //����str1�ǲ��ǻ���
    int test2 = IsRevStr(str2);                 //����str2�ǲ��ǻ���

    cout << "str1 is " << (test1 == 1 ? "" : " not") << " reverse string." << endl;
    cout << "str2 is " << (test2 == 1 ? "" : " not") << " reverse string." << endl;

    return 0;
}
