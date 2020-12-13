#include <iostream>
using namespace std;

class MyClass
{
public:
    int data;
    MyClass(int data)
    {
        this->data = data;
    }
    void print()
    {
        cout << data << endl;
        cout << "hello!" << endl;
    }
};

int main()
{
    MyClass *pMyClass;
    pMyClass = new MyClass(1);
    pMyClass->print();
    pMyClass[0].print();
    pMyClass[1].print();
    pMyClass[1000000].print();

    return 0;
}
