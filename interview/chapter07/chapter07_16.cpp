#include <iostream>
#include <memory.h>
#include <assert.h>
using namespace std;

class Animal
{
public:
    virtual void sleep() = 0;//���麯���������������౻����
    virtual void eat() = 0;//���麯���������������౻����
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
    Animal *p;      //Animalָ�룬����ʹ��Animal animal�������
    Tiger tiger;
    Lion lion;

    p = &tiger;     //ָ��Tiger����
    p->sleep();     //����Tiger::sleep()
    p->eat();       //����Tiger::eat()
    p = &lion;      //ָ��Lion����
    p->sleep();     //����Lion::sleep()
    p->eat();       //����Lion::eat()
    return 0;
}
