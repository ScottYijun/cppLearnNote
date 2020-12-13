#include <iostream>
using namespace std;

void RevStr(char *src)
{
    char *start = src, *end = src, *ptr = src;

    while (*ptr++ != '\0')                      //�����ַ���
    {
        if (*ptr == ' ' || *ptr == '\0')        //�ҵ�һ������
        {
            end = ptr - 1;                      //endָ�򵥴�ĩβ
            while (start < end)
                swap(*start++, *end--);         //�ѵ��ʵ���ĸ����

            start = end = ptr + 1;              //ָ����һ�����ʿ�ͷ������֮�����ǿո���'\0'
        }
    }
    start = src, end = ptr - 2;                 //startָ���ַ�����ͷ,endָ���ַ���ĩβ
    while (start < end)                         //�������ַ�������
    {
        swap(*start++, *end--);
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
