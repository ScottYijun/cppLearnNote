#include <iostream>
using namespace std;

class base {
//private:
//    int i;
public:
    base(int x) {
        i = x;
    }

    int i;
};
//
class derived :public base {
private:
    int i;
public:
    //��ߴ��󣬴����������£�
//    derived(int x, int y) {
//    	i = x;
//    }
    derived(int x, int y) :base(y) {
        i = x;
    }

    void printTotal() {
        int total = i + base::i;	//�޷�����˽�г�Ա����i
        cout << " total = " << total << endl;
    }
};

int main() {
    derived d(1, 2);
    d.printTotal();
    return 0;
}
