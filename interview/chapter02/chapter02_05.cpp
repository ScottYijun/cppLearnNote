#include <stdio.h>

#define WORD_LO(xxx) ((xxx) & 255)
#define WORD_HI(xxx) ((xxx) >> 8)

int main()
{
    int a = 511;
    printf("WORD_LO(xxx) = %d\n", WORD_LO(a));
    printf("WORD_HI(xxx) = %d\n", WORD_HI(a));
    return 0;
}
