#include <stdio.h>

#define STR(s)	#s	//ʹ��#�Ѻ�������һ���ַ���
#define CONS(a,b)  (int)(a##e##b)	//�����##���������������һ��  Ҳ����aeb

int main()
{
    printf(STR(vck));
    printf("\n");
    printf("%d\n", CONS(2, 3));  //Ҳ����2e3=2000
    return 0;
}
