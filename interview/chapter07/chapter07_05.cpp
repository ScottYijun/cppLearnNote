#include <iostream>
using namespace std;

class Engine {
public:
    Engine(int num) :numCylinders(num) {	//Engine���캯��

    }

    void start() {
        cout << " Engline start," << numCylinders << " Cylinders" << endl;
    }

private:
    int numCylinders;
};
//˽�м̳�
class Car_pri :private Engine {
public:
    Car_pri() :Engine(8) {		//���û���Ĺ��캯��

    }

    void start() {
        Engine::start();		//���û����start��������
    }
};

class Car_comp {
private:
    Engine engine;              //���Engline�����
public:
    Car_comp():engine(8){}      //��engline ��Ա��ʼ��

    void start() {
        engine.start();         //����engline��start()
    }
};

int main() {
    Car_pri car_pri;
    Car_comp car_comp;
    car_pri.start();
    car_comp.start();

    return 0;
}

