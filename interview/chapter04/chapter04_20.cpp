#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

const char* reverse1(const char* s1, const char* token)
{                                   //这边s1是字符串，token是字符串的子串
    stack<char> stack1;             //这边建立一个堆
    const char* ptoken = token, *head = s1, *rear = s1;
    assert(s1 && token);
    while (*head != '\0')
    {                                       //表示该字符串没有到头
        while (*head != '\0'&&*ptoken == *head)
        {                                   //表示字符串里面与子串相等
            ptoken++;
            head++;
        }
        if (*ptoken == '\0')                //这边表示子串已经走到最后了，走到最后则将它倒过来压入堆栈
        {
            const char* p;
            for (p = head - 1; p >= rear; p--)
            {
                stack1.push(*p);
            }
            ptoken = token;
            rear = head;
        }                                   //否则直接压入堆栈
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
    char welcome[] = "Welcome you, my friend";	//字符串
    char token[] = "you";                       //字符串的子串
    const char *pRev = reverse1(welcome, token);

    cout << "before reverse:" << endl;
    cout << welcome << endl;
    cout << "after reverse:" << endl;
    cout << pRev << endl;

    return 0;
}
