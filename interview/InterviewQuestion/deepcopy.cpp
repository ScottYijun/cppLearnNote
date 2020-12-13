#include <iostream>
#include <string>

using std::cout;
using std::endl;



//https://www.cnblogs.com/alantu2018/p/8459250.html

//浅拷贝示例
class CExample
{
public:
    CExample(int b) //构造函数
    {
        a = b;
        cout << "constructor is called" << this << endl;
    }
    //拷贝构造函数
    CExample(const CExample &c)
    {
        a = c.a;
        cout << "copy constructor is called" << this << endl;
    }
    //析构函数
    ~CExample()
    {
        cout << "destructor is called" << this << endl;
    }

    void Show()
    {
        cout << "a=======" << a << endl;
    }

private:
    int a;
};

//深拷贝示例
class CRect
{
public:
    CRect(int w, int h)
    {
        p = new int(100);
        width = w;
        height = h;
        cout << "constructor is called p = " << p << "\t*p = " << *p << "\tthis=" << this << endl;
    }

    CRect(const CRect &r)
    {
        width = r.width;
        height = r.height;
        p = new int;
        *p = *(r.p);
        cout << "copy constructor is called p = " << p << "\t*p = " << *p << "\tthis=" << this << endl;
    }

    ~CRect()
    {
        if(nullptr != p)
        {
            delete p;
        }
    }
    void Show()
    {
        cout << "p = " << p << "\t*p = " << *p << "\twidth = " << width << "\theight = " << height << endl;
    }

private:
    int width;
    int height;
    int *p;
};


//int main()
//{
//    CExample A(100);
//    CExample B = A;
//    B.Show();
//    cout << "A.this==" << &A << "\tB.this====" << &B << endl;
//    cout << "sizeof(A) = " << sizeof(A) << "\tsizeof(B) = " << sizeof(B) << endl;
//    cout << endl;
//    CRect RA(3, 5);
//    CRect RB = RA;
//    RB.Show();
//    cout << "RA.this==" << &RA << "\tRB.this====" << &RB << endl;
//    cout << "sizeof(RA) = " << sizeof(RA) << "\tsizeof(RB) = " << sizeof(RB) << endl;
//    return 0;
//}
