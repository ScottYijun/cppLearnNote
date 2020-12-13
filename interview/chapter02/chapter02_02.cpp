#include <stdio.h>

#define MAX(x,y) (((x)>(y)) ? (x) : (y))
#define MIN(x,y) ((x)>(y)) ? (x) : (y)
//在这里需要把参数小心的用括号括起来，因为宏只是简单的文本替换，括起来可以解决歧义的问题。
// 注意的是宏定义展开是在预处理时期，也就是编译之前，所有宏定义的参数能加括号就全加。
//
int main()
{
    int a = 13;
    int b = 35;

    printf("MAX(13, 35) = %d\n", MAX(a, b));
    printf("MIN(13, 35) = %d\n", MIN(a, b));
    return 0;
}
