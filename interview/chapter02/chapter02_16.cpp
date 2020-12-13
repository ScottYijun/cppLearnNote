#include <iostream>
using namespace std;

class A
{
};

class B
{
};

class C: public A, public B
{
};

class D: virtual public A
{
};

class E: virtual public A, virtual public B
{
};

class F
{
public:
    int a;
    static int b;
};

int F::b = 10;

int main()
{
    cout << "sizeof(A)=======" << sizeof(A) << endl;
    cout << "sizeof(B)=======" << sizeof(B) << endl;
    cout << "sizeof(C)=======" << sizeof(C) << endl;
    cout << "sizeof(D)=======" << sizeof(D) << endl;
    cout << "sizeof(E)=======" << sizeof(E) << endl;
    cout << "sizeof(F)=======" << sizeof(F) << endl;

    int a = 10;
    cout << "sizeof(a)=======" << sizeof a << endl;
    return 0;
}

