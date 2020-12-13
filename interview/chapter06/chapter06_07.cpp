#include <iostream>
using namespace std;

class Obj {
public:
    Obj(int k): j(k), i(j)
    {
    }
    void print(void)
    {
        cout << " i ==== " << i << endl << " j ==== " << j << endl;
    }
private:
    int i;
    int j;
};

int main(int argc, char *argv[])
{
    Obj obj(2);
    obj.print();

    return 0;
}




