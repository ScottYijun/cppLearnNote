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
    //�ڴζ�ȡ12���ֽ�
    while(nlen >= 12)
    {
        for(int i = 0; i < 12; ++i)
            ary[i] = temp[i];

        //����ary���ֶ�����
        if(ary[0] != 2 && ary[11] != 3)//2:�ֶο�ʼ�� 3���ֶν���
        {
            //���ݴ���
            nRet = -2;
            return nRet;
        }
        else
        {
            //�������ݣ�

        }

        nlen -= 12;
        temp += 12;
        //��ӡtest
        for(int i = 0; i < 12; ++i)
        {
            printf("ary[%d] = %d\n", i, ary[i]);
        }
    }

    if(nlen != 0)//���nlen����0.��������������ݲ�����
    {
        //������治����������
        return -1;
    }

    return nRet;
}


int main()
{
    char *src = malloc(sizeof(char)*13);
    //ģ���������
    src[0] = 0X02; src[1] = 0X2B; src[2] = 0X30; src[3] = 0X30;
    src[4] = 0X30; src[5] = 0X31; src[6] = 0X38; src[7] = 0X36;
    src[8] = 0X32; src[9] = 0X31; src[10] = 0X36; src[11] = 0X03;
    src[12] = '\0';
    double nRet = 0;
    nRet = analyze(src, 12);

    printf("nRet ===%f\n", nRet);//��������Ľ��
    return 0;
}
#endif
