#include <iostream>

class A
{
private:
    int nTest;

public:
    int readTest()
    {
        return nTest;
    }
    void setTest(int i);
};

inline void A::setTest(int i)
{
    nTest = i;
    std::cout << "nTest======" << nTest << std::endl;
}

int main()
{
    A a;
    a.setTest(59);
    std::cout << "readTest===" << a.readTest() << std::endl;
    return 0;
}
