#include <iostream>
using namespace std;

//����
struct Base {
public:
    virtual void Func1() = 0;           //���麯��
    virtual void Func2() = 0;           //���麯��

    void print() {
        Func1();                        //�����������Fun1()
        Func2();                        //�����������Fun2()
    }
};

struct T :private Base {
public:
    virtual void Func1() {              //���ǻ����Fun1
        cout << "Func1" << endl;		//���ǻ����Fun2
    }

    virtual void Func2() {
        cout << "Func2" << endl;
    }
    //���û����print()
    void UseFunc() {
        Base::print();
    }
};

int main()
{
    T t;
    t.UseFunc();
    return 0;
}
