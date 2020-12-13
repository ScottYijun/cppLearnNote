#include <iostream>
using namespace std;

class Parent
{
public:
    Parent(): num(0) {cout << "Parent" << endl;}
    Parent(int n): num(n){cout << "Parent(int)" << endl;}
private:
    int num;
};
class Child1: virtual public Parent
{
public:
    Child1() {cout << "Child1()" << endl;}
    Child1(int num): Parent(num){cout << "Child1(int)" << endl;}
};
class Child2: virtual public Parent
{
public:
    Child2() {cout << "Child2()" << endl;}
    Child2(int num): Parent(num){cout << "Child2(int)" << endl;}
};
class Derived:public Child1, public Child2
{
public:
    Derived(): Child1(0), Child2(1){}
    Derived(int num): Child2(num), Child1(num+1) {}
};

int main()
{
    Derived d(4);
    return 0;
}
