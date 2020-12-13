#include <iostream>
using namespace std;

int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int (*p)(int, int);
    int a, b, c;
    int result;
    int max(int, int);

    p = max;
    cout << "Please input three integer " << endl;
    cin >> a >> b >> c;
    result = (*p)((*p)(a, b), c);
    cout << "result = " << result << endl;

    return 0;
}
