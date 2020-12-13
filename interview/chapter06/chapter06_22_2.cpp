#include <iostream>
using namespace std;

class Test
{
public:
    char *buf;
    Test(void)//不带参数的构造函数,
    {
        buf = nullptr;
    }
    Test(const char *str)//带参数的构造函数,
    {
        buf = new char[strlen(str) + 1];//分配堆内存
        cout << "buf======" << &buf << endl;
        strcpy(buf, str);//复制字符串,
    }
    Test(Test &test)
    {
        buf = new char[strlen(test.buf) + 1];
        strcpy(buf, test.buf);
    }

    ~Test()
    {
        cout << "~Test========buf-======" << &buf << endl;
        if(nullptr != buf)
        {
            delete buf;//释放buf指向的堆内存,
            buf = nullptr;
        }
    }
};

int main()
{
    Test t1("hello");
    Test t2 = t1;//调用默认的复制构造函数
    cout << "t1.buf====" << t1.buf << "\t  t2.buf====" << t2.buf << endl;
    cout << "(t1.buf == t2.buf) ? " << (t1.buf == t2.buf ? "yes" : "no") << endl;
    return 0;
}

