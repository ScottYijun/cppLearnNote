#include <iostream>
#include <string>

using namespace std;

class AA
{
public:
    void print();
    virtual void show();
};

void AA::print()
{
    cout << "AA::print()=================" << endl;
}

void AA::show()
{
    cout << "AA::show()=================" << endl;
}

class BB: public AA
{
public:
    void print();
    virtual void show();
};

void BB::print()
{
    cout << "BB::print()=================" << endl;
}

void BB::show()
{
    cout << "BB::show()=================" << endl;
}



class CC:public AA
{
public:
    void print();
    virtual void show();
};

void CC::print()
{
    cout << "CC::print()=================" << endl;
}

void CC::show()
{
    cout << "CC::show()=================" << endl;
}


//int main()
//{
//    AA *ab = new BB();
//    AA *ac = new CC();
//    ab->print();
//    ab->show();
//    ac->print();
//    ac->show();

//    return 0;
//}



