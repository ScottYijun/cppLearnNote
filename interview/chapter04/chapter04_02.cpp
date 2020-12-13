#include <iostream>
using namespace std;

void int2str(int n, char *str)          //���n��ʾ����
{
    char buf[10] = "";
    int i = 0;
    int len = 0;
    int temp = n < 0 ? -n : n;          //tempΪn�ľ���ֵ

    if (str == NULL)
    {
        return;
    }
    while (temp)
    {
        buf[i++] = (temp % 10) + '0';	//��temp��ÿһλ�ϵ�������buf
        temp = temp / 10;
    }

    len = n < 0 ? ++i : i;              //���nΪ���������һλ���洢����
    str[i] = 0;                         //ĩβ�ǽ�����0
    while (1)
    {
        i--;
        if (buf[len - i - 1] == 0)
        {
            break;
        }
        str[i] = buf[len - i - 1];      //��buff��������ַ������ַ���
    }
    if (i == 0)
    {
        str[i] = '-';                   //����Ǹ�������Ӹ���
    }
}

int main() {
    int nNum;
    char p[10];

    cout << "Please input an integer:";
    cin >> nNum;
    cout << "output: ";
    int2str(nNum, p);                   //������ת�����ַ���
    cout << p << endl;

    return 0;
}
