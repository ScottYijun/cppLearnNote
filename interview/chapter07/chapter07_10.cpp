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
    Derived d;	//���� Derived ����d�����ȵ��� Base �Ĺ��캯����Ȼ����� Derived �Ĺ��캯����
    //�� Base ��Ĺ��캯�����ֵ������麯�� virt()

    Base *pB = &d;
    pB->f();

    return 0;
}
