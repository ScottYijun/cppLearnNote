#include <iostream>

using namespace std;

class A             //A�Ǹ���
{
private:
    int a;          //private��Ա
public:
    A() {}
    A(int x):a(x) {} //�������Ĺ��캯����a��ʼ��
    void printA()
    {
        cout << " a = " << a << endl;
    }
};

class B: public A //B������
{
private:
    int b;
public:
    B(int x, int y): A(x)       //��Ҫ��ʼ��b�Լ������a
    {
        //a = x;                  //aΪprivate,�޷��������б����ʣ��������
        //A(x);                   //���÷�ʽ���󣬱������
        b = y;
    }
    void printB() //��ӡb��ֵ
    {
        cout << " b = " << b << endl;
    }
};

int main()
{
    B b(2, 3);
    b.printA();     //���������printA()
    b.printB();     //�������ѵ�printB()

    return 0;
}
