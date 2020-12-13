#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

const char* reverse1(const char* s1, const char* token)
{                                   //���s1���ַ�����token���ַ������Ӵ�
    stack<char> stack1;             //��߽���һ����
    const char* ptoken = token, *head = s1, *rear = s1;
    assert(s1 && token);
    while (*head != '\0')
    {                                       //��ʾ���ַ���û�е�ͷ
        while (*head != '\0'&&*ptoken == *head)
        {                                   //��ʾ�ַ����������Ӵ����
            ptoken++;
            head++;
        }
        if (*ptoken == '\0')                //��߱�ʾ�Ӵ��Ѿ��ߵ�����ˣ��ߵ��������������ѹ���ջ
        {
            const char* p;
            for (p = head - 1; p >= rear; p--)
            {
                stack1.push(*p);
            }
            ptoken = token;
            rear = head;
        }                                   //����ֱ��ѹ���ջ
        else
        {
            stack1.push(*rear++);
            head = rear;
            ptoken = token;
        }
    }
    char *pReturn = new char[strlen(s1) + 1];
    int i = 0;
    while (!stack1.empty())
    {
        pReturn[i++] = stack1.top();
        stack1.pop();
    }
    pReturn[i] = '\0';

    return pReturn;
}

int main(int argc, char* argv[])
{
    char welcome[] = "Welcome you, my friend";	//�ַ���
    char token[] = "you";                       //�ַ������Ӵ�
    const char *pRev = reverse1(welcome, token);

    cout << "before reverse:" << endl;
    cout << welcome << endl;
    cout << "after reverse:" << endl;
    cout << pRev << endl;

    return 0;
}
