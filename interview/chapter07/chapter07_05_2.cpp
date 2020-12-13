#include <iostream>
using namespace std;

//抽象
struct Base {
public:
    virtual void Func1() = 0;           //纯虚函数
    virtual void Func2() = 0;           //纯虚函数

    void print() {
        Func1();                        //调用派生类的Fun1()
        Func2();                        //调用派生类的Fun2()
    }
};

struct T :private Base {
public:
    virtual void Func1() {              //覆盖基类的Fun1
        cout << "Func1" << endl;		//覆盖基类的Fun2
    }

    virtual void Func2() {
        cout << "Func2" << endl;
    }
    //调用基类的print()
    void UseFunc() {
        Base::print();
    }
};

int main()
{
    T t;
    t.UseFunc();
    return 0;
}
