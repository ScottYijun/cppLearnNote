#include <iostream>
#include <string>

void UpperCase(char str[])
{
    int test = sizeof(str);
    int test2 = sizeof(str[0]);

    for(size_t i = 0; i < strlen(str); ++i)//�����ַ����ĳ���
        if('a' <= str[i] && str[i] <= 'z')
            str[i] -= ('a' - 'A');
}

int main()
{
    char str[] = "aBcDe";
    std::cout << "The length of str is " << strlen(str) << std::endl;//�����ַ����ĳ���
    UpperCase(str);
    std::cout << str << std::endl;
    return 0;
}











