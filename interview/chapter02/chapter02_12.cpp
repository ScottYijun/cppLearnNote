#include <iostream>
class widget
{
public:
    widget()
    {
        count++;
    }
    ~widget()
    {
        --count;
    }
    static int num() //��widget��һ����̬����num()
    {
        return count;
    }
private:
    static int count;  //��widget��һ����̬��Աcount
};

int widget::count = 0;

int main() {
    widget x, y;
    std::cout << "The Num.is " << widget::num() << std::endl;

    if (widget::num() > 1)
    {
        widget x, y, z; //�������������x,y,y�ͱ���������
        std::cout << "The Num.is " << widget::num() << std::endl;
    }
    widget z;
    std::cout << "The Num.is " << widget::num() << std::endl;

    return 0;
}
