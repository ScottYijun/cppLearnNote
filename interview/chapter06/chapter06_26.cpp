#include <iostream>
using namespace std;

class String
{
public:
    String(const char *str = nullptr);              //��ͨ���캯��
    String(const String &other);                    //���ƹ��캯��
    ~String();                                      //��������
    String &operator=(const String &other);         //��ֵ����

private:
    char *m_string;                                 //˽�г�Ա�������ַ���
};
//��ͨ���캯��
String::String(const char *str)
{
    cout << "Construcing=============" << endl;
    if(nullptr == str)                              //���strΪnullptr������ַ���
    {
        m_string = new char[1];                     //����һ���ֽ�
        *m_string = '\0';                           //��ֵ��ֵΪ�ַ���������
    }
    else
    {
        m_string = new char[strlen(str) +1];        //����ռ�����str����
        strcpy(m_string, str);                      //����str��˽�г�Ա
    }
}
//���ƹ��캯��
String::String(const String &other)
{
    cout << "Constructing Copy=======" << endl;
    m_string = new char[strlen(other.m_string) + 1];//����ռ�����str����
    strcpy(m_string, other.m_string);               //����str��˽�г�Ա
}
//��������
String::~String()
{
    cout << "Destructing=============" << endl;
    if(m_string != nullptr)                         //���m_string��Ϊnullptr���ͷŶ��ڴ�
    {
        delete []m_string;
        m_string = nullptr;                         //�ͷź���Ϊnullptr
    }
}
//��ֵ����
String& String::operator=(const String &other)
{
    cout << "Operate = Function======" << endl;
    if(this == &other)                              //���������other��ͬһ������
    {
        return *this;                               //ֱ�ӷ��ر���
    }

    delete []m_string;                              //�ͷŶ��ڴ�
    m_string = new char[strlen(other.m_string) + 1];
    strcpy(m_string, other.m_string);

    return *this;
}

int main()
{
    String a("hello");                              //������ͨ���캯��
    String b("world");                              //������ͨ���캯��
    String c(a);                                    //���ø��ƹ��캯��
    c = b;                                          //���ø�ֵ����

    return 0;
}

