#include <iostream>
using namespace std;

class Parent {
public:
    Parent(int var = -1) {
        m_nPub = var;
        m_nPtd = var;
        m_nPrt = var;
    }
public:
    int m_nPub;
protected:
    int m_nPtd;
private:
    int m_nPrt;//私有变量
};
//
class Child1:public Parent{
public:
    int getPub() {
        return m_nPub;
    }
    int getPtd() {
        return m_nPtd;
    }
    int getPrt() {
        return m_nPrt;  //A，这边错误，m_nPrt是基类Parent的私有变量，不能被派生类访问
    }
};
//
class Child2 :protected Parent {
public:
    int getPub() {
        return m_nPub;
    }
    int getPtd() {
        return m_nPtd;
    }
    int getPrt() {
        return m_nPrt;  //B，这边错误，m_nPrt是基类Parent的私有变量，不能被派生类访问
    }
};
//私有继承，通过函数，子类还是可以访问基类的公有成员和保护成员，但在类外就不可以访问了
class Child3 :private Parent {
public:
    int getPub() {
        return m_nPub;
    }
    int getPtd() {
        return m_nPtd;
    }
    int getPrt() {
        return m_nPrt;  //C，这边错误，m_nPrt是基类Parent的私有变量，不能被派生类访问
    }
};
//
int main() {
    Child1 cd1;
    Child2 cd2;
    Child3 cd3;

    int nVar = 0;
    //public inherited
    cd1.m_nPub = nVar;      //D 正确
    cd1.getPtd = nVar;		//E是错误的,m_nPtd是基类Parent的protected成员变量，公有继承变成child1的protected成员，只能child1内部访问
    //不能被child1的对象访问
    nVar = cd1.getPtd();    //F 正确
    //protected inherited
    cd2.m_nPub = nVar;      //G 错误 m_nPub在Child2是Protected成员了
    nVar = cd2.getPtd();    //H 正确
    //private inherited
    cd3.m_nPub = nVar;      //I 错误 m_nPub变成Private成员了
    nVar = cd3.getPtd();    //J 正确，因为调用了类成员函数访问其私有变量

    return 0;
}
