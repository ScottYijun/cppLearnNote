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
    int m_nPrt;//˽�б���
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
        return m_nPrt;  //A����ߴ���m_nPrt�ǻ���Parent��˽�б��������ܱ����������
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
        return m_nPrt;  //B����ߴ���m_nPrt�ǻ���Parent��˽�б��������ܱ����������
    }
};
//˽�м̳У�ͨ�����������໹�ǿ��Է��ʻ���Ĺ��г�Ա�ͱ�����Ա����������Ͳ����Է�����
class Child3 :private Parent {
public:
    int getPub() {
        return m_nPub;
    }
    int getPtd() {
        return m_nPtd;
    }
    int getPrt() {
        return m_nPrt;  //C����ߴ���m_nPrt�ǻ���Parent��˽�б��������ܱ����������
    }
};
//
int main() {
    Child1 cd1;
    Child2 cd2;
    Child3 cd3;

    int nVar = 0;
    //public inherited
    cd1.m_nPub = nVar;      //D ��ȷ
    cd1.getPtd = nVar;		//E�Ǵ����,m_nPtd�ǻ���Parent��protected��Ա���������м̳б��child1��protected��Ա��ֻ��child1�ڲ�����
    //���ܱ�child1�Ķ������
    nVar = cd1.getPtd();    //F ��ȷ
    //protected inherited
    cd2.m_nPub = nVar;      //G ���� m_nPub��Child2��Protected��Ա��
    nVar = cd2.getPtd();    //H ��ȷ
    //private inherited
    cd3.m_nPub = nVar;      //I ���� m_nPub���Private��Ա��
    nVar = cd3.getPtd();    //J ��ȷ����Ϊ���������Ա����������˽�б���

    return 0;
}
