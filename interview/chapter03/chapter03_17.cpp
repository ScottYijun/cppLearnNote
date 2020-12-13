#include <stdio.h>

int main()
{
    const char *node1 = "abc";
    //char *const node2 = "abc";//C++ 11不支持这种写法
    printf("node1====%s\n", node1);
    //node1[2] = 'k';//node1是常量指针，所指向的内容是不能修改的
    //*node1[2] = 'k';//node1是常量指针，所指向的内容是不能修改的
    //*node1 = "xyz";//node1是常量指针，所指向的内容是不能修改的
    node1 = "xyz";//正确，node1指向了“xyz”所在的地址。
    printf("node1====%s\n", node1);

    //node2[2] = 'k';
    //*node2[2] = 'k';
    //*node2 = "xyz";
    //node2 = "xyz";

    return 0;
}
