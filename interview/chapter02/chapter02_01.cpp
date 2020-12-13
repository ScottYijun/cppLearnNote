#include <stdio.h>
#include <stdlib.h>
//定义了名为DEBUG的预处理器常量
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
#ifdef DEBUG  //这边判断DEBUG是否被定义了
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

