/*
 * 5. 给定一个 int 数据 M，判断其二进制中 1 是否连续。
 * 比如 ： M = 120 -> 0111 1000 true;
 * M=184->1011 1000 false.实现函数 bool check(int M)。
*/

#include <iostream>

using namespace std;

bool check(int M)
{
    while(M)
    {
        while((M & 1) == 0)
        {
            M >>= 1;
        }
        if((M & 3) != 3)
            return false;
        M >>= 2;
    }

    return true;
}

#if 0
int main()
{
    int num;
    cout << "请输入一个整数：";
    cin >> num;
    bool bRet = check(num);
    printf("%d->", num);
    char str[32] = {'\0'};
    itoa(num, str, 2);
    printf("%s", str);//输出二进制数

    if(bRet)
        cout << " 二进制中1连续    true" << endl;
    else
        cout << " 二进制中1不连续  false" << endl;

    return 0;
}

#endif


/*
运行结果：
请输入一个整数：120
120-> 1111000 二进制中1连续    true
请输入一个整数：184
184->10111000 二进制中1不连续  false
*/
