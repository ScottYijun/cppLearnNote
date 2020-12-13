#include <stdio.h>
#include <assert.h>

const char *strstr(const char* src, const char* sub)
{
    const char *bp;
    const char *sp;

    if (src == NULL || sub == NULL ) //�ж�src��sub����Ч��
    {
        return src;
    }
    while (*src) //����src�ַ�����Ҳ����src���Ӵ�������sub�Ƚ�
    {
        bp = src;	//����src�ı���
        sp = sub;	//����sub�ı���
        do
        {	//����sub�ַ���
            if (!*sp)//�������sub�ַ���������λ��
                return src;//��ʾ�ҵ���sub�ַ������˳�
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
