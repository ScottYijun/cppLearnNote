#include <iostream>
using namespace std;
//strΪԭ�ַ�����sub1:Ϊ��2���ַ�����sub2Ϊ��3���ַ�����outputΪ���
char *replace(const char *str, const char *sub1, const char *sub2, char *output)
{
    char *pOutput = NULL;
    const char *pStr = NULL;
    int lenSub1 = strlen(sub1);                 //�Ӵ�sub1�ĳ���
    int lenSub2 = strlen(sub2);                 //�Ӵ�sub2�ĳ���

    pOutput = output;
    pStr = str;                                 //����Ѱ���Ӵ�
    while (*pStr != 0)
    {
        pStr = strstr(pStr, sub1);              //��str��Ѱ��sub1�Ӵ�
        if (pStr != NULL)                       //�ҵ�sub1�Ӵ�
        {
            memcpy(pOutput, str, pStr - str);	//����str��ǰһ����output
            pOutput += pStr - str;
            memcpy(pOutput, sub2, lenSub2);     //����sub2�Ӵ���output
            pOutput = pOutput + lenSub2;
            pStr = pStr + lenSub1;              //Ϊ����һ�θ�����׼��
            str = pStr;
        }
        else                                    //�Ҳ���sub1�Ӵ�
        {
            break;
        }
    }
    *pOutput = '\0';
    if (*str != '\0')
    {
        strcpy(pOutput, str);                   //����strʣ�ಿ�ֵ�output
    }

    return output;
}

int main()
{
    char str[50] = "";                          //Դ�ַ���str
    char sub1[10] = "";                         //���滻���ַ���sub1
    char sub2[10] = "";                         //�����滻sub2
    char output[100] = "";                      //����ַ���

    cout << "str:";
    cin >> str;
    cout << "sub1:";
    cin >> sub1;
    cout << "sub2:";
    cin >> sub2;

    cout << replace(str, sub1, sub2, output) << endl;

    return 0;
}
