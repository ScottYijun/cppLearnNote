#include <iostream>
using namespace std;

class human
{
public:
    human()
    {
        human_num++;
        //cout << "This is human Construction==this=" << this << endl;
    }
    static int human_num;
    ~human()
    {
        human_num--;
        print();
        //cout << "This is human Destruction======this======" << this << endl;
    }
    void print()
    {
        cout << "human num is: " << human_num << endl;
    }
//    human(const human &h)
//    {
//        human_num++;
//        //cout << "This is human Copy Construction==&h=" << &h << endl;
//    }
};

int human::human_num = 0;

human f1(human x)//这里会调用一次复制构造函数,
{
    x.print();
    //cout << "f1===========&x=====" << &x << endl;
    return x;//这里理论上要生成一个临时地象,
}

int main()
{
    human h1;
    h1.print();
    //cout <<"&h1=================" << &h1 << endl;
    human h2 = f1(h1);//h2是复制构造函数构造的对象吗
    //human h2 = h1;//h2是复制构造函数构造的对象,调用的是复制构造函数
    //cout <<"&h2=================" << &h2 << endl;
    h2.print();
    //cout <<"2===================" << endl;
    return 0;
}
