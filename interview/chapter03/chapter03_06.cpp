#include <iostream>
using namespace std;

class Test
{
public:
    void f(const int& arg);
private:
    int value;
};

void Test::f(const int &arg)
{
    //arg = 10;//arg�ǳ����ã�ֵ���ܱ��޸�
    cout << "arg = " << arg << endl;
    value = 20;
}

int main()
{
    int a = 7;
    const int b = 10;
    //int &c = b;//b�ǳ������ͣ����ܸ����ǳ���������
    const int &d = a;

    a++;
    //d++;//����ʹ�ó��������޸ı�����ֵ

    Test test;
    test.f(a);
    cout << "a = " << a << endl;
    return 0;
}
