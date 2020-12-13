#include <iostream>
#include <stdio.h>

using namespace std;

//macos是8字节对齐
typedef struct STByte
{
    int a = 10;
    double b;
    short c;
}StByte;

typedef struct STData
{
    int a = 10;
    char ch[4];
    int &r = a;
}StData;

typedef struct STData2
{
    int a = 10;
    char ch[4];
}StData2;

typedef struct STData3
{
    int a = 10;
    int &r = a;//macos的指针占8个字节，并且是8字节对齐
    char ch[4];
}StData3;

//int main()
//{
//    //测试引用类型的变量是否占内存
//    int a = sizeof(StByte);
//    int b = sizeof(StData);
//    int c = sizeof(StData2);
//    int d = sizeof(StData3);
//    cout << "a = " << a << "\tb = " << b << endl;
//    cout << "c = " << c << "\td = " << d << endl;
//    cout << "sizeof(int) = " << sizeof(int) << "\tsizeof(float) = " << sizeof(float) << endl;
//    cout << "sizeof(short) = " << sizeof(short) << "\tsizeof(double) = " << sizeof(double) << endl;
//    cout << "sizeof(long int) = " << sizeof(long int) << "\tsizeof(long long) = " << sizeof(long long) << endl;
//    const int a1 = 20;
//    cout << "a1 = " << a1 << endl;
//    int *p1 = &a;
//    cout << "a1 = " << a1 << "\t*p1 = " << *p1 << endl;
//    *p1 = 30; //a内存中的值改变了，是30  寄存器中的值是20，编译器优化导致的。
//    //https://www.cnblogs.com/Lynn-Zhang/p/5689969.html
//    cout << "a1 = " << a1 << "\t*p1 = " << *p1 << endl;
//    return 0;
//}



