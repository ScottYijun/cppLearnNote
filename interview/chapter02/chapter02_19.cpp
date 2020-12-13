#include <iostream>
#include <string>

void UpperCase(char str[])
{
    int test = sizeof(str);
    int test2 = sizeof(str[0]);

    for(size_t i = 0; i < strlen(str); ++i)//计算字符串的长度
        if('a' <= str[i] && str[i] <= 'z')
            str[i] -= ('a' - 'A');
}

int main()
{
    char str[] = "aBcDe";
    std::cout << "The length of str is " << strlen(str) << std::endl;//计算字符串的长度
    UpperCase(str);
    std::cout << str << std::endl;
    return 0;
}











