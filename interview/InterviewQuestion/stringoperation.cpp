#include <stdio.h>
#include <assert.h>
#include <string.h>

//https://www.cnblogs.com/heyonggang/p/3196922.html

//strcpy函数原型,功能把Src字符串复制到Dest
char *Mystrcpy(char *Dest, const char *Src)
{
    char *address = Dest;
    assert((NULL != Dest) && (NULL != Src));
    while((*Dest++ = *Src++) != '\0')
        NULL;
    return address; //返回一个指针地址    函数指针
}

//strncpy函数：利用标准库函数strncpy()，可以将一字符串的一部分拷贝到另一个字符串中。strncpy()函数有3个参数：第一个参数是目录字符串；第二个参数是源字符串；第三个参数是一个整数，代表要从源字符串拷贝到目标字符串中的字符数。
char *Mystrncpy(char *strDest, const char *strSrc, int n)
{
    char *address = strDest;
    assert((NULL != strDest) && (NULL != strSrc));
    while(n-- > 0)
        *strDest++ = *strSrc++;
    return address;
}

//strcmp函数:strcmp函数是C/C++中基本的函数，它对两个字符串进行比较，然后返回比较结果，函数形式如下：
//int strcmp(constchar*str1,constchar*str2);
//其中str1和str2可以是字符串常量或者字符串变量，返回值为整形。返回结果如下规定：
//①str1小于str2，返回负值或者-1（VC返回-1）；
//②str1等于str2，返回0；
//③str1大于str2，返回正值或者1（VC返回1）；
//strcmp函数实际上是对字符的ASCII码进行比较，
//实现原理如下：首先比较两个串的第一个字符，若不相等，则停止比较并得出两个ASCII码大小比较的结果；
//如果相等就接着比较第二个字符然后第三个字符等等。
//无论两个字符串是什么样，strcmp函数最多比较到其中一个字符串遇到结束符'/0'为止，就能得出结果。
int Mystrcmp(const char *str1, const char *str2)
{
    assert((NULL != str1) && (NULL != str2));
    int ret = 0;
    while(!(ret = (unsigned char*)*str1 - (unsigned char*)*str2) && (*str2))
    {
        str1++;
        str2++;
    }

    if(ret > 0)
        return 1;
    else if(ret < 0)
        return -1;

    return 0;
}

//strlen函数：获取字符串的长度，不包括'\0'
int Mystrlen(const char *str)
{
    assert(NULL != str);
    int len = 0;
    while((*str++) != '\0')
    {
        len++;
    }
    return len;
}

//strcat函数原型：
char *Mystrcat(char *strDest, const char *strSrc)
{
    char *address = strDest;//后文return address，故不能放在assert断言之后声明address
    assert((NULL != strDest) && (NULL != strSrc));//对源地址和目的地址加非0断言
    while(*strDest) //是while(*strDest != '\0')的简化形式
    {
        //若使用while(*strDest++)，则会出错，因为循环结束后strDest还会执行一次++,
        //那么strDest将指向'\0'的下一个位置。所以要在循环体内++；
        //因为要是*strDest最后指向该字符串的结束标志’\0’。
        strDest++;
    }

    while((*strDest++ = *strSrc++) != '\0')
        ;
    return address;
}

//memcpy函数原型：
//功能：从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中。
void *Mymemcpy(void *dest, const void *src, size_t count)
{
    assert((NULL != dest) && (NULL != src));//安全检查
    assert(count > 0);
    char *psrc = (char *)src;
    char *pdest = (char *)dest;
    while(count--)
    {
        *pdest++ = *psrc++;
    }
    return dest;
}
//strcpy和memcpy主要有以下3方面的区别。
//1、复制的内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。
//2、复制的方法不同。strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，所以容易溢出。memcpy则是根据其第3个参数决定复制的长度。
//3、用途不同。通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy。

