#include <iostream>
using namespace std;

class Test
{
public:
    Test()      //构造函数a
    {
        cout << "constructor of Test====this=" << this << endl;
    }
};

Test a;         //全局变量a

int main()
{
    cout << "main() start====" << endl;
    Test b;
    return 0;
}


