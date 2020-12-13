#include <iostream>
using namespace std;

class A
{
private:
    int num;
public:
    A()
    {
        cout << "Default constructor======" << endl;
    }
    ~A()
    {
        cout << "Desconstructor=====num===" << num << endl;
    }
    A(const A &a)
    {
        cout << "Copy constructor=========" << endl;
    }
    void operator=(const A &a)
    {
        cout << "Overload operator==========" << endl;
    }
    void setNum(int n)
    {
        num = n;
    }
};

int main()
{
    A a1;
    A a2(a1);
    A a3 = a1;
    A &a4 = a1;
    a1.setNum(1);
    a2.setNum(2);
    a3.setNum(3);
    a4.setNum(4);
    return 0;
}