//char *strstr(char *str1,char *str2);
//在字符串str1中，寻找字串str2，若找到返回找到的位置，否则返回NULL。
//例如：src = "adabdef"; sub = "abd";,这里返回的是第二个a所在的地址，打印它的值是abdef而不是sub的值abd.
const char *Mystrstr(const char *src, const char *sub)
{
    const char *tsrc = src;//tsrc指向的内容不可变，自身指针可以变
    const char *tsub = sub;

    if(!src || !sub)
    {
        return tsrc;
    }


    while(*tsrc)
    {
        const char *flag = tsrc;//设置标志位，方便回滚
        tsub = sub;
        printf("flag====%s\ttsub=====%s\n", flag, tsub);
        //开始进行比较，如果第一个字符相等，继续循环比较下一个字符。
        while(*tsrc ==*tsub && *tsrc != '\0')
        {
            tsrc++;
            tsub++;
        }
        //上面循环完毕，有如下在种情况
        if(!*tsub)
        {
            //子字符串tsub已达到'\0'，说明在src中已找到子字符串
            return flag;//返回找到子串的起始位置
        }
        if(!*tsrc)
        {
            //走到这里，tsrc到达\0,而tsub没有到达'\0',没有找到
            return NULL;
        }
        //走到这里，没有匹配成功，继续从下一位开始匹配整个子串
        tsrc++;
    }
    return NULL;
}

//void *memset(void *s, int ch, size_t n);
//将s中前n个字节 （typedef unsigned int size_t n）用 ch 替换并返回 s 。
//memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法。
void *Mymemset(void *src, int c, size_t n)
{
    if(nullptr == src || n <= 0)
        return nullptr;
    char *temp = (char *)src;
    while(n-- > 0)
    {
        *temp++ = c;
    }
    return src;
}

//原型 char *strtok(char *str, const char *delimiters);
//分解字符串为一组字符串。str为要分解的字符，delimiters为分隔符字符
//（如果传入字符串，则传入的字符串中每个字符均为分割符）。
//首次调用时，str指向要分解的字符串，之后再次调用要把s设成NULL。


//int main()
//{
//    char a1[20] = "hello,";
//    char b1[20] = "world!";
//    Mystrcpy(a1, b1);
//    printf("a1====%s\n", a1);
//    char a2[20] = "\0";
//    char b2[20] = "world!";
//    Mystrncpy(a2, b2, 5);
//    printf("a2====%s\n", a2);
//    char a3[20] = "ssdsf";
//    char b3[20] = "asfsdfsdf!";
//    int ret = Mystrcmp(a3, b3);
//    printf("a3====%d\n", ret);

//    printf("len====%d\n", Mystrlen(b3));
//    char a5[20] = "hello,";
//    char b5[20] = "world!";
//    Mystrcat(a5, b5);
//    printf("a5====%s\n", a5);
//    char a6[20] = "hello,";
//    char b6[20] = "world!";
//    Mymemcpy(a6, b6, 8);
//    printf("a6====%s\n", a6);

//    char str[] = "This is a simple string";
//    char *pch;
//    pch = strstr(str, "simple");
//    printf("pch====%s\n", pch);
//    printf("str====%s\n", str);

//    char a7[20] = "adabdef";
//    char b7[20] = "abd";
//    const char *sub;
//    sub = Mystrstr(a7, b7);
//    printf("sub====%s\n", sub);

//    char a8[] = "this is memset example.";
//    Mymemset(a8, '?', 8);
//    printf("a8====%s\n", a8);
//    //在第一次调用时，strtok(char *s, const char *delim)必需给予参数s 字符串，
//    //往后的调用则将参数s 设置成NULL。每次调用成功则返回下一个分割后的字符串指针。
//    //返回值：返回下一个分割后的字符串指针，如果已无从分割则返回NULL。
//    char a9[] = "this*is*memset*example.";
//    char *p;
//    p = strtok(a9, "*");
//    while(nullptr != p)
//    {
//        printf("%s\n", p);
//        p = strtok(nullptr, "*");
//    }
//    return 0;
//}
