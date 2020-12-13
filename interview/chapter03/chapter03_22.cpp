#include <iostream>
using namespace std;

int max(int x, int y)
{
    return (x > y ? x : y);
}

float *find(float *p, int x)
{
    return p + x;
}

int main()
{
    float score[] = {10, 20, 30, 40};
    int (*p)(int, int);
    float *q = find(score + 1, 1);
    int a;

    p = max;
    a = (*p)(1, 2);

    cout << "a = " << a << endl;
    cout << "*q = " << *q << endl;

    return 0;
}














