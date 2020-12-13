#include <iostream>
using namespace std;

void RevStr(char *src)
{
    char *start = src, *end = src, *ptr = src;

    while (*ptr++ != '\0')                      //遍历字符串
    {
        if (*ptr == ' ' || *ptr == '\0')        //找到一个单词
        {
            end = ptr - 1;                      //end指向单词末尾
            while (start < end)
                swap(*start++, *end--);         //把单词的字母逆置

            start = end = ptr + 1;              //指向下一个单词开头，单词之间间隔是空格不是'\0'
        }
    }
    start = src, end = ptr - 2;                 //start指向字符串开头,end指向字符串末尾
    while (start < end)                         //把整个字符串逆置
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
