#include <stdio.h>

struct Point
{
    int x;//合法
    int y;//合法
    void print() //编译错误
    {
        printf("Point print\n");
    }
};

int main()
{
    Point point;
    point.x = 20;
    point.y = 32;
    point.print();
    return 0;
}
