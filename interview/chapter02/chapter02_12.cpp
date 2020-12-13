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
    static int num() //类widget有一个静态方法num()
    {
        return count;
    }
private:
    static int count;  //类widget有一个静态成员count
};

int widget::count = 0;

int main() {
    widget x, y;
    std::cout << "The Num.is " << widget::num() << std::endl;

    if (widget::num() > 1)
    {
        widget x, y, z; //出了这个作用域，x,y,y就被析构掉了
        std::cout << "The Num.is " << widget::num() << std::endl;
    }
    widget z;
    std::cout << "The Num.is " << widget::num() << std::endl;

    return 0;
}
