#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *GetMemory()
{
    char p[] = "hello world";
    return p;
}

void Test(void)
{
    char *str = NULL;
    str = GetMemory();
    printf(" str====%s\n", str);
}

void GetMemory2(char *p)
{
    p = (char*)malloc(100);
}

void Test2(void)
{
    char *str = NULL;
    GetMemory2(str);
    strcpy(str, "hello world");
    printf(" str====%s\n", str);
}

int main()
{
    Test();
    Test2();
    return 0;
}
