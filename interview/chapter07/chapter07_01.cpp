#include <iostream>

using namespace std;

class Base
{
protected:
    void printProtected() {cout << "print Protected" << endl;}
public:
    void printPublic() {cout << "print Public" << endl;}
};

class Derived1: protected Base //protected�̳�
{

};

class Derived2: private Base  //private�̳�
{

};

class A: public Derived1
{
public:
    void print()
    {
        printProtected();
        printPublic();
    }
};

class B: public Derived2
{
public:
    void print()
    {
        //printProtected();  //������󣬲��ܷ���
        //printPublic();     //������󣬲��ܷ���
        cout << "print Derived2" << endl;
    }
};

int main()
{
    class A a;
    class B b;
    a.print();
    b.print();
    cout << "Hello World!" << endl;
    return 0;
}
