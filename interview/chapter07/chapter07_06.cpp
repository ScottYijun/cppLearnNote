#include <iostream>
using namespace std;

class Person {
public:
    virtual void print() {
        cout << " I'm a Person" << endl;
    }
};

class Chinese :public Person {
public:
    virtual void print() {
        cout << " I'm from china" << endl;
    }
};

class American :public Person {
public:
    virtual void print() {
        cout << " I'm from USA" << endl;
    }
};

void printPerson(Person &person) {
    person.print();         //����ʱ���������ĸ����е�print()����
}

int main()
{
    Person p;
    Chinese c;
    American a;
    printPerson(p);
    printPerson(c);
    printPerson(a);
    return 0;
}
