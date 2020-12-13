#include <iostream>
using namespace std;
class A
{
private:
    int a;
public:
    A(int aa) { a = aa; }
    ~A() {cout << "Destructor A!======" << a << endl;}
};

class B: public A
{
private:
    int b;

public:
    B(int aa = 0, int bb = 0): A(aa) {b = bb;}
    ~B() {cout << "Destructor B!======" << b <<endl;}
};

int main()
{
    B obj1(5), obj2(6, 7);
    return 0;
}

