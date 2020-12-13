#include <iostream>
using namespace std;

class Base
{
public:
    Base():i(0){cout << "Base()===i=" << i << endl;}
    Base(int n):i(n){cout << "Base(int)==" << endl;}
    Base(const Base &b):i(b.i)//复制构造函数,
    {
        cout << "Base(Base&)==" << endl;
    }
private:
    int i;//私有成员,
};

class Derived: public Base
{
public:
    Derived():Base(0),j(0) {cout << "Derived()=i="/* << this->i */<< "  j=" << j << endl;}//默认普通构造函数,
    Derived(int m, int n):Base(m), j(n) {cout << "Derived(int)=j=" << j << endl;}//普通构造函数,
    Derived(Derived &obj):Base(obj), j(obj.j)//Derived类的复制构造函数,
    {
        cout << "Derived(Derived&)==i="/* << this->i */<< "  j=" << j << endl;
    }
private:
    int j;
};

int main()
{
    Base b(1);
    Derived obj(2, 3);
    cout << "=================" << endl;
    Derived d(obj);
    cout << "=================" << endl;
    return 0;
}
//基类的私有成员会被添加到派生类的数据结构里面，但是派生类的函数没有权限直接访问基类私有成员,
//必须通过基类的protect或者public函数来访问,

