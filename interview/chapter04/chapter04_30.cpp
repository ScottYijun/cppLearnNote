#include <iostream>
using namespace std;

void Calculate(const char *str, int *max0, int *max1)
{
    int temp0 = 0;                          //保存连续是'0'的最大长度
    int temp1 = 0;                          //保存连续是'1'的最大长度

    while (*str)                            //遍历字符串
    {
        if (*str == '0')                    //当前字符为‘0’
        {
            (*max0)++;                      //‘0’的计算长度加1
            if (*(++str) == '1')            //如果下一个字符是'1'
            {
                if (temp0 < *max0)          //判断当前最大长度是否需要保存
                {
                    temp0 = *max0;
                }
                *max0 = 0;
            }
        }
        else if (*str == '1')               //当前字符是‘1’
        {
            (*max1)++;                      //‘1’的计算长度加1
            if (*(++str) == '0')            //如果下一个字符是‘0’
            {
                if (temp1 < *max1)          //判断当前最大长度是否需要保存
                {
                    temp1 = *max1;
                }
                *max1 = 0;
            }
        }
    }

    *max0 = temp0;                          //‘0’的最大长度返回max0
    *max1 = temp1;                          //‘1’的最大长度返回max1
}

int main()
{
    char string[] = "00001110110000001100110101101001010101011111010";

    int max0 = 0;                           //保存连续是'0'的最大长度
    int max1 = 0;                           //保存连续是'1'的最大长度

    Calculate(string, &max0, &max1);
    cout << "max0 = " << max0 << endl;
    cout << "max1 = " << max1 << endl;

    return 0;
}

