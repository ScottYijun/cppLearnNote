#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    fp = fopen("F:\\github\\cppLearnNote\\interview\\InterviewQuestion\\tangshi.txt", "r");   //���ļ�
    printf("fp=========%p\n", fp);
    fseek(fp, 0, SEEK_END);                                     //����fp��ƫ��λ��
    int fileSize;
    fileSize = ftell(fp);                                       //��ȡfp��λ��
    printf("fileSize=====%d\n", fileSize);
    char *strText;
    strText = (char*)malloc(fileSize*sizeof(char));
    //memset(strText, '\0', fileSize*sizeof(char));
    fread(strText, fileSize, sizeof(char), fp);
    strText[fileSize] = '\0';
    printf("strText=====%s\n", strText);
    return 0;
}
