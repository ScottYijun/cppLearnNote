#ifndef STRING06_36_H
#define STRING06_36_H

#include <iostream>
using namespace std;

class String
{
public:
    String();                                                           //默认构造函数
    String(int n, char c);                                              //普通构造函数
    String(const char *source);                                         //普通构造函数
    String(const String& s);                                            //复制构造函数
    String& operator =(char* s);                                        //重载=，实现字符串赋值
    String& operator =(const String& s);                                //重载=，实现对象赋值
    ~String();                                                          //析构函数
    char& operator[](int i);                                            //重载[]，实现数组运算
    const char& operator[](int i) const;                                //重载[],实现数组运算（对象为常量）
    String& operator +=(const String& s);                               //重载+=，实现与字符串相加
    String& operator +=(const char *s);                                 //重载+=，实现与对象相加
    friend ostream& operator <<(ostream &out, String& s);               //重载<<，实现输出流
    friend istream& operator >>(istream& in, String& s);                //重载>>，实现输入流
    friend bool operator < (const String& left, const String& right);   //重载<
    friend bool operator > (const String& left, const String& right);   //重载>
    friend bool operator == (const String& left, const String& right);  //重载==
    friend bool operator != (const String& left, const String& right);  //重载!=
    char* getData();                                                    //获取data指针
    size_t length();                                                    //获取字符串长度

private:
    size_t size;                                                           //data表示的字符串长度
    char *data;                                                         //指向字符串数据
};


#endif // STRING06_36_H
