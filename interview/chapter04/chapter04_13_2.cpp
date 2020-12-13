#include <iostream>
using namespace std;

void RevStr(char *src)
{
    char *start = src, *end = src, *ptr = src;

    while(*ptr++ != '\0');
    end = ptr - 2;                      //找到字符串末尾
    while (start < end)
    {
        swap(*start++, *end--);         //逆置整个字符串
    }

    start = src, end = ptr - 2;
    ptr = start;
    while (*ptr++ != '\0')
    {
        if(*ptr == ' ' || *ptr == '\0') //找到单词
        {
            end = ptr - 1;              //end指向单词末尾
            while(start < end)
                swap(*start++, *end--); //逆置单词

            start = end = ptr + 1;      //指向下一个单词开头
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
