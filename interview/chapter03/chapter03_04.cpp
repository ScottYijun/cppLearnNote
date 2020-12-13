#include <iostream>
#include <string>

void swap(char *&x, char *&y)
{
    char *temp;
    temp = x;
    x = y;
    y = temp;
}

void swap2(char **x, char **y)
{
    char *temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    char apr[] = "hello";
    char bpr[] = "how are your?";
    char *ap = apr;
    char *bp = bpr;

    std::cout << "*ap === " << ap << std::endl;
    std::cout << "*bp === " << bp << std::endl;

    swap(ap, bp);
    //swap2(&ap, &bp);
    std::cout << "swap ap, bp === " << std::endl;
    std::cout << "*ap === " << ap << std::endl;
    std::cout << "*bp === " << bp << std::endl;

    return 0;
}
