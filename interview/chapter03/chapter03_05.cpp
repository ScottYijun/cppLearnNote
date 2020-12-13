#include <iostream>

const float pi = 3.14f;
float f;

float f1(float r)
{
    f = r * r * pi;
    return f;
}

float& f2(float r)
{
    f = r * r * pi;
    return f;
}

int main()
{
    float f1(float = 5);//声明函数f1()的默认参数调用，其默认值为5
    float &f2(float = 5);//声明函数f2()的默认参数调用，其默认值为5
    float a = f1();//将变量a赋为f1()的返回值。
    //float &b = f1();
    float c = f2();//f2()函数在返回值时直接将全局变量f返回变量c
    float &d = f2();//返回全局变量的引用给d

    d += 1.0f;//将d的值加1.0，此时d是全局变量f的引用，因此f的值变成79.5

    std::cout << "a = " << a << std::endl;
    //std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "f = " << f << std::endl;
}


