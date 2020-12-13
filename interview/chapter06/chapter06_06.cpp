#include <iostream>

#define public private //(1)

class Animal
{
public:                     //(2)
    void MakeNoise();
};

int main()
{
    Animal animal;
    animal.MakeNoise();         //(3)
    return 0;
}

