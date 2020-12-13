#include <stdio.h>
#define MAX 255
int main()
{
    unsigned char A[MAX], i;
    for(i = 0; i <= MAX; i++)
    {
        A[i] = i;
        printf("A[%d]=%d\n", i, A[i]);
    }
    return 0;
}
