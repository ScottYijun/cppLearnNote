#include <stdio.h>
#include <stdlib.h>

//冒泡排序算法
void mysort(char *str, int num)
{
    int i, j;
    int temp = 0;

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (str[i] < str[j])            //如果下一个值比当前值大，
            {                               //则交换两个元素值
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

char *foo(char *str)
{
    int len = 0;
    char *start = NULL;

    if (str == NULL)                        //检查参数str的有效性
    {
        return NULL;
    }

    start = str;                            //保存头部位置
    while (*str++);
    len = str - start - 1;                  //计算字符串长度
    len = len / 2;                          //计算需要排序的字符个数
    str = start;

    mysort(str, len);                       //从大到小排序

    return str;
}

int main()
{
    char string[] = "ADZDDJKJFIEJHGI";
    printf("before transformation:%s\n", string);
    foo(string);                            //调用冒泡排序方法进行排序
    printf("after transformation:%s\n", string);

    return 0;
}
