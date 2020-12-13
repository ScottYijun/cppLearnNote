#include <iostream>
using namespace std;

class MyString
{
public:
    MyString(const char *s)   //参数为字符指针的构造函数,
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~MyString()         //析构函数释放str堆内存,
    {
        delete []str;
    }

    MyString& operator=(MyString &string)   //赋值函数，重载=,
    {
        if(this == &string)
        {
            return *this;
        }
        if(str != nullptr)  //释放内存,
        {
            delete []str;
        }
        str = new char[strlen(string.str) + 1];//申请内存,
        strcpy(str, string.str);                 //复制字符串内容,
        return *this;
    }

    /*
    MyString& operator+(MyString &string)       //重载+（改变被加对象）,
    {
        char *temp = str;
        str = new char[strlen(temp) + strlen(string.str) + 1];
        strcpy(str, temp);  //复制第一个字符串   str成员改变,
        delete []temp;
        strcat(str, string.str);    //连接第二个字符串,
        return *this;
    }
    */

    MyString& operator+(MyString &string)   //重载+（不改变被加对象）,
    {
        MyString *pString = new MyString("");//堆内存中构造对象,
        pString->str = new char[strlen(str) + strlen(string.str) + 1];
        strcpy(pString->str, str);          //复制第一个字符串  str没有改变,
        strcat(pString->str, string.str);   //连接第二个字符串,
        return *pString;                    //返回堆中的对象,
    }


    void print()
    {
        cout << str << endl;
    }
private:
    char *str;
};

/*
//MyString类的友员，要求str成员是public访问权限
MyString& operator +(MyString &left, MyString &right) //重载+（不改变被加对象）
{
    MyString *pString = new MyString("");
    pString->str = new char[strlen(left.str) + strlen(right.str) + 1];
    strcpy(pString->str, left.str);
    strcat(pString->str, right.str);
    return *pString;
}
*/
int main(int argc, char *argv[])
{
    MyString a("hello ");
    MyString b("world");

    MyString c("");
    c = c + a;  //先做加法，再赋值,
    c.print();
    c = c + b;  //先做加法，再赋值,
    c.print();

    c = a + b;
    a.print();
    c.print();

    return 0;
}


