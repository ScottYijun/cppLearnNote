#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
double analyze(char *buf, int len)
{
    printf("buf length=====%d\n", len);
    char *temp;
    temp = buf;
    int nlen = 0;
    int nRet = 0;
    //char *src = malloc(13);
    //memset(src, '\0', 13);
    nlen = len;
    int ary[12] = {0};
    //第次读取12个字节
    while(nlen >= 12)
    {
        for(int i = 0; i < 12; ++i)
            ary[i] = temp[i];

        //分析ary各字段数据
        if(ary[0] != 2 && ary[11] != 3)//2:字段开始， 3：字段结束
        {
            //数据错误
            nRet = -2;
            return nRet;
        }
        else
        {
            //处理数据？

        }

        nlen -= 12;
        temp += 12;
        //打印test
        for(int i = 0; i < 12; ++i)
        {
            printf("ary[%d] = %d\n", i, ary[i]);
        }
    }

    if(nlen != 0)//如果nlen不等0.表过传过来的数据不完整
    {
        //处理后面不完整的数据
        return -1;
    }

    return nRet;
}


int main()
{
    char *src = malloc(sizeof(char)*13);
    //模拟测试数据
    src[0] = 0X02; src[1] = 0X2B; src[2] = 0X30; src[3] = 0X30;
    src[4] = 0X30; src[5] = 0X31; src[6] = 0X38; src[7] = 0X36;
    src[8] = 0X32; src[9] = 0X31; src[10] = 0X36; src[11] = 0X03;
    src[12] = '\0';
    double nRet = 0;
    nRet = analyze(src, 12);

    printf("nRet ===%f\n", nRet);//输出分析的结果
    return 0;
}
#endif
