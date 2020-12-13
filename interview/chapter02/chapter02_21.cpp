#include <iostream>

#pragma pack(1)

struct test{
    char c;
    short s1;
    short s2;
    int i;
};

int main()
{
    std::cout << "sizeof(test)====" << sizeof(test) << std::endl;
    return 0;
}
