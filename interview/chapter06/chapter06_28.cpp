#include <iostream>
using namespace std;

class B
{
public:
    B()
    {
        cout << "default constructor=======" << endl;
    }
    ~B()
    {
        cout << "destructed=====this=" << this << endl;
    }
    B(const B &b)
    {
        cout << "copy constructor===this==" << this << " &b=" << &b << " b.data=" << b.data << endl;
        data = b.data;
    }
    B(int i): data(i)//��ʼ��˽�г�Ա
    {
        cout << "constructed by parameter=i=" << i << "  this==" << this << endl;
    }

private:
    int data;
};

B Play(B b)//����һ��b��ʱ����,returnʱ�������������ʱ����
{
    cout << "Play============&b==" << &b << endl;
    return b;
}

int main(int argc, char *argv[])
{
    B t1 = Play(5);//t1=����Ĭ�ϵĸ��ƹ��캯��
    cout << "&t1=================" << &t1 << endl << endl;
    B t2 = Play(10);//t2=����Ĭ�ϵĸ��ƹ��캯��
    //B t2 = Play(t1);
    cout << "&t2=================" << &t2 << endl << endl;
    return 0;
}
