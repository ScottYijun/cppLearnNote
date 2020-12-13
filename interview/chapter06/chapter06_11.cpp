#include <iostream>
using namespace std;
class test
{
public:
    static int i;
    int j;
    test(int a):j(a) //, i(1)  //静态成员不参在类内部初始化
    {}
    void func1();
    static void func2();
};
int test::i = 1;
void test::func1() {cout << i << ", " << j << endl;}

void test::func2() {cout << i << /*", " << j <<*/ endl;} //静态函数只能调用静态成员。

int main()
{
    test t(2);
    t.func1();
    t.func2();
    return 0;
}

