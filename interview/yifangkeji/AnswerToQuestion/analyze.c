// ��ȡʮ�������ļ���main.hex���������䰴Hex��ʽ�涨���Բ�ͬ��ʽ����л���
// �����ֺ�ĸ�ʽд��main.txt�ļ�������Hex��ʽ������Ӧ��Flash�洢��Ԫ��ֵ
// ��Flash�洢��Ԫд��main_formated.txt��
// �뽫main.hex���ڸĳ����ͳһĿ¼��
// ���ߣ�nuaazdh
// ʱ�䣺2012��3��16�� 15:57:52
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLASHVOLUM 16   //Flash����������KΪ��λ


//https://blog.csdn.net/nuaazdh/article/details/7364013

//https://blog.csdn.net/a1037488611/article/details/43340055

void FormatTran(char *dst,const char *src);
int HexToDec(char *src);
void TranHex(char *flashbuffer,char *formatcmd,int flashsize);
void PrintFlash(char *flashbuffer,int flashsize);
void WriteFlashToFile(char *flashbuffer,char *filename,int flashsize);
char *ExtraSubStr(const char *src,int startIndex,int len);

#if 0
int main()
{
    FILE *fp;
    FILE *resultfp;
    int  flashsize=2*FLASHVOLUM*1024*sizeof(char);//flash�Ĵ洢��Ԫ����
    char *buffer = malloc(sizeof(char)*100);//�洢hex�ļ���һ������
    char *trsbuffer = malloc(sizeof(char)*200);//�洢hex�ļ������������
    char *flashbuffer = malloc(flashsize);//�洢Flash�е�����
    if(buffer==NULL||trsbuffer==NULL||flashbuffer==NULL){//����ռ�ʧ��
        printf("Apply for memory failed.!\n");
        exit(0);
    }
    //-----------------------------------
    //HexToDex()�������Դ���
    char *src=malloc(sizeof(char)*5);
    int value;
    //src[0]='2';src[1]='F';src[2]='1';src[3]='F';src[4]='\0';
    src[0]='0x00';src[1]='0x00';src[2]='0x00';src[3] = '0x0D';src[4]='\0';
    int num = -1;
            //atoi(src);
//    int val;
//    char str[20];
//    strcpy(str, "98993489");
//    val = atoi(str);

    //��������8���ֽ�Ϊ���ݴ�С����ַ��
    sscanf(src,"%x", &num);

    printf("%d\n", num);//���ʮ������
    value=HexToDec(src);
    printf("The value of the hex string:%d\n",value);



    //--------------------------------------------------
    /*
        //ExtraSubStr()�������Դ���
        char *src=":10003000758180121086D2A400000000C2A40000C6";
        char *substr;
        substr=ExtraSubStr(src,1,2);
        printf("SubString:%s\n",substr);
        printf("Change to Number:%d",HexToDec(substr));
    */

    memset(flashbuffer,'F',flashsize);//��Flash��ʼʱȫ����1
    fp=fopen("main.hex","r");
    resultfp=fopen("main.txt","w");
    if(resultfp==NULL||fp==NULL){//���ļ�ʧ��
        printf("Open file error.\n");
        exit(0);
    }
    while(fscanf(fp,"%s",buffer)!=EOF){//��ȡ�ļ���������
        //HextoBin(trsbuffer,buffer);
        printf("%s\n",buffer);//����̨��ʾ
        FormatTran(trsbuffer,buffer);
        //printf("Length:%d\n",strlen(buffer));//��ʾ�ַ�������
        fprintf(resultfp,"%s\n",trsbuffer);//д���ļ�
        TranHex(flashbuffer,buffer,flashsize);
    }
    PrintFlash(flashbuffer,2*1024);//����ʾǰ2K������
    WriteFlashToFile(flashbuffer,"main_formated.txt",2*1024);//��ǰ2K������д���ļ�"main_formated.txt"��
    //�ͷ��ڴ�
    free(buffer);
    free(trsbuffer);
    free(flashbuffer);
    //�ر��ļ�
    fclose(fp);
    fclose(resultfp);
}
#endif


void TranHex(char *flashbuffer,char *formatcmd,int flashsize){
    //��formatcmd�ַ�����������hex�ļ���ʽ�޸�flashbuffer�еĴ洢��Ԫ
    //�� formatcmd=":03000000020030CB"
    //��flahsbuffer����"0000"��ʼ������"03"���ڴ浥Ԫ������Ϊ"020030"
    //flashsize:��ʾflash�Ĵ洢��Ԫ����
    char *eofstring=":00000001FF";
    int startadd;//formatcmdָʾ����ʼ��ַ
    int count;//formatcmdָʾ�����ݵ�Ԫ����
    int p,q;//����ָ��
    if(strcmp(formatcmd,eofstring)==0){//������־
        printf("End of file.\n");
        return;
    }
    if(formatcmd[0]!=':'){//������":"��ʼ
        printf("Format wrong!\n");
        return;
    }
    if(strlen(formatcmd)<11){//�ַ�������С��11
        printf("Format wrong!\n");
        return;
    }
    count=HexToDec(ExtraSubStr(formatcmd,1,2));//������ݵ�Ԫ����
    startadd=2*HexToDec(ExtraSubStr(formatcmd,3,4));//�����ʼ��ַ
    if(strlen(formatcmd)<11+count*2){//�ַ����������𻵣���ʧ��
        printf("File has been damaged!\n");
        return;
    }
    for(p=0;p<count*2;p++){
        flashbuffer[startadd+p]=formatcmd[9+p];
    }
}

