#include <iostream>
using namespace std;

class Test
{
public:
    void f(const int& arg);
private:
    int value;
};

void Test::f(const int &arg)
{
    //arg = 10;//arg是常引用，值不能被修改
    cout << "arg = " << arg << endl;
    value = 20;
}

int main()
{
    int a = 7;
    const int b = 10;
    //int &c = b;//b是常量类型，不能赋给非常量的引用
    const int &d = a;

    a++;
    //d++;//不能使用常量引用修改变量的值

    Test test;
    test.f(a);
    cout << "a = " << a << endl;
    return 0;
}
