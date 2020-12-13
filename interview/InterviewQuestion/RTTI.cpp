/*
dynamic_cast 有什么用？
可以用来判断指针的类型转换是否安全。如果安全，则返回类型转换后的值；如果不安全，则返回0。

什么是安全的转换？
安全的指针：
指向自身类的对象。
指向自身派生的（直接和间接）的类的对象。
通过转换后，如果符合上述的条件，就是安全的转换。
*/
#include <iostream>
#include <typeinfo>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
class Base
{
public:
    virtual void ShowInfo();
    virtual ~Base();
};

Base::~Base()
{
    cout << "~~~~~~~~Base" << endl;
}
void Base::ShowInfo()
{
    cout << "Base::ShowInfo===========" << endl;
}

//必须要写虚析构函数的实现，否则报'Derived' has no out-of-line virtual method definitions...的警告。
//https://blog.csdn.net/luoyayun361/article/details/88369950

class Derived: public Base
{
public:
    virtual void ShowInfo();
    void print();
    ~Derived();
};

Derived::~Derived()
{
    cout << "~~~~~~~~Derived" << endl;
}

void Derived::print()
{
    cout << "Derived::print()===============" << endl;
}

void Derived::ShowInfo()
{
    cout << "Derived::ShowInfo===========" << endl;
}

class DerivedB: public Base
{
public:
    virtual void ShowInfo();
    void print();
    ~DerivedB();
};

DerivedB::~DerivedB()
{
    cout << "~~~~~~~~DerivedB" << endl;
}

void DerivedB::print()
{
    cout << "DerivedB::print()===============" << endl;
}

void DerivedB::ShowInfo()
{
    cout << "DerivedB::ShowInfo===========" << endl;
}
//RTTI(Run Time Type Identification)即通过运行时类型识别，
//程序能够使用基类的指针或引用来检查这些指针或引用所指的对象的实际派生类型。
int main()
{
    int a = 13;
    Base objb;
    Derived objd;
    Base *pb = dynamic_cast<Base *>(&objd);//派生类转基类可以，因为基类的对象比派生类小，
    pb->ShowInfo();

    Derived *pd = dynamic_cast<Derived *>(&objb);//基类对象不能转派生类对象，原因是基类比派生类小，如果这个时候用派生类对象pd调用print函数，这个是基类没有了，所以这样调用就会出问题。
    cout << "RTTI Example========" << endl;
    cout << "pb=======" << pb << endl;
    cout << "pd=======" << pd << endl;
    //typeid函数的主要作用就是让用户知道当前的变量是什么类型的，比如使用typeid(a).name()就能知道变量a是什么类型的。typeid()函数的返回类型为typeinfo类型的引用。
    cout << "typeid(a).name()========" << typeid (a).name() << endl;
    cout << "typeid(objb).name()========" << typeid (objb).name() << endl;
    cout << "typeid(objd).name()========" << typeid (objd).name() << endl;
    //虽然objd对象转成成了Base类型，但它是由Derived构建的，所以它的类型是Derived类型。
    cout << "typeid(*pb).name()========" << typeid (*pb).name() << endl;
    return 0;
}
*/


//https://www.cnblogs.com/xfxu/p/4012383.html
//两个类相等的前提是首先它们的类型相同，其次他们的成中也相同。
/*
class Animal
{
public:
    virtual bool equal(const Animal &other) const = 0;
    virtual ~Animal();
};

Animal::~Animal()
{
    cout << "~Animal================" << endl;
}

class Cat: public Animal
{
public:
    bool equal(const Animal &other) const
    {
        if(const Cat *pc = dynamic_cast<const Cat*>(&other))
        {
            return m_strName == pc->m_strName;
        }

        return false;
    }

    ~Cat();

private:
    string m_strName;
};
Cat::~Cat()
{
    cout << "~Cat================" << endl;
}

class Dog:public Animal
{
public:
    bool equal(const Animal &other) const
    {
        if(const Dog *pd = dynamic_cast<const Dog*>(&other))
        {
            return m_strName == pd->m_strName;
        }

        return false;
    }
    ~Dog();


private:
    string m_strName;
};

Dog::~Dog()
{
    cout << "~Dog================" << endl;
}

bool operator==(const Animal &a, const Animal &b)
{
    return typeid(a) == typeid(b) && a.equal(b);
}

int main()
{
    Cat c;
    Dog d;
    Animal *pa = &c;
    cout << "(*pa == c) =====" << (*pa == c) << endl;
    cout << "(*pa == d) =====" << (*pa == d) << endl;
}
*/


//https://www.cnblogs.com/tgycoder/p/5427303.html
/*
class A{
    //virtual void f(){ cout << "A++++++++++\n"; }
private:
    int a;
};

class B :public A{
public:
    virtual void f(){ cout << "HelloWorld\n"; }
private:
    int b;
};

class C :public B{
public:
    virtual void f(){ cout << "HelloWorld++\n"; }
private:
    int c;
};

class D :public A{
public:
    virtual void f(){ cout << "HelloWorld--\n"; }
private:
    int d;
};
int main()
{
    int a = 2;
    cout << typeid(a).name() << endl;
    A objA;
    //打印出class A
    cout << typeid(objA).name() << endl;
    B objB;
    //打印出class B
    cout << typeid(objB).name() << endl;
    C objC;
    //打印出class C
    cout << typeid(objC).name() << endl << endl;

    //在运行时候来确定类型的，而不是在编译器,会打印出class c  f()在C类中产生了多态
    B *ptrB = new C();    //C-》B-》A
    cout<<typeid(*ptrB).name()<<endl;  //print C

    A *ptrA = new D();  //D-》A
    //打印出class A而不是class D， 原因A类中没有virtual void f()，没有产生多态，如果在定中定义virtual void f()则会打印D。多态在运行时产生。
    cout << typeid(*ptrA).name() << endl;
    return 0;
}
*/
