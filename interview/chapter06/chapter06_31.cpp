#include <iostream>
using namespace std;

class Test
{
public:
    Test(): num(0) //默认构造函数,
    {
        //cout << "Constructor: this = " << this << ", num = " << num << endl;
    }
    Test(int number):num(number) //带参数的构造函数,
    {
        //cout << "Constructor:int this = " << this << ", num = " << num << endl;
    }
    void print()
    {
        cout << "num = " << num << endl;
    }
    ~Test() //析构函数，打印this指针和私有成员num
    {
        cout << "destructor: this = " << this << ", num = " << num << endl;
    }

private:
    int num;
};

void fun1(Test &test) //参数按值传递,
{
    //cout << "fun1()=====&test============" << &test << endl;
    test.print();
}

Test fun2()
{
    Test t(3);
    //cout << "fun2()=====&t============" << &t << endl;
    return t;           //返回值按值传递,
}

int main(int argc, char *argv[])
{
    Test t1(1);
    //cout << "&t1====0=========" << &t1 << endl;
    fun1(t1);   //对象传入,
    //fun1(2);    //整型数2传入,
    //cout << "&t1====1=========" << &t1 << endl;
    //t1 = fun2();
    //cout << "&t1====2=========" << &t1 << endl;
    return 0;
}


