#include "string06_36.h"
#include <string.h>

//默认构造函数,
String::String()
{
    data = new char[1];
    *data = '\0';           //空字符串只含有'\0'一个元素,
    size = 0;
}
//普通构造函数,
String::String(int n, char c)//含有n个相同字符的字符串,
{
    data = new char[n + 1];
    size = n;
    char *temp = data;//保存data,
    while(n--)//做n次赋值,
    {
        *temp++ = c;
    }
    *temp = '\0';
}
//普通构造函数,
String::String(const char *source)//字符串内容与source相同,
{
    if(nullptr == source)//source为nullptr,
    {
        data = new char[1];
        *data = '\0';//将data赋为空字符串,
        size = 0;
    }
    else
    {
        size = strlen(source);//source不为nullptr,
        data = new char[size + 1];
        strcpy(data, source);//复制source字符串,
    }
}
//复制构造函数,
String::String(const String& s)//字符串内容与对象s的相同,
{
    data = new char[s.size + 1];
    strcpy(data, s.data);
    size = s.size;
}
//重载=，实现字符串赋值,
String& String::operator =(char* s)//目标为字符串,
{
    if(data != nullptr)
    {
        delete []data;
    }
    size = strlen(s);
    data = new char[size + 1];
    strcpy(data, s);//复制目标字符串,
    return *this;
}
//重载=，实现对象赋值,
String& String::operator =(const String& s)//目标为String对象,
{
    if(this == &s)//如果对象s就是自己，直接返回*this,
    {
        return *this;
    }
    if(data != nullptr)//释放data堆内存,
    {
        delete []data;
    }
    size = strlen(s.data);
    data = new char[size + 1];//分配内存,
    strcpy(data, s.data);//复制对象s的字符串成员,
    return *this;
}
//析构函数,
String::~String()
{
    if(data != nullptr) //data不为nullptr，释放堆内存,
    {
        delete []data;
        data = nullptr;
        size = 0;
    }
}
//重载[]，实现数组运算,
char& String::operator[](int i)//[]重载,
{
    return data[i];//取数组下标为i的字符元素,
}
//重载[],实现数组运算（对象为常量）,
const char& String::operator[](int i) const
{
    return data[i];
}
//重载+=，实现与字符串相加,
String& String::operator +=(const String& s)//连接对象s的字符串成员,
{
    size_t len = size + s.size + 1;
    char *temp = data;
    data = new char[len];//申请足够的堆内存来存放连接后的字符串,
    size = len - 1;
    strcpy(data, temp);//复制原来的字符串,
    strcat(data, s.data);//连接目标对象内的字符串成员,
    delete []temp;
    return *this;
}
//重载+=，实现与对象相加,
String& String::operator +=(const char *s)//连接s字符串,
{
    if(s == nullptr)
    {
        return *this;
    }
    size_t len = size + strlen(s) + 1;
    char *temp = data;
    data = new char[len];//申请足够的堆内存来存放连接后的字符串,
    size = len - 1;
    strcpy(data, temp);//复制原来的字符串,
    strcat(data, s);//连接目标字符串,
    delete []temp;
    return *this;
}
size_t String::length()
{
    return size;
}
//重载<<，实现输出流,
ostream& operator <<(ostream &out, String& s)//打印对象s内字符串成员的所有字符元素,
{
    for(int i = 0; i < s.length(); i++)
    {
        out << s[i] << " ";//输出字符串中每一个字符元素,
    }
    return out;
}
//重载>>，实现输入流,
istream& operator >>(istream& in, String& s)
{
    char p[50];
    in.getline(p, 50);//从输入流接收最多50个字符,
    s = p;//调用赋值函数,
    return in;
}
//重载<,
bool operator < (const String& left, const String& right)
{
    int i = 0;
    while(left[i] == right[i] && left[i] != 0 && right[i] != 0)
    {
        i++;
    }
    return (left[i] - right[i]) < 0 ? true : false;
}
//重载>,
bool operator > (const String& left, const String& right)
{
    int i = 0;
    while(left[i] == right[i] && left[i] != 0 && right[i] != 0)
    {
        i++;
    }
    return (left[i] - right[i]) > 0 ? true : false;
}
//重载==,
bool operator == (const String& left, const String& right)
{
    int i = 0;
    while(left[i] == right[i] && left[i] != 0 && right[i] != 0)
    {
        i++;
    }
    return (left[i] - right[i]) == 0 ? true : false;
}
//重载!=,
bool operator != (const String& left, const String& right)
{
    int i = 0;
    while(left[i] == right[i] && left[i] != 0 && right[i] != 0)
    {
        i++;
    }
    return (left[i] - right[i]) != 0 ? true : false;
}
//获取data指针,
char* String::getData()
{
    return data;
}

int main()
{
    String str(3, 'a');
    String str1(str);//这种调用有什么问题,
    String str2("scott");
    String str3;
    cout << "str:=" << str << endl;
    cout << "str1:=" << str1 << endl;
    cout << "str2:=" << str2 << endl;
    cout << "str3:=" << str3 << endl;

    str3 = str2;
    cout << "str3:=" << str3 << endl;
    str3 = "12ab";
    cout << "str3:=" << str3 << endl;

    cout << "str3[2]:=" << str3[2] << endl;

    str3 += "chan";
    cout << "str3:=" << str3 << endl;
    str3 += str1;
    cout << "str3:=" << str3 << endl;

    cin >> str1;
    cout << "str1:=" << str1 << endl;

    String t1 = "1234";
    String t2 = "1234";

    String t3 = "12345";
    String t4 = "12335";

    cout << "t1 == t2 ? " << (t1 == t2) << endl;
    cout << "t1 < t3 ? " << (t1 < t3) << endl;
    cout << "t1 > t4 ? " << (t1 > t4) << endl;
    cout << "t1 != t4 ? " << (t1 != t4) << endl;

    return 0;
}
