#include <iostream>

using namespace std;

int checkCPU()
{
    union word{
        int a;
        char b;
    }c;
    c.a = 1;
    return (c.b == 1);
}

int main()
{
    int ret = checkCPU();
    if(1 == ret)
        cout << "С����==========" << endl;
    else
        cout << "�����==========" << endl;
    return 0;
}

