#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    int a = 10;
    int b = 20;
    int &rn = a;	//����rn�Ǳ���a��һ�����ã�Ҳ����rn��a��һ������
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

