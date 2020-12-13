#include <iostream>
using namespace std;

class Person {
public:
    void eat() {
        cout << " Person eat===========" << endl;
    }
};
//私有继承
class Student :private Person {
public:
    void study() {
        cout << " Student Study========" << endl;
    }
};
//
int main() {
    Person p;
    Student s;
    p.eat();
    s.study();
    //s.eat();	//从私有基类继承而来的成员都成为派生类的私有成员--即使它们在基类中是保护或者私有成员变量。
    //p = s;		//如果两个类之间的继承关系为私有private，编译器一般不会将派生类对象转成基类对象。

    return 0;
}
