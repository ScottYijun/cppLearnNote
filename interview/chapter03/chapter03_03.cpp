#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 2;
    int &c;//��������û�г�ʼ��
    int &d = a;
    &d = b;//����ֻ����������ʱ�򱻸�ֵ���Ժ󲻶����޸�������������
    int *p;

    *p = 5;//pû�б���ʼ������˴�ʱ��p�Ǹ�Ұָ�롣

    return 0;
}
