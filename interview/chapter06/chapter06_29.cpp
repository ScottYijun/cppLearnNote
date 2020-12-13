#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "This is A Construction====this=" << this << endl;
    }
    virtual ~A()
    {
        cout << "This is A destruction======this=" << this << endl;
    }
    A(A &a)
    {
        cout << "This is A Copy Construction==&a=" << &a << endl;
    }
    A& operator =(const A &a)
    {
        cout << "This is an assignment function==&a=" << &a << " this=" << this << endl;
        return *this;
    }
};

A fun()
{
    A a;
    cout << "fun===============&a====" << &a << endl;
    return a;
}

int main()
{
    {
        A a;
        cout << "==&a=======1=========" << &a << endl;
        a = fun();
        cout << "==&a=======2=========" << &a << endl;
    }
    return 0;
}


