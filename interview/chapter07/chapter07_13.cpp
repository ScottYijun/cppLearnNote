#include <iostream>
using namespace std;
class cat
{
public:
    void show()
    {
        cout << "cat" << endl;
    }
};
class fish
{
public:
    void show()
    {
        cout << "fish" << endl;
    }
};

class catfish: public cat, public fish
{
};

int main()
{
    catfish obj;
    obj.cat::show();
    cout << "hello world" << endl;
    return 0;
}
