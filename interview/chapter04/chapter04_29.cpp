#include <iostream>
using namespace std;

int gbk_strlen(const char *str)
{
    const char *p = str;                                //ͷ�ڵ㣬pҲ���ں���ı���
                                                        //ʹ������ָ��ָ��ĵ�ַ֮������ȡ�ַ�������
    while (*p)                                          //���ǽ�����0�������ѭ��
    {
                                                        //���ֱ���Ϊ˫�ֽڣ��������ֽ�<0��β�ֽ���0~63����
        if (*p < 0 && (*(p + 1) < 0 || *(p + 1) > 63))  //���ĺ������
        {
            str++;                                      //str�ƶ�һλ��p�ƶ���λ����˳���+1
            p = p + 2;
        }
        else
        {
            p++;                                        //str������p�ƶ�һλ�����ȼ�1
        }
    }
    return p - str;                                     //���ص�ַ֮��
}

int main()
{
    char str[] = "abc���123�й�456";
    int len = gbk_strlen(str);
    cout << str << endl;
    cout << "len = " << len << endl;

    return 0;
}
