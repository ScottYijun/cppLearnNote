#include <iostream>
using namespace std;

int mystrcmp(const char *src, const char *dst)
{
    int ret = 0;
    while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
    {                                   //循环比较两个字符是否相等,
        ++src;                          //如果不等或者到了dst字符的末尾，
        ++dst;                          //则退出循环
    }
    if (ret < 0)                        //ret保存着字符比较的结果
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

    int test1 = mystrcmp(str, str1);    //测试str与str1比较
    int test2 = mystrcmp(str, str2);    //测试str与str2比较
    int test3 = mystrcmp(str, str3);    //测试str与str3比较

    cout << "test1= " << test1 << endl;
    cout << "test2= " << test2 << endl;
    cout << "test3= " << test3 << endl;

    return 0;
}
