#include <malloc.h>
#include <iostream>
using namespace std;

typedef struct node//��������ṹ��
{
    int data;//�ڵ�����
    node *next;//ָ��ṹ���ָ�룬��һ���ڵ�
}node;

node *create()//����������
{
    int i = 0;//���������ݵĸ���
    node *head, *p, *q;//��Щ�ı����ǽڵ�ĵ�ַ
    int x = 0;
    head = NULL;
    q = NULL;//��ʼ��q��q����ĩ�ڵ�
    p = NULL;
    while (1)
    {
        printf("please input the data:");
        scanf_s("%d", &x);
        if (x == 0)
            break;//dataΪ0ʱ��������
        p = (node *)malloc(sizeof(node));//����ÿ���������������
        p->data = x;
        if (++i == 1)//����ͷ��ָ��ָ����һ���ڵ�
        {
            head = p;
            q = p;
        }
        else
        {
            q->next = p;//���ӵ�����β��
            q = p;
        }
        q->next = NULL;/*β���ĺ��ָ��ΪNULL(��)*/
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
    while (p)                       /*ֱ�����qΪNULL����ѭ��*/
    {
        printf("%d ", p->data);     /*�������е�ֵ*/
        p = p->next;                /*ָ����һ�����*/
    }
}

node *search_node(node *head, int pos)                  //���ҵ�����posλ�õĽڵ㣬���ؽڵ��ָ�롣pos��0��ʼ��0����head�ڵ�
{
    node *p = head->next;
    if (pos < 0)                                        //posλ�ò���ȷ
    {
        printf("incorrect position to search node!");   //poseλ�ò���ȷ
        return NULL;
    }
    if (pos == 0)
    {
        return head;
    }
    if (pos == NULL)
    {
        printf("Link is empty!");                       //����Ϊ��
        return NULL;
    }
    while (--pos)
    {
        if ((p = p->next) == NULL)
        {
            printf("incorrect position to search node!");//����������
            break;
        }
    }
    return p;
}

node *insert_node(node *head, int pos, int data)        //������Ĳ���
{
    node *item = NULL;
    node *p;
    item = (node *)malloc(sizeof(node));
    item->data = data;
    if (pos == 0)                                       //����head����
    {
        head->next = item;                              //head������item
        return head;
    }
    p = search_node(head, pos);                         //���pos�Ľڵ�ָ��
    if(p!=NULL)
    {
        item->next = p->next;                           //itemָ��ԭpos�ڵ�ĺ�һ���ڵ�
        p->next = item;                                 //��item���뵽pos�ĺ���
    }
    return head;
}

node *delete_node(node *head, int pos)                  //ɾ���ڵ�
{
    node *item = NULL;
    node *p = head->next;
    if (p = NULL)
    {
        printf("link is empty!");
        return NULL;
    }
    p = search_node(head, pos - 1);                     //���λ��pos�ڵ��ָ��
    if (p != NULL&&p->next != NULL)
    {
        item = p->next;
        p->next = item->next;
        delete item;
    }
    return head;
}

node *reverse(node *head)                       //���������
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
    node *head = create();//����������
    print(head);//�������
    head = reverse(head);
    cout << "���ú�" << endl;
    print(head);
    return 0;
}
