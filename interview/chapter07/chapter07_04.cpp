#include <iostream>
using namespace std;

class Person {
public:
    void eat() {
        cout << " Person eat===========" << endl;
    }
};
//˽�м̳�
class Student :private Person {
public:
    void study() {
        cout << " Student Study========" << endl;
    }
};
//
int main() {
    Person p;
    Student s;
    p.eat();
    s.study();
    //s.eat();	//��˽�л���̳ж����ĳ�Ա����Ϊ�������˽�г�Ա--��ʹ�����ڻ������Ǳ�������˽�г�Ա������
    //p = s;		//���������֮��ļ̳й�ϵΪ˽��private��������һ�㲻�Ὣ���������ת�ɻ������

    return 0;
}
