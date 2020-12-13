#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 2;
    int &c;//声明引用没有初始化
    int &d = a;
    &d = b;//引用只能在声明的时候被赋值，以后不都能修改引用其它别名
    int *p;

    *p = 5;//p没有被初始化，因此此时的p是个野指针。

    return 0;
}
