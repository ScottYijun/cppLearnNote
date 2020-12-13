#include <iostream>
using namespace std;

class Base
{
private:
    char *name;
public:
    Base(char *className)
    {
        name = new char[strlen(className) + 1];
        strcpy(name, className);
    }
    ~Base()
    {
        delete name;
    }
    char *copyName()
    {
        char *newname = new char[strlen(name) + 1];
        strcpy(newname, name);
        return newname;
    }

    char *getName()
    {
        return name;
    }
};

class Subclass: public Base
{
public:
    Subclass(char *className):Base(className)
    {

    }
};

int main()
{
    Base *pBase = new Subclass((char*)"test");
    printf("name: %s\n", pBase->getName());
    printf("new name: %s\n", pBase->copyName());

    return 0;
}










