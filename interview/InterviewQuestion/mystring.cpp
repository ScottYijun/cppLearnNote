//实现MyString类——构造函数，拷贝构造函数，析构函数，赋值函数，操作符重载函数。
#include <iostream>
#include <stdio.h>
#include <string>
#include <assert.h>

using std::cout;
using std::endl;
using std::string;

class MyString
{
public:
    MyString(const char *str = nullptr);//普通构造函数，加nullptr包含无参的情况
    MyString(const MyString &other);//拷贝构造函数
    ~MyString();//析构函数
    MyString& operator=(const MyString &other);//赋值函数，返回一个对象的引用
    MyString& operator+(const MyString &other);//"+"操作符重载
    MyString& operator+=(const MyString &other);//"+="操作符重载
    void print_str();

private:
    char *m_data;//保存字符串。
};

//普通构造函数
MyString::MyString(const char *str) //输入参数为const型
{
    if(nullptr == str)
    {
        cout << "普通构造函数========" << endl;
        m_data = new char[1];//对空字符串自动申请存放结束标志'\0'
        *m_data = '\0';
    }
    else
    {
        cout << "普通构造函数========*str==" << str << endl;
        size_t length = strlen(str);//strlen()函数返回的长度不包括'\0'
        m_data = new char[length + 1];//若能加nullptr判断则更好
        m_data[length] = '\0';
        strcpy(m_data, str);
    }
}

//拷贝构造函数
MyString::MyString(const MyString &other)//输入参数为const型
{
    cout << "拷贝构造函数==========" << endl;
    size_t length = strlen(other.m_data);
    m_data = new char[length + 1];
    m_data[length] = '\0';//添加结束符
    strcpy(m_data, other.m_data);
}

//析构函数
MyString::~MyString()
{
    cout << "析构函数========this==" << this << endl;
    delete []m_data;//数组用delete[]，平时的析构用delete m_data;
}
//赋值函数，返回一个对象的引用
MyString& MyString::operator=(const MyString &other)//输入参数为const型
{
    cout << "赋值函数“=”号==========" << endl;
    if(this == &other) //检查自赋值
        return *this;
    delete []m_data;//释放原有的内存资源
    size_t length = strlen(other.m_data);
    m_data = new char[length + 1];
    m_data[length] = '\0';//添加结束标志符
    strcpy(m_data, other.m_data);
    return *this;//返回本对象的引用
}
//重载操作符“+”号
MyString& MyString::operator+(const MyString &other)//输入参数为const型
{
    cout << "重载操作符“+”号==========" << endl;
    size_t length = strlen(m_data) + strlen(other.m_data);
    char *temp =  new char[length + 1];
    assert(temp);
    strcpy(temp, m_data);
    strcat(temp, other.m_data);
    if(m_data)
        delete []m_data;
    m_data = temp;
    return *this;
}

//重载操作符“+=”号
MyString& MyString::operator+=(const MyString &other)//输入参数为const型
{
    cout << "重载操作符“+=”号==========" << endl;
    size_t length = strlen(m_data) + strlen(other.m_data);
    char *temp = new char[length + 1];
    assert(temp);
    strcpy(temp, m_data);
    strcat(temp, other.m_data);
    //释放原来的内存
    if(m_data)
        delete []m_data;
    m_data = temp;
    return *this;
}

void MyString::print_str()
{
    cout << "print_str::m_data=======" << m_data << endl;
    //cout << "this->m_data=======" << this->m_data << endl;
}

/*
int main()
{
    MyString s0;//无参构造函数
    MyString s1("first");//有参构造函数
    MyString s2 = "second";//有参构造函数
    MyString s3 = s2;//拷贝构造函数；

    s0 = s1;//赋值函数；注意和上面一行的区别，
    s0.print_str();
    s0 + s1;//操作符"+"
    s0 += s2;//操作符"+="
    s0.print_str();
    cout << endl;

    MyString s4(nullptr);
    cout << endl;
    s4 = s1 + "_AAA";//调用3个函数：有参("_AAA")构造函数，重载操作符+函数，操作符=函数
    cout << endl;
    s4.print_str();
    cout << endl;
    s4 = s3 + s2;//不同于s4 = s1 + "_XXX",只调用两个函数，操作符+和操作符=
    cout << endl;
    s4.print_str();
    cout << endl;

    //s4 = "aaa" + "bbb";//错误，为什么，原因：+没有重载两个常量操作符。
    MyString s5 = s4 + "_BBB";//调用3个函数：有参("_BBB")构造函数，操作符+函数，拷贝构造函数
    cout << endl;
    s5.print_str();

    return 0;
}
*/

