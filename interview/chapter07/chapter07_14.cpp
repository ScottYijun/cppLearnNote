class A{};
class B: virtual public A{};//B����̳���A
class C: virtual public A{};//C����̳���A
class D: public B, public C{};

int main()
{
    D d;
    A *pb = &d;//�������   �ɹ�ת��
    return 0;
}
