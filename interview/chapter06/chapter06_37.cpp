#include <memory.h>
#include <stdlib.h>
#include <iostream>

class Blanks
{
public:
    void *operator new(size_t stAllocateBlock, char chInit);
};
void *Blanks::operator new(size_t stAllocateBlock, char chInit)
{
    void *pvTemp = malloc(stAllocateBlock);
    if(pvTemp != nullptr)
        memset(pvTemp, chInit, stAllocateBlock);
    return pvTemp;
}

int main()
{
    Blanks *a5 = new(0xa5) Blanks;
    std::cout << "a5======" << a5 << std::endl;
    return a5 != nullptr;
}

