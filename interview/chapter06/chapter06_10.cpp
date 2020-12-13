#include <iostream>

using namespace std;

class A             //A是父类
{
private:
    int a;          //private成员
public:
    A() {}
    A(int x):a(x) {} //带参数的构造函数对a初始化
    void printA()
    {
        cout << " a = " << a << endl;
    }
};

class B: public A //B是子类
{
private:
    int b;
public:
    B(int x, int y): A(x)       //需要初始化b以及父类的a
    {
        //a = x;                  //a为private,无法在子类中被访问，编译错误
        //A(x);                   //调用方式错误，编译错误
        b = y;
    }
    void printB() //打印b的值
    {
        cout << " b = " << b << endl;
    }
};

int main()
{
    B b(2, 3);
    b.printA();     //调用子类的printA()
    b.printB();     //调用自已的printB()

    return 0;
}
