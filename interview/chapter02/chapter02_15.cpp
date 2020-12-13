#include <iostream>
using namespace std;

class Base
{
public:
    Base(int x): a(x)
    {
    }

    void print()
    {
        cout << "print ====== base===a=" << a << endl;
    }
private:
    int a;
};

class Derived: public Base
{
public:
    Derived(int x):Base(x - 1), b(x)
    {
    }

    void print()
    {
        cout << "print ====== derived===b=" << b << endl;
    }
private:
    int b;
};

class A
{
public:
    A(int x): a(x)
    {
    }
    virtual void print()
    {
        cout << "print ====== A===a=" << a << endl;
    }
private:
    int a;
};

class B: public A
{
public:
    B(int x):A(x - 1), b(x)
    {
    }
    virtual void print()
    {
        cout << "print ====== B===b=" << b << endl;
    }
private:
    int b;
};

int main()
{
    Base obj1(1);
    cout << "sizeof Base obj is " << sizeof(obj1) << endl;
    Derived obj2(2);
    cout << "sizeof Derived obj is " << sizeof(obj2) << endl;

    A a(1);
    cout << "sizeof A obj is " << sizeof(a) << endl;
    B b(2);
    cout << "sizeof B obj is " << sizeof(b) << endl;

    return 0;
}







