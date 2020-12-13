#include <iostream>
using namespace std;

class Test
{
public:
    int add(int x, int y) //相加，传入参数以及返回值都是int
    {
        return x + y;
    }
    float add(float x, float y) //相加，传入参数以及返回值都是float
    {
        return x + y;
    }
};

int add(int x, int y)//相加，传入参数以及返回值都是int
{
    return x + y;
}

float add(float x, float y) //相加，传入参数以及返回值都是float
{
    return x + y;
}

int main()
{
    int i = add(1, 2);
    float f = add(1.1f, 2.2f);
    Test test;
    int i1 = test.add(3, 4);
    float f1 = test.add(3.3f, 4.4f);

    cout << "i = " << i << endl;
    cout << "f = " << f << endl;
    cout << "i1 = " << i1 << endl;
    cout << "f1 = " << f1 << endl;

    return 0;
}
