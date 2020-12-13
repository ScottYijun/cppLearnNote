#include <iostream>
#include <string>
using namespace std;

class Number
{
public:
    string type;
    Number():type("void") {}
    explicit Number(short):type("short") {}
    Number(int): type("int"){}
};

void Show(const Number& n) {cout << n.type << endl;}

int main()
{
    short s = 42;
    Show(s);
    return 0;
}
