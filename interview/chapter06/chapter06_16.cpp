#include <iostream>
using namespace std;

class Test
{
public:
    Test() {}
    Test(char *Name, int len = 0) {cout << "name==" << Name << "len=" << len << endl;}
    Test(char *Name) {cout << "name==" << Name << endl;}
};
int main()
{
    Test obj("Hello");
    cout << "Hello=world=" << endl;
    return 0;
}
