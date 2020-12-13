#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* addBigInt(char* num1, char* num2)
{
    int c = 0;                                  //c为进位，开始最低进位为0;
    int i = strlen(num1) - 1;                   //i指向第一个加数的最低位
    int j = strlen(num2) - 1;                   //j指向第二个加数的最低位
                                                //两个数中较大数的位数
    int maxLength = strlen(num1) >= strlen(num2) ? strlen(num1) + 1 : strlen(num2) + 1;
    char* rst = (char*)malloc(maxLength + 1);   //保留结果
    int k;
    if (rst == NULL)                            //这边判断申请的内存是否成功
    {
        printf("malloc error!\n");
        exit(1);
    }

    rst[maxLength] = '\0';                      //字符串最后一位为'\0'
    k = strlen(rst) - 1;                        //指向结果数组的最低位
    while ((i >= 0) && (j >= 0))
    {
        rst[k] = ((num1[i] - '0') + (num2[j] - '0') + c) % 10 + '0';
        c = ((num1[i] - '0') + (num2[j] - '0') + c) / 10;
        --i;
        --j;
        --k;
    }
    while (i >= 0)                              //这边是个弥补
    {
        rst[k] = ((num1[i] - '0') + c) % 10 + '0';
        c = ((num1[i] - '0') + c) / 10;
        --i;
        --k;
    }
    while (j >= 0)                              //这边是个弥补
    {
        rst[k] = ((num1[j] - '0') + c) % 10 + '0';
        c = ((num2[j] - '0') + c) / 10;
        --j;
        --k;
    }
    rst[0] = c + '0';

    if (rst[0] != '0')                          //如果结果最高位不等于0，则输出结果
    {
        return rst;
    }
    else
    {
        return rst + 1;
    }
}

int main()
{
    char num1[] = "123456789323";
    char num2[] = "45671254563123";
    char *result = NULL;

    result = addBigInt(num1, num2);
    printf("%s + %s = %s\n", num1, num2, result);

    return 0;
}

