#include <iostream>

using namespace std;

class Myclass
{
public:
    Myclass(int a, int b, int c);
    void GetNumber();
    void GetSum();
private:
    int A;
    int B;
    int C;
    int Num;
    static int Sum;
};

int Myclass::Sum = 0;

Myclass::Myclass(int a, int b, int c)
{
    A = a;
    B = b;
    C = c;
    Num = A + B + C;
    Sum = A + B + C;
}

void Myclass::GetNumber()
{
    cout << "Number = " << Num << endl;
}

void Myclass::GetSum()
{
    cout << "Sum = " << Sum << endl;
}

int main()
{
    Myclass M(3, 7, 10), N(14, 8, 11);
    M.GetNumber();
    N.GetNumber();
    M.GetSum();
    N.GetSum();
    return 0;
}
