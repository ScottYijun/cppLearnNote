#include <iostream>

using namespace std;

class Base
{
protected:
    void printProtected() {cout << "print Protected" << endl;}
public:
    void printPublic() {cout << "print Public" << endl;}
};

class Derived1: protected Base //protected¼Ì³Ð
{

};

class Derived2: private Base  //private¼Ì³Ð
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
        //printProtected();  //±àÒë´íÎó£¬²»ÄÜ·ÃÎÊ
        //printPublic();     //±àÒë´íÎó£¬²»ÄÜ·ÃÎÊ
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
