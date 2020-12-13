#include <iostream>
using namespace std;
#define PI 3.14159  //圆周率

//形状类
class Shape {
public:
    Shape(){}
    ~Shape() {}
    virtual void Draw() = 0;	//纯虚函数
    virtual double Area() = 0;	 //纯虚函数
};

//长方形类
class Rectangle :public Shape {
public:
    Rectangle() :a(0), b(0) {}
    Rectangle(int x, int y) :a(x), b(y) {}
    virtual void Draw()
    {
        cout << "Rectangle,area:" << Area() << endl;
    }
    //
    virtual double Area() {	return a*b;	}
private:
    int a;
    int b;
};
//圆形类
class Circle :public Shape {
public:
    Circle(double x) :r(x) {}
    virtual void Draw()
    {
        cout << "Circle,area:" << Area() << endl;
    }
    virtual double Area() {	return PI*r*r;	}
private:
    double r;
};
//正方形类
class Square :public Rectangle {
public:
    Square(int length):a(length){}
    virtual void Draw()
    {
        cout << "Square,area:" << Area() << endl;
    }
    virtual double Area() {	return a*a;	}
private:
    int a;
};
//
int main() {
    Rectangle rect(10, 20);
    Square square(10);
    Circle circle(8);

    Shape *p;                   //抽象类指针
    p = &rect;
    cout << p->Area() << endl;  //调用Rectangle::Area()
    p->Draw();                  //调用Rectangle::Draw()

    p = &square;
    cout << p->Area() << endl;  //调用Square::Area()
    p->Draw();                  //调用Square::Draw()

    p = &circle;
    cout << p->Area() << endl;  //调用Circle::Area()
    p->Draw();                  //调用Circlee::Draw()

    return 0;
}
