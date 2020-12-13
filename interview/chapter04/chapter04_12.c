#include <stdio.h>
#include <assert.h>

const char *strstr(const char* src, const char* sub)
{
    const char *bp;
    const char *sp;

    if (src == NULL || sub == NULL ) //判断src与sub的有效性
    {
        return src;
    }
    while (*src) //遍历src字符串，也就是src的子串挨个与sub比较
    {
        bp = src;	//用于src的遍历
        sp = sub;	//用于sub的遍历
        do
        {	//遍历sub字符串
            if (!*sp)//如果到了sub字符串结束符位置
                return src;//表示找到了sub字符串，退出
        } while (*bp++ == *sp++);
        src += 1;
    }

    return NULL;
}

int main()
{
    char p[] = "12345";
    char q[] = "34";
    char *r = strstr(p, q);
    printf("r:%s\n", r);

    return 0;
}
