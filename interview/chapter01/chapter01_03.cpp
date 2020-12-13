#include <stdio.h>

int main(void)
{
    int i = 8;

    printf("%d\n",++i);//9
    printf("%d\n",--i);//8
    printf("%d\n",i++);//8
    printf("%d\n",i--);//9
    printf("%d\n",-i++);//-8
    printf("%d\n",-i--);//-9
    printf("------\n");

    return 0;
}
