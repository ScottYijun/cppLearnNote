#include <iostream>
using namespace std;

struct Test
{
    Test(int a) {cout << "a=======" << a << endl;}
    Test() {cout << "call no-argument constructor=========" << endl;}
    void fun() {cout << "call fun()===========" << endl;}
};

int main()
{
    Test a(1);
    a.fun();
    Test b;//Test b() 调用不带参数的构造函数时，不需要加()
    b.fun();
    return 0;
}
