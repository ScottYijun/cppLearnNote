#include <stdio.h>

#define STR(s)	#s	//使用#把宏参数变成一个字符串
#define CONS(a,b)  (int)(a##e##b)	//这边用##把两个宏参数贴在一起  也就是aeb

int main()
{
    printf(STR(vck));
    printf("\n");
    printf("%d\n", CONS(2, 3));  //也就是2e3=2000
    return 0;
}
