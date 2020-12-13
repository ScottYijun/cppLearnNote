#include <iostream>
#include <complex>
using namespace std;
class Base {
public:
    Base() { cout << "Base-ctor " << endl;    }
    ~Base() { cout << "Base-dtor " << endl;    }
    virtual void f(int) { cout << "Base::f(int) " << endl;    }
    virtual void f(double) { cout << "Base::f(double) " << endl;    }
    virtual void g(int i = 10) { cout << "Base::g() " << endl;    }
};

class Derived :public Base {
public:
    Derived() {cout << "Derived-ctor " << endl;}
    ~Derived() {cout << "Derived-dctor " << endl;}
    void f(complex<double> c) {cout << "Derived::f(complex)" << endl;}
    virtual void g(int i = 20) {cout << "Base::g() " << i << endl; }
};

int main() {
    Base b;
    Derived d;	//构造 Derived 对象d，首先调用 Base 的构造函数，然后调用 Derived 的构造函数，
    Base *pb = new Derived();
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    pb->f(1.0);
    pb->g();
    return 0;
}
