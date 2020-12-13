#include <iostream>
using namespace std;

class Test
{
public:
    int a;
    Test(int x)
    {
        a = x;
    }
    Test(const Test &test)        //复制构造函数,
    {
        cout << "copy constructor====" << this << "  &test==" << &test << endl;
        a = test.a;
    }
};

void fun1(Test test)            //(1)值传递传入函数体,
{
    cout << "fun1()...&test==" << &test << endl;
}

Test fun2()                 //(2)值传递从函数体返回,
{
    Test t(2);
    cout << "fun2(),,,,&t===" << &t << endl;
    return t;
}

int main()
{
    Test t1(1); //cout << "&t1=========" << &t1 << endl;
    Test t2 = t1;       //(3)用t1对t2做初始化,
    cout << "before fun1()...&t1=" << &t1 << "  &t2==" << &t2 << endl << endl;
    fun1(t1);
    cout << endl;
    Test t3 = fun2();
    cout << "after fun2()..&t3====" << &t3 << endl;
    return 0;
}
