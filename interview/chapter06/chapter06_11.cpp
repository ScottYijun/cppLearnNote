#include <iostream>
using namespace std;
class test
{
public:
    static int i;
    int j;
    test(int a):j(a) //, i(1)  //��̬��Ա���������ڲ���ʼ��
    {}
    void func1();
    static void func2();
};
int test::i = 1;
void test::func1() {cout << i << ", " << j << endl;}

void test::func2() {cout << i << /*", " << j <<*/ endl;} //��̬����ֻ�ܵ��þ�̬��Ա��

int main()
{
    test t(2);
    t.func1();
    t.func2();
    return 0;
}

