#include <stdio.h>

int main()
{
    char a[] = "hello,world";
    char *ptr = a;

    printf("%c\n", *(ptr+4));
    printf("%c\n", ptr[4]);
    printf("%c\n", a[4]);
    printf("%c\n", *(a+4));

    *(ptr+4) += 1;
    printf("%c\n", *(ptr+4));
    printf("%s\n", a);

    return 0;
}
