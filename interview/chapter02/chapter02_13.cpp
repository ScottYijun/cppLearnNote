#include <stdio.h>
#include <stdlib.h>

void Func(char str[100])
{
    printf("Func()=====sizeof(str) = %d\n", sizeof(str));
}

int main()
{
    char str[] = "Hello";
    char *p = str;
    int n = 10;
    printf("sizeof(str) ===== %d\n", sizeof(str));
    printf("sizeof(p) ======= %d\n", sizeof(p));
    printf("sizeof(n) ======= %d\n", sizeof(n));
    void *ptr = malloc(100);
    printf("sizeof(ptr) ===== %d\n", sizeof(ptr));
    Func(str);
    return 0;
}
