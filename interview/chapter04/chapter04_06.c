#include <stdio.h>
#include <assert.h>

void *memcpy2(void *memTo, const void *memFrom, size_t size)
{
    assert((memTo != NULL) && (memFrom != NULL));   //memTo和memFrom必须有效
    char *tempFrom = (char *)memFrom;               //保存memFrom的首地址
    char *tempTo = (char *)memTo;                   //保存memTo的首地址

    while (size-- > 0) {                            //循环size次，复制memFrom的值到memTo中
        *tempTo++ = *tempFrom++;
    }
    return memTo;
}

int main()
{
    char strSrc[] = "Hello World";                  //将被复制的字符数组
    char strDest[20];                               //目的字符数组

    memcpy2(strDest, strSrc, 4);                    //复制strSrc的前4个字符到strDest中
    strDest[4] = '\0';                              //把strDest的第5个元素赋为结束符'\0'
    printf("strDest:%s\n", strDest);

    return 0;
}

