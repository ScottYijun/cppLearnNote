#include <stdio.h>

int main()
{
    char *str[] = {"Welcom", "to", "Fortemedia", "Nanjing"};
    char **p = str + 1;//p指向str[1]的地址
    str[0] = (*p++) + 2;//++的优化级高于*号  此时p指向了str[2]的地址
    str[1] = *(p+1);
    str[2] = p[1] + 3;//p指向的是str[2]的地址，str[2]的地址变了，所以p指向的地址也根着改修改了，p[0] = "jing"
    str[3] = p[0] + (str[2] - str[1]);
    printf(" str[0] = %s\n", str[0]);
    printf(" str[1] = %s\n", str[1]);
    printf(" str[2] = %s\n", str[2]);
    printf(" str[3] = %s\n", str[3]);

    return 0;
}
