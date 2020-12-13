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
    B(int i): data(i)//初始化私有成员
    {
        cout << "constructed by parameter=i=" << i << "  this==" << this << endl;
    }

private:
    int data;
};

B Play(B b)//复制一个b临时对象,return时会析构掉这个临时对象
{
    cout << "Play============&b==" << &b << endl;
    return b;
}

int main(int argc, char *argv[])
{
    B t1 = Play(5);//t1=调用默认的复制构造函数
    cout << "&t1=================" << &t1 << endl << endl;
    B t2 = Play(10);//t2=调用默认的复制构造函数
    //B t2 = Play(t1);
    cout << "&t2=================" << &t2 << endl << endl;
    return 0;
}
