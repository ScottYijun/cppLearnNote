#include <iostream>
using namespace std;

void RevStr(char *src)
{
    char *start = src, *end = src, *ptr = src;

    while(*ptr++ != '\0');
    end = ptr - 2;                      //�ҵ��ַ���ĩβ
    while (start < end)
    {
        swap(*start++, *end--);         //���������ַ���
    }

    start = src, end = ptr - 2;
    ptr = start;
    while (*ptr++ != '\0')
    {
        if(*ptr == ' ' || *ptr == '\0') //�ҵ�����
        {
            end = ptr - 1;              //endָ�򵥴�ĩβ
            while(start < end)
                swap(*start++, *end--); //���õ���

            start = end = ptr + 1;      //ָ����һ�����ʿ�ͷ
        }
    }
}

int main()
{
    char src[] = "I am from Shanghai";
    cout << src << "\n";
    RevStr(src);
    cout << src << "\n";

    return 0;
}
