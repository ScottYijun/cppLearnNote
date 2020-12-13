#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    int a = 10;
    int b = 20;
    int &rn = a;	//声明rn是变量a的一个引用，也就是rn是a的一个别名
    int equal;

    rn = b;
    cout << "a =" << a << endl;
    cout << "b =" << b << endl;

    rn = 100;

    cout << "a =" << a << endl;
    cout << "b =" << b << endl;

    equal = (&a == &rn) ? 1 : 0;
    cout << "equal = " << equal << endl;

    return 0;
}

