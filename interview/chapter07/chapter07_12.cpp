#include <iostream>
using namespace std;

class Person
{
public:
    void sleep() {cout << "sleep" << endl;}
    void eat() {cout << "eat" << endl;}
};

class Author: virtual public Person //Author虚继承自Person
{
public:
    void writeBook() {cout << "write Book" << endl;}
};

class Programmer: virtual public Person //Programmer虚继承自Person
{
public:
    void writeCode() {cout << "write Code" << endl;}
};

class Programmer_Author: public Programmer, public Author//多重继承
{

};

int main()
{
    Programmer_Author pa;
    pa.writeBook();//调用基类Author的方法
    pa.writeCode();//调用基类Programmer的方法
    pa.eat();       //编译错误，eat()定义不明确
    pa.sleep();     //编译错误，sleep()定义不明确

    return 0;
}
