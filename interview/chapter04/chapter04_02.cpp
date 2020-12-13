#include <iostream>
using namespace std;

void int2str(int n, char *str)          //这边n表示整数
{
    char buf[10] = "";
    int i = 0;
    int len = 0;
    int temp = n < 0 ? -n : n;          //temp为n的绝对值

    if (str == NULL)
    {
        return;
    }
    while (temp)
    {
        buf[i++] = (temp % 10) + '0';	//把temp的每一位上的数存入buf
        temp = temp / 10;
    }

    len = n < 0 ? ++i : i;              //如果n为负数，则多一位来存储负号
    str[i] = 0;                         //末尾是结束符0
    while (1)
    {
        i--;
        if (buf[len - i - 1] == 0)
        {
            break;
        }
        str[i] = buf[len - i - 1];      //把buff数组里的字符拷到字符串
    }
    if (i == 0)
    {
        str[i] = '-';                   //如果是负数，添加负号
    }
}

int main() {
    int nNum;
    char p[10];

    cout << "Please input an integer:";
    cin >> nNum;
    cout << "output: ";
    int2str(nNum, p);                   //整型数转换成字符串
    cout << p << endl;

    return 0;
}
