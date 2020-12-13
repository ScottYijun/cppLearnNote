/*
    4.ĳϵͳԼ��˫��ʹ�� socket ͨ�ţ���Э�����£�
    ����      ��ǩ      ˵��
    Int       Len       4�ֽ�����������ʾjsonParam����
    String   jsonParam ����Ϊ��JSON��ʽ��֯����UTF-8��ʽ����Ĳ���
    ���յ����� socket ���������� code ֵΪ 0��
    �ֽ� 0    1    2    3    4 5 6 7 8 9 10 11 12 13
    ���� 0x00 0x00 0x00 0x0A { �� c o d e �� : 0 }
    ��ʵ�ֺ��� int analyze(char* buf, int len)�������� code ֵ�� buf Ϊ�յ��� socket ����
    lenΪ�����ȡ�
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
    //��ȡ4���ֽ�
    //sscanf(src,"%04x", &nlen);
    //printf("nlen == %d\n", nlen);//���ʮ������
    for(int i = 0; i < 4; ++i)//����ͷ4���ֽڣ�json�ַ����ĳ���
    {
        int nTemp = temp[i];
        nlen += nTemp << (3 - i) * 8;
    }

    if(nlen == len - 4) //1.���������ַ�����������
    {
        char *json = malloc(nlen + 1);
        strncpy(json, buf+4, nlen); //��json���ݿ������ַ�����
        json[nlen] = '\0';          //��������
        printf("json length=====%d\n", nlen);
        printf("json string=====%s\n", json);
        //����json����
        cJSON *root = NULL;
        cJSON *codeNode = NULL;
        int value = -1;
        root = cJSON_Parse(json);
        codeNode = cJSON_GetObjectItem(root, "code");
        value = codeNode->valueint;
        printf("code value======%d\n", value);
        cJSON_Delete(root);
    }
    else if(nlen > len - 4)//2.���������ݻ�û�д��꣬
    {
        //josn���ݵĳ��ȴ���len-4��˵���������ַ����Ƚϳ���û�д��꣬
        //���ʱ���Ȱ�����������Ǳ����������´������ݹ�����ƴ�ӽ���
        nRet = -1;
    }
    else if(nlen  < len - 4)//3.һ�δ��˶�����ݰ�
    {
        //��nlen���Ƚ��������ǰ�沿�ֶ��������ˣ���ʣ��һ���ֲ�������
        //�ȱ��������ȴ���һ������������ƴ���ٽ�����
        nRet = 1;
    }

    return nRet;
}


int main()
{

    char *src = malloc(sizeof(char)*15);
    //ģ���������
    src[0] = 0X00; src[1] = 0X00; src[2] = 0X00; src[3] = 0X0A;
    src[4] = '{'; src[5] = '\"'; src[6] = 'c'; src[7] = 'o';
    src[8] = 'd'; src[9] = 'e'; src[10] = '\"'; src[11] = ':';
    src[12]= '0'; src[13] = '}';src[14] = '\0';
    int nRet = -1;
    nRet = analyze(src, 14);
    printf("src=====%s\n", src+4);
    printf("nRet ===%d\n", nRet);//��������Ľ��
    return 0;
}
#endif

/*
 * ���н��
    buf length=====14
    json length=====10
    json string====={"code":0}
    code value======0
    src====={"code":0}
    nRet ===0
*/
