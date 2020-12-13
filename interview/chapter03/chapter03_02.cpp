#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int a = 1;
    int b = 10;
    int *p = &a;	//这一行的意思是声明整型的指针变量P，并指向a，也就是p指向a
    int*  &pa = p;  //声明p的一个指针引用pa, pa实际也是指向a

    (*pa)++;        //pa指向的内容加1
    cout << "a = " << a << endl;    //2
    cout << "b = " << b << endl;    //10
    cout << "*p = " << *p << endl;  //2

    pa = &b;        //将pa指向变量b的地址，由于pa也是p的引用，此时p也指向了b
    (*pa)++;
    cout << "a = " << a << endl;    //2
    cout << "b = " << b << endl;    //11
    cout << "*p = " << *p << endl;  //11

    return 0;
}
