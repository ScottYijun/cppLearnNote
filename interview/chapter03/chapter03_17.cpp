#include <stdio.h>

int main()
{
    const char *node1 = "abc";
    //char *const node2 = "abc";//C++ 11��֧������д��
    printf("node1====%s\n", node1);
    //node1[2] = 'k';//node1�ǳ���ָ�룬��ָ��������ǲ����޸ĵ�
    //*node1[2] = 'k';//node1�ǳ���ָ�룬��ָ��������ǲ����޸ĵ�
    //*node1 = "xyz";//node1�ǳ���ָ�룬��ָ��������ǲ����޸ĵ�
    node1 = "xyz";//��ȷ��node1ָ���ˡ�xyz�����ڵĵ�ַ��
    printf("node1====%s\n", node1);

    //node2[2] = 'k';
    //*node2[2] = 'k';
    //*node2 = "xyz";
    //node2 = "xyz";

    return 0;
}
