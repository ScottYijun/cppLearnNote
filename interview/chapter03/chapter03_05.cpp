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
    float f1(float = 5);//��������f1()��Ĭ�ϲ������ã���Ĭ��ֵΪ5
    float &f2(float = 5);//��������f2()��Ĭ�ϲ������ã���Ĭ��ֵΪ5
    float a = f1();//������a��Ϊf1()�ķ���ֵ��
    //float &b = f1();
    float c = f2();//f2()�����ڷ���ֵʱֱ�ӽ�ȫ�ֱ���f���ر���c
    float &d = f2();//����ȫ�ֱ��������ø�d

    d += 1.0f;//��d��ֵ��1.0����ʱd��ȫ�ֱ���f�����ã����f��ֵ���79.5

    std::cout << "a = " << a << std::endl;
    //std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "f = " << f << std::endl;
}


