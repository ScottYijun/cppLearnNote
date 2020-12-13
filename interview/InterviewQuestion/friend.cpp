//有些情况下，允许特定的非成员函数访问一个类的私有成员，同时仍阻止一般的访问，这是很方便做的，例如被重载的操作符，如输入或输出操作符，经常需要访问类的私有数据成员。
//友元(friend)机制允许一个类将对其非公有成员的访问权授予指定的函数或者类，友元的声明以friend开始，它只能出一央类定义的内部，友元声明可以出现在类中的任何地方；友元不是授予友元关系的那个类的成员，所以它们不受其声明出现部分的访问控制影响，通常，将友元声明成组地放在类定义的开始或结尾是个好主意。
//1。友元函数：友元函数是指某些虽然不是类成员函数却能够访问类的所有成员的函数。类授予它的友元特别的访问权，这样该友元函数就能访问到类中的所有成员。

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class CBoy
{
public:
    friend void setAge(int age, CBoy &boy);//该函数是友元函数的声明

private:
    int m_nAge;
};

void setAge(int age, CBoy &boy) //友元函数定义，为了访问类CBoy的私有成员m_nAge；
{
    boy.m_nAge = age;
    cout << "友元函数示例：age = " << boy.m_nAge <<endl;
}

//2.友元类
//友元类的所有成员函数都是另一个类的友元函数，都可以访问另一个类中的隐藏信息（包括私有成员和保护成员），当希望一个类可以存取另一个类的私有成员时，可以将该类声明为另一个类的友元类。
//关于友元类的注意事项：
//(1)友元关系不能被继承
//(2)友元关系是单向的，不具有交换性。若类B是类A的友元，类A不一定是类B的友元，要看在类中是否有相应的声明。
//(3)友元关系不具有传递性，若类B是类A的友元，类C是类B的友元，类C不一定是类A的友元，同样要看类中是否有相应的申明。

class CMateA
{
public:
    friend class CMateB; //这是友元类的声明

private:
    string m_strName;
};

class CMateB //友元类定义，为了访问CMateA中的成员。
{
public:
    void setName(string name, CMateA &mate);
};

void CMateB::setName(string name, CMateA &mate)
{
    mate.m_strName = name;
    cout << "友元类示例：m_strName=" << mate.m_strName << endl;
}

//3。友元成员函数：使类iPhone中的成员函数成为类Android的友元函数，这样类iPhone的该成员函数就可以访问类Android的所有成员了。
//当用到友元成员函数时，需要注意友元声明和友元定义之间的相互依赖，在该例子中，类iPhone必须先定义，否则类Android就不能将一个iPhone的函数指定为友元，然而，只有在定义了类Android后，才能定义类iPhone的该成员函数。更一般的讲，必须先定义包含成员函数的类，才能将成员函数设为友元。另一方面，不必预先声明类和非成员函数来将它们设为友元。

class Android; //当用到友元成员函数时，需注意友元声明与友元定义之间的互相依赖，这是类Android的声明

class iPhone
{
public:
    void setNumber(string number, Android &android);//该函数是类Android的友元函数。
};

class Android
{
public:
    friend void iPhone::setNumber(string name, Android &android); //该函数是友元成员函数的声明
    void show()
    {
        cout << "m_strNumber=======" << m_strNumber << endl;
    }
private:
    string m_strNumber;

};

void iPhone::setNumber(string number, Android &android)
{
    android.m_strNumber = number;
    cout << "android.m_strNumber=======" << android.m_strNumber << endl;
}

//int main()
//{
//    CBoy boy;
//    setAge(15, boy);

//    CMateA mateA;
//    CMateB mateB;
//    mateB.setName("chenyijun", mateA);

//    Android android;
//    iPhone iphone;
//    iphone.setNumber("15361481379", android);
//    android.show();

//    return 0;
//}

/*
友元小结：
在需要允许某些特定的非成员函数访问一个类的私有成员（及受保护成员），而同时仍阻止一般的访问的情况下，友元是可用的。
优点：
可以灵活地实现需要访问若干类的私有或受保护的成员才能完成的任务；
便于与其他不支持类概念的语言（如C语言。汇编等）进行混合编程；
通过使用友元函数重载可以更自然地使用C++语言的IO流库。
缺点：
一个类将其非公有成员的访问权限授予其他函数或者类，会破坏该类的封装性，降低该类的可靠性和可维护性。

*/





