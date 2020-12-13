#include <iostream>
using namespace std;

class Engine {
public:
    Engine(int num) :numCylinders(num) {	//Engine构造函数

    }

    void start() {
        cout << " Engline start," << numCylinders << " Cylinders" << endl;
    }

private:
    int numCylinders;
};
//私有继承
class Car_pri :private Engine {
public:
    Car_pri() :Engine(8) {		//调用基类的构造函数

    }

    void start() {
        Engine::start();		//调用基类的start（）函数
    }
};

class Car_comp {
private:
    Engine engine;              //组合Engline类对象
public:
    Car_comp():engine(8){}      //给engline 成员初始化

    void start() {
        engine.start();         //调用engline的start()
    }
};

int main() {
    Car_pri car_pri;
    Car_comp car_comp;
    car_pri.start();
    car_comp.start();

    return 0;
}

