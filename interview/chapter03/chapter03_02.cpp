#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int a = 1;
    int b = 10;
    int *p = &a;	//��һ�е���˼���������͵�ָ�����P����ָ��a��Ҳ����pָ��a
    int*  &pa = p;  //����p��һ��ָ������pa, paʵ��Ҳ��ָ��a

    (*pa)++;        //paָ������ݼ�1
    cout << "a = " << a << endl;    //2
    cout << "b = " << b << endl;    //10
    cout << "*p = " << *p << endl;  //2

    pa = &b;        //��paָ�����b�ĵ�ַ������paҲ��p�����ã���ʱpҲָ����b
    (*pa)++;
    cout << "a = " << a << endl;    //2
    cout << "b = " << b << endl;    //11
    cout << "*p = " << *p << endl;  //11

    return 0;
}
