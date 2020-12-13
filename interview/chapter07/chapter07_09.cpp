#include <iostream>
using namespace std;

class A {
public:
    virtual void print(void)
    {
        cout << " A::print()" << endl;
    }
};

class B :public A {
public:
    virtual void print(void)
    {
        cout << " B::print()" << endl;
    }
};

class C :public A {
public:
    void print(void)
    {
        cout << " C::print()" << endl;
    }
};

void print(A a) {
    a.print();
}

int main() {
    A a;
    B b;
    C c;
    A *pa, *pb, *pc;
    pa = &a;
    pb = &b;
    pc = &c;

    a.print();
    b.print();
    c.print();
    //上面都是自己类中的成员函数,在构造函数中，虚拟机制不会发生作用
    pa->print();
    pb->print();
    pc->print();

    print(a);
    print(b);
    print(c);

    return 0;
}
