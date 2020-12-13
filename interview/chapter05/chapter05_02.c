#include <stdio.h>

int main()
{
    unsigned short int i = 0;
    unsigned char ii = 255;
    int j = 8, p, q;

    p = j << 1; // p  = 16;  j = 8;
    q = j >> 1; // q  = 4;   j = 8;
    i = i - 1;  // i  = 65535
    ii = ii + 1;// ii = 0
    printf(" j  = %d\n", j);
    printf(" i  = %d\n", i);
    printf(" ii = %d\n", ii);
    printf(" p  = %d\n", p);
    printf(" q  = %d\n", q);
    return 0;
}
