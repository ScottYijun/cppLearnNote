#include <stdio.h>
#include <malloc.h>

struct Tag_Node
{
    struct Tag_Node *left;
    struct Tag_Node *right;
    int value;
};

typedef struct Tag_Node TNode;

TNode *root = NULL;

void append(int N);
void print();

int main()
{
    append(63);
    append(45);
    append(32);
    append(77);
    append(96);
    append(21);
    append(17);
    printf(" head: %d\n", root->value);
    print();
    return 0;
}

void append(int N)
{
    TNode *NewNode = (TNode *)malloc(sizeof(TNode));
    NewNode->value = N;
    NewNode->left = NULL;   //初始化left
    NewNode->right = NULL;  //初始化right
    if(root == NULL)
    {

        root = NewNode;
        return;
    }
    else
    {
        TNode *temp;
        temp = root;
        printf(" N = %d temp->value = %d temp->left = %p temp->right = %p\n", N, temp->value, temp->left, temp->right);
        while((N >= temp->value && temp->left != NULL) ||
                (N < temp->value && temp->right != NULL))
        {
            while(N >= temp->value && temp->left != NULL)
                temp = temp->left;
            while(N < temp->value && temp->right != NULL)
                temp = temp->right;
        }
        if(N >= temp->value)
        {
            temp->left = NewNode;
            NewNode->right = temp;  //形成双向链表
        }
        else
        {
            temp->right = NewNode;
            NewNode->left = temp;   //形成双向链表
        }
        return;
    }
}

void print()
{
    TNode *leftside = NULL;
    if(root == NULL)
    {
        printf("There is not any element\n");
        return;
    }
    leftside = root->left;
    while(1)
    {
        if(leftside->left == NULL)
            break;
        leftside = leftside->left;
    }

    while(leftside != NULL)
    {
        printf(" %d ", leftside->value);
        leftside = leftside->right;
    }
}














