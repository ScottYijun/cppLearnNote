/*
 * 5. ����һ�� int ���� M���ж���������� 1 �Ƿ�������
 * ���� �� M = 120 -> 0111 1000 true;
 * M=184->1011 1000 false.ʵ�ֺ��� bool check(int M)��
*/

#include <iostream>

using namespace std;

bool check(int M)
{
    while(M)
    {
        while((M & 1) == 0)
        {
            M >>= 1;
        }
        if((M & 3) != 3)
            return false;
        M >>= 2;
    }

    return true;
}

#if 0
int main()
{
    int num;
    cout << "������һ��������";
    cin >> num;
    bool bRet = check(num);
    printf("%d->", num);
    char str[32] = {'\0'};
    itoa(num, str, 2);
    printf("%s", str);//�����������

    if(bRet)
        cout << " ��������1����    true" << endl;
    else
        cout << " ��������1������  false" << endl;

    return 0;
}

#endif


/*
���н����
������һ��������120
120-> 1111000 ��������1����    true
������һ��������184
184->10111000 ��������1������  false
*/
