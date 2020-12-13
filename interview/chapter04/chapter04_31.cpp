#include <iostream>
using namespace std;
//str为原字符串，sub1:为第2个字符串，sub2为第3个字符串，output为结果
char *replace(const char *str, const char *sub1, const char *sub2, char *output)
{
    char *pOutput = NULL;
    const char *pStr = NULL;
    int lenSub1 = strlen(sub1);                 //子串sub1的长度
    int lenSub2 = strlen(sub2);                 //子串sub2的长度

    pOutput = output;
    pStr = str;                                 //用于寻找子串
    while (*pStr != 0)
    {
        pStr = strstr(pStr, sub1);              //在str中寻找sub1子串
        if (pStr != NULL)                       //找到sub1子串
        {
            memcpy(pOutput, str, pStr - str);	//复制str的前一部分output
            pOutput += pStr - str;
            memcpy(pOutput, sub2, lenSub2);     //复制sub2子串到output
            pOutput = pOutput + lenSub2;
            pStr = pStr + lenSub1;              //为了下一次复制做准备
            str = pStr;
        }
        else                                    //找不到sub1子串
        {
            break;
        }
    }
    *pOutput = '\0';
    if (*str != '\0')
    {
        strcpy(pOutput, str);                   //复制str剩余部分到output
    }

    return output;
}

int main()
{
    char str[50] = "";                          //源字符串str
    char sub1[10] = "";                         //被替换的字符串sub1
    char sub2[10] = "";                         //用来替换sub2
    char output[100] = "";                      //输出字符串

    cout << "str:";
    cin >> str;
    cout << "sub1:";
    cin >> sub1;
    cout << "sub2:";
    cin >> sub2;

    cout << replace(str, sub1, sub2, output) << endl;

    return 0;
}
