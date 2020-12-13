/*
 * 2. 打开微信，设置-->账号与安全-->声音锁-->开始。屏幕中会出现一个八位数字。观察数字
 * 规律（可多次点击开始），请用代码批量实现有同样规律的数字。
*/
#include <iostream>
#include <random>

#define COUNT 10

using namespace std;
#if 0
int main()
{
    uniform_int_distribution<unsigned> u(10000000, 99999999);   //设置8位数的范围
    default_random_engine rand8Bit;                             //使用随机数引擎生成8位随机数
    for(auto i = 0; i < COUNT; ++i)
    {
        cout << "8位随机数生成:" << u(rand8Bit) << endl;
    }

    return 0;
}
#endif

/*
运行结果：
8位随机数生成:89211612
8位随机数生成:51869302
8位随机数生成:30346734
8位随机数生成:86334585
8位随机数生成:15404204
8位随机数生成:31255391
8位随机数生成:62919429
8位随机数生成:59333985
8位随机数生成:25962298
8位随机数生成:73567403
*/
