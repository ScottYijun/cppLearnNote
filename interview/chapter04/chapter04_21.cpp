#include <iostream>
using namespace std;

//解法1:第一个和最后一个交换，依次
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

//解法2：指针形式
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

//解法3，优化，使用异或优化
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

//解法4
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

//解法5:使用递归
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
    const char *str = "123456";//C++不充许从const char*初始化为char*
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
