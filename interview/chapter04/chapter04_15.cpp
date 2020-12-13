#include <iostream>
using namespace std;

int mystrcmp(const char *src, const char *dst)
{
    int ret = 0;
    while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
    {                                   //ѭ���Ƚ������ַ��Ƿ����,
        ++src;                          //������Ȼ��ߵ���dst�ַ���ĩβ��
        ++dst;                          //���˳�ѭ��
    }
    if (ret < 0)                        //ret�������ַ��ȽϵĽ��
        ret = -1;
    else if (ret > 0)
        ret = 1;
    return ret;
}

int main()
{
    char str[10] = "1234567";
    char str1[10] = "1234567";          //str1==str
    char str2[10] = "12345678";         //str2 > str1
    char str3[10] = "1234566";          //str3 < str

    int test1 = mystrcmp(str, str1);    //����str��str1�Ƚ�
    int test2 = mystrcmp(str, str2);    //����str��str2�Ƚ�
    int test3 = mystrcmp(str, str3);    //����str��str3�Ƚ�

    cout << "test1= " << test1 << endl;
    cout << "test2= " << test2 << endl;
    cout << "test3= " << test3 << endl;

    return 0;
}
