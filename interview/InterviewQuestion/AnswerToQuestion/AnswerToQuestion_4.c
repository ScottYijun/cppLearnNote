/*
    4.某系统约定双方使用 socket 通信，其协议如下：
    类型      标签      说明
    Int       Len       4字节整形数，表示jsonParam长度
    String   jsonParam 内容为以JSON格式组织并以UTF-8方式编码的参数
    现收到如下 socket 包，解析出 code 值为 0：
    字节 0    1    2    3    4 5 6 7 8 9 10 11 12 13
    内容 0x00 0x00 0x00 0x0A { “ c o d e “ : 0 }
    请实现函数 int analyze(char* buf, int len)，解析出 code 值。 buf 为收到的 socket 包，
    len为包长度。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

#if 0
int analyze(char *buf, int len)
{
    printf("buf length=====%d\n", len);
    char *temp;
    temp = buf;
    int nlen = 0;
    int nRet = 0;
    //读取4个字节
    //sscanf(src,"%04x", &nlen);
    //printf("nlen == %d\n", nlen);//输出十进制数
    for(int i = 0; i < 4; ++i)//解析头4个字节，json字符串的长度
    {
        int nTemp = temp[i];
        nlen += nTemp << (3 - i) * 8;
    }

    if(nlen == len - 4) //1.传过来的字符串是完整的
    {
        char *json = malloc(nlen + 1);
        strncpy(json, buf+4, nlen); //把json数据拷贝到字符串中
        json[nlen] = '\0';          //结束符；
        printf("json length=====%d\n", nlen);
        printf("json string=====%s\n", json);
        //解析json数据
        cJSON *root = NULL;
        cJSON *codeNode = NULL;
        int value = -1;
        root = cJSON_Parse(json);
        codeNode = cJSON_GetObjectItem(root, "code");
        value = codeNode->valueint;
        printf("code value======%d\n", value);
        cJSON_Delete(root);
    }
    else if(nlen > len - 4)//2.完整的数据还没有传完，
    {
        //josn数据的长度大于len-4，说明完整的字符串比较长还没有传完，
        //这个时候先把数据做个标记保存起来，下次有数据过来再拼接解析
        nRet = -1;
    }
    else if(nlen  < len - 4)//3.一次传了多个数据包
    {
        //按nlen长度解析，如果前面部分都解析完了，还剩下一部分不完整，
        //先保存起来等待下一个包传过来，拼接再解析。
        nRet = 1;
    }

    return nRet;
}


int main()
{

    char *src = malloc(sizeof(char)*15);
    //模拟测试数据
    src[0] = 0X00; src[1] = 0X00; src[2] = 0X00; src[3] = 0X0A;
    src[4] = '{'; src[5] = '\"'; src[6] = 'c'; src[7] = 'o';
    src[8] = 'd'; src[9] = 'e'; src[10] = '\"'; src[11] = ':';
    src[12]= '0'; src[13] = '}';src[14] = '\0';
    int nRet = -1;
    nRet = analyze(src, 14);
    printf("src=====%s\n", src+4);
    printf("nRet ===%d\n", nRet);//输出分析的结果
    return 0;
}
#endif

/*
 * 运行结果
    buf length=====14
    json length=====10
    json string====={"code":0}
    code value======0
    src====={"code":0}
    nRet ===0
*/