void FormatTran(char *dst,const char *src){
    //��ʽ��������һ��Hex�ļ��ַ���src����Hex�ļ���֯��ʽ
    //���ֳ���ͬ�Ŀ飬��֮��ͨ���ո����
    // ":llaaaatt[dd]cc"
    // ":"�п�ʼ��־��"ll"���ݳ��ȣ�"aaaa"��ʼ��ַ��"tt"�������ͣ�"dd"���ݣ�"cc"У��
    //������Ϊ��": ll aaaa tt [dd] cc"
    int srclen=strlen(src);
    //printf("Length of src:%d",srclen);
    int p=0,q=0;//������pΪsrc��������qΪdst����
    int i;//ѭ����־
    while(p<=srclen){//ѭ������src����ʽ����
        if(p==0){
            if(src[p]!=':'){//�Ƿ���":"��ʼ
                printf("Format wrong! Please check the format of the file.\n");
                break;
            }
            else{
                dst[q++]=':';dst[q++]=' ';
                p++;continue;
            }
        }
        if(p==1){
            for(i=0;i<2;i++){//��ȡ��λ��"ll"
                dst[q++]=src[p++];
            }
            dst[q++]=' ';continue;
        }
        if(p==3){
            for(i=0;i<4;i++){//��ȡ��λ��"aaaa"
                dst[q++]=src[p++];
            }
            dst[q++]=' ';continue;
        }
        if(p==7){
            for(i=0;i<2;i++){//��ȡ��λ��"tt"
                dst[q++]=src[p++];
            }
            dst[q++]=' ';continue;
        }
        for(i=0;i<2;i++){//��dst������λ������Ϊһ�飬�ÿո����
                dst[q++]=src[p++];
        }
        dst[q++]=' ';
    }
    dst[q]='\0';//������־
}

int HexToDec(char *src){
    //��src�е��޷���ʮ�������ַ���תΪʮ������
    //��src="001A"���򷵻�26
    //�ַ���src��Ҫ��'\0'��Ϊ������־
    int value=0,srclen=strlen(src);
    int i;
    for(i=0;i<srclen;i++){
        if(src[i]<='9'&&src[i]>='0'){
            value=value*16+(int)(src[i]-'0');
        }
        else if(src[i]<='f'&&src[i]>='a'){
            value=value*16+(int)(src[i]-'a'+10);
        }else{
            value=value*16+(int)(src[i]-'A'+10);
        }
    }
    return value;//����ת�������ֵ
}

char *ExtraSubStr(const char *src,int startIndex,int len){
    //��ȡ�Ӵ�����src����ȡ��startIndex��ʼ������len���ֽڣ������Ӵ�
    char *substr=malloc(sizeof(char)*(len+1));
    int i=0;
    if(substr==NULL){
        printf("Apply for memory failed.\n");
        return NULL;
    }
    if(strlen(src)<startIndex+len){
        printf("Index exceeds bounds.\n");
        return NULL;
    }
    for(i=0;i<len;i++){//��ȡ�Ӵ�
        substr[i]=src[startIndex+i];
    }
    substr[len]='\0';//�����ַ���ĩβ��־
    return substr;
}

void PrintFlash(char *flashbuffer,int flashsize){
    //flashbuffer:�ڴ浥Ԫָ�룻flashsize��flash�洢��Ԫ���������ֽ���
    //���Flash�е�����
    int rowlen=16;//ÿ��16���ֽ�
    int i,j;
    printf("Flash:%d\n",flashsize);
    for(i=0;i<flashsize;i+=2){
        if((i/2)%(rowlen)==0){
            printf("\n%06X\t",i/2);//�ڴ浥Ԫ��ַ�����ʽ��6λʮ�����ƣ�A~F��д��
        }
        printf("%c%c ",flashbuffer[i],flashbuffer[i+1]);
    }
}

void WriteFlashToFile(char *flashbuffer,char *filename,int flashsize){
    //��Flash������д���ļ���
    //flashbuffer:�ڴ浥Ԫָ�룻filename:Ҫд����ļ��ļ�����
    //flashsize:д��ĳ��ȣ����ֽڼ�
    FILE *fp;
    int i,rowlen=16;
    if((fp=fopen(filename,"w"))==NULL){
        printf("Open file error.\n");
        exit(0);
    }
    //��ʼд��
    for(i=0;i<flashsize;i+=2){
        if((i/2)%(rowlen)==0){
            if(i!=0){//���ǵ�һ�У�����д��16����Ԫ����
                fprintf(fp,"\n");
            }
            fprintf(fp,"%06X\t",i/2);//�ڴ浥Ԫ��ַ�����ʽ��6λʮ�����ƣ�A~F��д��
        }
        fprintf(fp,"%c%c ",flashbuffer[i],flashbuffer[i+1]);
    }
    fclose(fp);
}