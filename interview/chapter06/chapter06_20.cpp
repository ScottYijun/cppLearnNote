#include <iostream>
using namespace std;

class Base
{
public:
    Base() {} //Base的构造函数,
    virtual ~Base()   //Base的析构函数,
    {
        cout << "Output from the destructor of class Base!" << endl;
    }
    virtual void DoSomething()
    {
        cout << "Do something in class Base!" << endl;
    }
};

class Derived: public Base
{
public:
    Derived() {} //Derived的构造函数,
    ~Derived()   //Derived的析构函数,
    {
        cout << "Output from the destructor of class Derived!" << endl;
    }
    virtual void DoSomething()
    {
        cout << "Do something in class Derived!" << endl;
    }
};

int main()
{
    Derived *pTest1 = new Derived();//Derived类的指针,
    pTest1->DoSomething();
    delete pTest1;

    cout << endl;

    Base *pTest2 = new Derived();   //Base类的指针,
    pTest2->DoSomething();
    delete pTest2;

    return 0;
}
