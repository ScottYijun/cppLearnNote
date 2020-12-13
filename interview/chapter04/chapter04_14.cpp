#include <iostream>
using namespace std;

int IsRevStr(char *str)
{
    int i, len;
    int found = 1;                              //1表示回文字符串，0表示不是

    if (str == NULL)                            //判断str的有效性
    {
        return -1;
    }
    len = strlen(str);                          //获取字符串长度
    for (i = 0; i < len / 2; i++)
    {
        if (*(str + i) != *(str + len - i - 1)) //遍历中如果发现相应的头尾字符不等，则字符串不是回文字符串
        {
            found = 0;
            break;
        }
    }
    return found;
}

int main()
{
    char str1[10] = "1234321";                  //回文字符串
    char str2[10] = "1234221";                  //非回文字符串

    int test1 = IsRevStr(str1);                 //测试str1是不是回文
    int test2 = IsRevStr(str2);                 //测试str2是不是回文

    cout << "str1 is " << (test1 == 1 ? "" : " not") << " reverse string." << endl;
    cout << "str2 is " << (test2 == 1 ? "" : " not") << " reverse string." << endl;

    return 0;
}
