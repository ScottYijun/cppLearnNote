//重载，重写(覆盖)，隐藏
//函数重载：是指同一作用域的不同函数使用相同的函数名，但是参数个数或类型不同。
//a,相同的作用域(同一个类中)， b函数名相同, c.参数不同； d.virtual关键字可有可无。

#include <iostream>


using std::cout;
using std::endl;
using std::string;

int add(int x, int y);
double add(double x, double y);

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

class CShape
{
public:
    void Show(int w, int h);
    void Show(int r);
};

void CShape::Show(int w, int h)
{
    cout << "Rectangle w = " << w << " h = " << h << endl;
}

void CShape::Show(int r) //重载Show函数
{
    cout << "Circle r = " << r << endl;
}

class Base
{
public:
    virtual void showClassName();
    void print();
    void setName(string name);

    virtual ~Base();
};

void Base::showClassName()
{
    cout << "showClassName======Base" << endl;
}

void Base::print()
{
    cout << "print Base point=======" << this << endl;
}

void Base::setName(string name)
{
    cout << "name======" << name << endl;
}

Base::~Base()
{
    cout << "Destructor==========Base" << endl;
}

class Derived: public Base
{
public:
    virtual void showClassName();  //重写基类的showClassName函数
    void print();//隐藏基类的print函数
    void setName();//隐藏基类的setName函数

    virtual ~Derived();
};

void Derived::showClassName()
{
    cout << "showClassName======Derived" << endl;
}

void Derived::print()
{
    cout << "print Derived point=======" << this << endl;
}

void Derived::setName()
{
    cout << "name=====Derived=" << endl;
}

Derived::~Derived()
{
    cout << "Destructor==========Derived" << endl;
}

/*
int main()
{
    int nSum = add(2, 3);
    double dSum = add(3.3, 8.62); //同一作用域内函数重载
    cout << "2 + 3 = " << nSum << endl;
    cout << "3.3 + 8.62 = " << dSum << endl;

    CShape shape;
    shape.Show(5, 8);
    shape.Show(6);  //同一个类中函数重载

    cout << endl;
    Derived d;
    Base *pb = &d;
    Derived *pd = &d;
    pb->showClassName();
    pd->showClassName();//重写showClassName函数

    pb->print();
    pd->print();//隐藏基类的print函数

    pd->setName();//隐藏setName函数，
    //带参数调用错误,因为子类中的void setName()函数已经把父类中的void setName(string name)函数隐藏了，这种方式下子类对象pd访问不到void setName(string name)
    //pd->setName("aa");
    //此时可通过以下方式访问
    pd->Base::setName("函数隐藏");

    return 0;
}
*/


//https://blog.csdn.net/buknow/article/details/80517594
//https://www.cnblogs.com/418ks/p/7372608.html


