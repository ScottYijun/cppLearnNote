#include <iostream>
using namespace std;

int main()
{
    const char *str1 = "hello";
    const char *str2 = "china";
    char *str3 = NULL;
    //这边用new申请的堆内存没有被初始化
    str3 = new char[strlen(str1) + strlen(str2) + 1];
    str3[0] = '\n';       //上面的堆内存没有初始化，不含有字符串结束符，输出的是随机值。
    //str3[0] = '\0';         //str3[0]赋为结束符'\0'，以便strcat能正常调用。
    strcat(str3, str1);     //str3变为"hello"
    strcat(str3, str2);     //str3变为"hello china"
    cout << str3 << endl;

    return 0;
}
