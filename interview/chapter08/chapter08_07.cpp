#include <malloc.h>
#include <iostream>
using namespace std;

typedef struct node//定义链表结构体
{
    int data;//节点内容
    node *next;//指向结构体的指针，下一个节点
}node;

node *create()//创建单链表
{
    int i = 0;//链表中数据的个数
    node *head, *p, *q;//这些的本质是节点的地址
    int x = 0;
    head = NULL;
    q = NULL;//初始化q，q代表末节点
    p = NULL;
    while (1)
    {
        printf("please input the data:");
        scanf_s("%d", &x);
        if (x == 0)
            break;//data为0时创建结束
        p = (node *)malloc(sizeof(node));//用于每次输入链表的数据
        p->data = x;
        if (++i == 1)//链表头的指针指向下一个节点
        {
            head = p;
            q = p;
        }
        else
        {
            q->next = p;//连接到链表尾端
            q = p;
        }
        q->next = NULL;/*尾结点的后继指针为NULL(空)*/
    }
    return head;
}

int length(node *head)
{
    int len = 0;
    node *p;
    p = head->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void print(node *head)
{
    node *p;
    p = head;
    while (p)                       /*直到结点q为NULL结束循环*/
    {
        printf("%d ", p->data);     /*输出结点中的值*/
        p = p->next;                /*指向下一个结点*/
    }
}

node *search_node(node *head, int pos)                  //查找单链表pos位置的节点，返回节点的指针。pos从0开始，0返回head节点
{
    node *p = head->next;
    if (pos < 0)                                        //pos位置不正确
    {
        printf("incorrect position to search node!");   //pose位置不正确
        return NULL;
    }
    if (pos == 0)
    {
        return head;
    }
    if (pos == NULL)
    {
        printf("Link is empty!");                       //链表为空
        return NULL;
    }
    while (--pos)
    {
        if ((p = p->next) == NULL)
        {
            printf("incorrect position to search node!");//超出链表返回
            break;
        }
    }
    return p;
}

node *insert_node(node *head, int pos, int data)        //单链表的插入
{
    node *item = NULL;
    node *p;
    item = (node *)malloc(sizeof(node));
    item->data = data;
    if (pos == 0)                                       //插在head后面
    {
        head->next = item;                              //head后面是item
        return head;
    }
    p = search_node(head, pos);                         //获得pos的节点指针
    if(p!=NULL)
    {
        item->next = p->next;                           //item指向原pos节点的后一个节点
        p->next = item;                                 //把item插入到pos的后面
    }
    return head;
}

node *delete_node(node *head, int pos)                  //删除节点
{
    node *item = NULL;
    node *p = head->next;
    if (p = NULL)
    {
        printf("link is empty!");
        return NULL;
    }
    p = search_node(head, pos - 1);                     //获得位置pos节点的指针
    if (p != NULL&&p->next != NULL)
    {
        item = p->next;
        p->next = item->next;
        delete item;
    }
    return head;
}

node *reverse(node *head)                       //链表的逆置
{
    node *next;
    node *prev = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
int main()
{
    node *head = create();//创建单链表
    print(head);//输出链表
    head = reverse(head);
    cout << "逆置后：" << endl;
    print(head);
    return 0;
}
