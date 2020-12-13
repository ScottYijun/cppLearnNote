#include <stdio.h>

int main()
{
    int a[5] = {0, 1, 2, 3, 4}, *p;
    p = a;
    printf("%d\n", *(p + 4*sizeof(int)));

    return 0;
}
