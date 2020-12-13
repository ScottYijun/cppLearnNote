#include <iostream>
using namespace std;

class Person
{
public:
    void sleep() {cout << "sleep" << endl;}
    void eat() {cout << "eat" << endl;}
};

class Author: virtual public Person //Author��̳���Person
{
public:
    void writeBook() {cout << "write Book" << endl;}
};

class Programmer: virtual public Person //Programmer��̳���Person
{
public:
    void writeCode() {cout << "write Code" << endl;}
};

class Programmer_Author: public Programmer, public Author//���ؼ̳�
{

};

int main()
{
    Programmer_Author pa;
    pa.writeBook();//���û���Author�ķ���
    pa.writeCode();//���û���Programmer�ķ���
    pa.eat();       //�������eat()���岻��ȷ
    pa.sleep();     //�������sleep()���岻��ȷ

    return 0;
}
