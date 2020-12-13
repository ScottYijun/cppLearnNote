#include <iostream>
#include <stdio.h>


using std::endl;
using std::cout;

char *p1;                       //Global uninitialized area
int a = 0;                      //Global initialization area

int main()
{
    int b;                      //stack
    char s[] = "abc";           //stack
    char *p2;                   //stack
    //char *p3 = "123456";        //123456\0在常量区，p3在栈上。a
    const char *p3 = "123456";    //新标准不以把常量赋给普通指针a
    static int c = 0;           //全局（静态）初始化区a
    p1 = (char *)malloc(10);    //heap
    p2 = (char *)malloc(20);    //heap
    int *p5 = new int[10];      //heap

    cout << "&p3=======" << &p3 << endl;
    cout << "&p2=======" << &p2 << endl;
    cout << "&s========" << &s << endl;
    cout << "&b========" << &b << endl;
    cout << "p5========" << p5 << endl;
    cout << "&c========" << &c << endl;
    cout << "&p1=======" << &p1 << endl;
    cout << "&a========" << &a << endl;

    cout << "sizeof(p1)========" << sizeof(p1) << endl;
    cout << "sizeof(&a)========" << sizeof(&a) << endl;
    cout << "sizeof(&c)========" << sizeof(&c) << endl;
    cout << "sizeof(p5)========" << sizeof(p5) << endl;

    return 0;
}






