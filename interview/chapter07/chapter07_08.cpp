#include <stdio.h>

class A {
public:
    A() {
        doSth();	//���캯�������麯��
    }

    virtual void doSth() {
        printf("I am A");
    }
};

class B :public A {
public:
    virtual void doSth() {
        printf("I am B");
    }
};

int main() {
    B b;
    return 0;
}
