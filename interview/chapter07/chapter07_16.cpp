#include <iostream>
#include <memory.h>
#include <assert.h>
using namespace std;

class Animal
{
public:
    virtual void sleep() = 0;//纯虚函数，必须在派生类被定义
    virtual void eat() = 0;//纯虚函数，必须在派生类被定义
};

class Tiger: public Animal
{
public:
    void sleep() {cout << "Tiger sleep" << endl;}
    void eat() {cout << "Tiger eat" << endl;}
};

class Lion: public Animal
{
public:
    void sleep() {cout << "Lion sleep" << endl;}
    void eat() {cout << "Lion eat" << endl;}
};

int main()
{
    Animal *p;      //Animal指针，不能使用Animal animal定义对象
    Tiger tiger;
    Lion lion;

    p = &tiger;     //指向Tiger对象
    p->sleep();     //调用Tiger::sleep()
    p->eat();       //调用Tiger::eat()
    p = &lion;      //指向Lion对象
    p->sleep();     //调用Lion::sleep()
    p->eat();       //调用Lion::eat()
    return 0;
}
