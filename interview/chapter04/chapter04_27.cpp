#include <iostream>
using namespace std;

int main()
{
    const char *str1 = "hello";
    const char *str2 = "china";
    char *str3 = NULL;
    //�����new����Ķ��ڴ�û�б���ʼ��
    str3 = new char[strlen(str1) + strlen(str2) + 1];
    str3[0] = '\n';       //����Ķ��ڴ�û�г�ʼ�����������ַ���������������������ֵ��
    //str3[0] = '\0';         //str3[0]��Ϊ������'\0'���Ա�strcat���������á�
    strcat(str3, str1);     //str3��Ϊ"hello"
    strcat(str3, str2);     //str3��Ϊ"hello china"
    cout << str3 << endl;

    return 0;
}
