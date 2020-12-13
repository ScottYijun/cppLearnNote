class A{};
class B: virtual public A{};//BĞéÄâ¼Ì³Ğ×ÔA
class C: virtual public A{};//CĞéÄâ¼Ì³Ğ×ÔA
class D: public B, public C{};

int main()
{
    D d;
    A *pb = &d;//±àÒë´íÎó   ³É¹¦×ª»»
    return 0;
}
