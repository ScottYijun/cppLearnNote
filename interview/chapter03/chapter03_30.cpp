#include <iostream>
using namespace std;

class Obj
{
public:
    Obj(void)
    {
        cout << "Initialization===" << endl;
    }
    ~Obj(void)
    {
        cout << "Destroy==========" << endl;
    }
};

void UseMallocFree(void)
{
    cout << "in UseMallocFree()..." << endl;
    Obj *a = (Obj *)malloc(sizeof(Obj));
    free(a);
}

void UseNewDelete(void)
{
    cout << "in UseNewDelete....." << endl;
    Obj *a = new Obj;
    delete a;
}

int main()
{
    UseMallocFree();
    UseNewDelete();
    return 0;
}
