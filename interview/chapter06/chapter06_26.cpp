#include <iostream>
using namespace std;

class String
{
public:
    String(const char *str = nullptr);              //普通构造函数
    String(const String &other);                    //复制构造函数
    ~String();                                      //析构函数
    String &operator=(const String &other);         //赋值函数

private:
    char *m_string;                                 //私有成员，保存字符串
};
//普通构造函数
String::String(const char *str)
{
    cout << "Construcing=============" << endl;
    if(nullptr == str)                              //如果str为nullptr，存空字符串
    {
        m_string = new char[1];                     //分配一个字节
        *m_string = '\0';                           //将值赋值为字符串结束符
    }
    else
    {
        m_string = new char[strlen(str) +1];        //分配空间容纳str内容
        strcpy(m_string, str);                      //复制str到私有成员
    }
}
//复制构造函数
String::String(const String &other)
{
    cout << "Constructing Copy=======" << endl;
    m_string = new char[strlen(other.m_string) + 1];//分配空间容纳str内容
    strcpy(m_string, other.m_string);               //复制str到私有成员
}
//析构函数
String::~String()
{
    cout << "Destructing=============" << endl;
    if(m_string != nullptr)                         //如果m_string不为nullptr，释放堆内存
    {
        delete []m_string;
        m_string = nullptr;                         //释放后置为nullptr
    }
}
//赋值函数
String& String::operator=(const String &other)
{
    cout << "Operate = Function======" << endl;
    if(this == &other)                              //如果对象与other是同一个对象
    {
        return *this;                               //直接返回本身
    }

    delete []m_string;                              //释放堆内存
    m_string = new char[strlen(other.m_string) + 1];
    strcpy(m_string, other.m_string);

    return *this;
}

int main()
{
    String a("hello");                              //调用普通构造函数
    String b("world");                              //调用普通构造函数
    String c(a);                                    //调用复制构造函数
    c = b;                                          //调用赋值函数

    return 0;
}

