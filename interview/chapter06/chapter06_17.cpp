#include <iostream>

using namespace std;

struct CLS
{
    int m_i;
    CLS(int i): m_i(i)
    {
        cout << "CLS(): this = " << this << endl;
    }
    CLS()
    {
        CLS(0);
        cout << "CLS(int): this = " << this << endl;
    }
};

int main()
{
    CLS obj;
    cout << "&obj = " << &obj << endl;
    cout << obj.m_i << endl;
    return 0;
}

