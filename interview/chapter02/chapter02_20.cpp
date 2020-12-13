#include <iostream>

union u
{
    double a;
    int b;
};

union u2
{
    char a[13];
    int b;
};

union u3
{
    char a[13];
    char b;
};

int main()
{
    std::cout << "sizeof(u)====" << sizeof(u) << std::endl;
    std::cout << "sizeof(u2)===" << sizeof(u2) << std::endl;
    std::cout << "sizeof(u3)===" << sizeof(u3) << std::endl;
    return 0;
}
