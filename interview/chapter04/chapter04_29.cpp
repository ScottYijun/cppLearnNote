#include <iostream>
using namespace std;

int gbk_strlen(const char *str)
{
    const char *p = str;                                //头节点，p也用于后面的遍历
                                                        //使用两个指针指向的地址之差来获取字符串长度
    while (*p)                                          //若是结束符0，则结束循环
    {
                                                        //汉字编码为双字节，其中首字节<0，尾字节在0~63以外
        if (*p < 0 && (*(p + 1) < 0 || *(p + 1) > 63))  //中文汉字情况
        {
            str++;                                      //str移动一位，p移动两位，因此长度+1
            p = p + 2;
        }
        else
        {
            p++;                                        //str不动，p移动一位，长度加1
        }
    }
    return p - str;                                     //返回地址之差
}

int main()
{
    char str[] = "abc你好123中国456";
    int len = gbk_strlen(str);
    cout << str << endl;
    cout << "len = " << len << endl;

    return 0;
}
