#include <iostream>
using namespace std;

class Shape
{
public:
    Shape() {}
    ~Shape() {}
    virtual void Draw() = 0;
};

int main()
{
    Shape *s1;
    return 0;
}
