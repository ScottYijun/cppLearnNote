#include <stdio.h>
#include <stdlib.h>
//��������ΪDEBUG��Ԥ����������
#define DEBUG
//
int main() {
    int i = 0;
    char c;

    while (1) {
        i++;
        c = getchar();
        if (c != '\n') {
            getchar();
        }
        if (c == 'q' || c == 'Q')
        {
#ifdef DEBUG  //����ж�DEBUG�Ƿ񱻶�����
            printf("we got:%c,about to exit.\n", c);
#endif // DEBUG
            break;
        } else {
            printf("i=%d", i);
#ifdef DEBUG
            printf(",we got:%c", c);
#endif // DEBUG
            printf("\n");
        }
    }
    return 0;
}

