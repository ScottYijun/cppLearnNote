#include <stdio.h>

#define ARR_SIZE(a) (sizeof((a)) / sizeof((a[0])))
//#define ARR_SIZE2(a) (sizeof(a) / sizeof(a[0]))

int main()
{
    int array[100];
    printf("array size = %d\n", ARR_SIZE(array));
    //printf("array size = %d\n", ARR_SIZE2(array));
    return 0;
}
