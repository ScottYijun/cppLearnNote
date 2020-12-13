#include <iostream>
using namespace std;

//�ⷨ1:��һ�������һ������������
char* strrev1(const char* str)
{
    int len = strlen(str);
    char* tmp = new char[len + 1];
    strcpy(tmp, str);
    for (int i = 0; i < len / 2; ++i)
    {
        char c = tmp[i];
        tmp[i] = tmp[len - i - 1];
        tmp[len - i - 1] = c;
    }
    return tmp;
}

//�ⷨ2��ָ����ʽ
char* strrev2(const char* str)
{
    char* tmp = new char[strlen(str) + 1];
    strcpy(tmp,str);
    char* ret = tmp;
    char* p = tmp + strlen(str) - 1;

    while (p > tmp)
    {
        char t = *tmp;
        *tmp = *p;
        *p = t;

        --p;
        ++tmp;
    }
    return ret;
}

//�ⷨ3���Ż���ʹ������Ż�
char* strrev3(const char* str)
{
    char* tmp = new char[strlen(str) + 1];
    strcpy(tmp, str);
    char* ret = tmp;
    char* p = tmp + strlen(str) - 1;

    while (p > tmp)
    {
        *p ^= *tmp;
        *tmp ^= *p;
        *p ^= *tmp;

        --p;
        ++tmp;
    }
    return ret;
 }

//�ⷨ4
char* strrev4(const char* str)
{
    char* tmp = new char[strlen(str) + 1];
    strcpy(tmp, str);
    char* ret = tmp;
    char* p = tmp + strlen(str) - 1;

    while (p > tmp)
    {
        *p = *p + *tmp;
        *tmp = *p - *tmp;
        *p = *p - *tmp;

        --p;
        ++tmp;
    }
    return ret;
}

//�ⷨ5:ʹ�õݹ�
char* strrev5(char* str, int len)
{
    if (len <= 1)
        return str;

    char t = *str;
    *str = *(str + len - 1);
    *(str + len - 1) = t;

    return (strrev5(str + 1, len - 2) - 1);
}

int main(int argc, char *argv[])
{
    const char *str = "123456";//C++�������const char*��ʼ��Ϊchar*
    cout << "str = " << str << endl;

    char *str2 = strrev1(str);
    cout << "str2= " << str2 << endl;

    char *str3 = strrev2(str2);
    cout << "str3= " << str3 << endl;

    char *str4 = strrev3(str3);
    cout << "str4= " << str4 << endl;

    char *str5 = strrev4(str4);
    cout << "str5= " << str5 << endl;

    char *str6 = strrev5(str5, strlen(str5));
    cout << "str6= " << str6 << endl;

    return 0;
}
