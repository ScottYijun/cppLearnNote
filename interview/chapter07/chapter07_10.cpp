#include <iostream>
#include <string>
using namespace std;

void println(const string& msg) {
    cout << msg << '\n';
}

class Base {
public:
    Base() {
        println(" Base::Base()");
        virt();
    }

    void f() {
        println(" Base::f()");
        virt();
    }

    virtual void virt() {
        println(" Base::virt()");
    }
};

class Derived :public Base {
public:
    Derived() {
        println(" Derived::Derived()");
        virt();
    }

    virtual void virt() {
        println(" Derived::virt()");
    }
};

int main() {
    Derived d;	//构造 Derived 对象d，首先调用 Base 的构造函数，然后调用 Derived 的构造函数，
    //在 Base 类的构造函数，又调用了虚函数 virt()

    Base *pB = &d;
    pB->f();

    return 0;
}
