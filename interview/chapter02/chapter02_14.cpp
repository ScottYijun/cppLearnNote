#include <iostream>

class A
{
public:
    int i;
};

class B
{
public:
    char ch;
};

class C
{
public:
    int i;
    short j;
};

class D
{
public:
    int i;
    short j;
    char ch;
};

class E
{
public:
    int i;
    int ii;
    short j;
    char ch;
    char chr;
};

class F
{
public:
    int i;
    int ii;
    int iii;
    short j;
    char ch;
    char chr;
};

int main()
{
    std::cout << "sizeof(int) ======" << sizeof(int) << std::endl;
    std::cout << "sizeof(short) ====" << sizeof(short) << std::endl;
    std::cout << "sizeof(char) =====" << sizeof(char) << std::endl;
    std::cout << std::endl;
    std::cout << "sizeof(A) ========" << sizeof(A) << std::endl;
    std::cout << "sizeof(B) ========" << sizeof(B) << std::endl;
    std::cout << "sizeof(C) ========" << sizeof(C) << std::endl;
    std::cout << "sizeof(D) ========" << sizeof(D) << std::endl;
    std::cout << "sizeof(E) ========" << sizeof(E) << std::endl;
    std::cout << "sizeof(F) ========" << sizeof(F) << std::endl;

    return 0;
}







