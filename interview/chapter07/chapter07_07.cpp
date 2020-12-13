#include <iostream>

using namespace std;

class Parent {
public:
    virtual void foo1() {}
    virtual void foo2() {}
};

class Child1:public Parent {
public:
    void foo1() {
        cout << "Child1======foo1()" << endl;
    }
    void foo3();
};

class Child2:public Parent {
public:
    void foo1() {
        cout << "Child1======foo1()" << endl;
    }
    void foo2() {
        cout << "Child1======foo2()" << endl;
    }
    void foo3();
};

class Child3{
public:
    void foo1() {
        cout << "Child3======foo1()" << endl;
    }
    void foo2() {
        cout << "Child3======foo2()" << endl;
    }
    void foo3();
};

int main()
{
    cout << " sizeof(Parent) ====" << sizeof(Parent) << endl;
    cout << " sizeof(Child1) ====" << sizeof(Child1) << endl;
    cout << " sizeof(Child2) ====" << sizeof(Child2) << endl;
    cout << " sizeof(Child3) ====" << sizeof(Child3) << endl;
    return 0;
}
