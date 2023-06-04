#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int element;

typedef struct Treenode{
    element data;
    struct Treenode *left, *right; 
}Treenode;

typedef struct{
    Treenode *Stack[N];
    int top;
}StacktType;

typedef struct{
    Treenode *Queue[N];
    int front, rear;
}QueueType;

void initStack(StacktType *S)
{
    S->top = -1;
}

void initQueue(QueueType *Q)
{
    Q->front = Q->rear = 0;
}

int isEmpty(QueueType *Q)
{
    if(Q->front == Q->rear)
        return 1;
    else    
        return 0;
}

void enqueue(QueueType *Q, Treenode *e)
{
    Q->rear = (Q->rear + 1) % N;
    Q->Queue[Q->rear] = e;
}

Treenode* dequeue(QueueType *Q)
{
    Q->front = (Q->front + 1) % N;
    return Q->Queue[Q->front];
}

void levelOrder(Treenode *root)
{
    QueueType Q;
    initQueue(&Q);

    enqueue(&Q, root);

    while(!isEmpty(&Q))
    {
        root = dequeue(&Q);
        printf("[%d] ", root->data);

        if(root->left != NULL)
            enqueue(&Q, root->left);

        if(root->right != NULL)
            enqueue(&Q, root->right);
    }
}

void push(StacktType *S, Treenode* e)
{
    if(S->top < N-1)
    {
        S->top++;
        S->Stack[S->top] = e;
    }
}

Treenode* pop(StacktType *S)
{
    Treenode *e = NULL;
    if(S->top >= 0)
        e = S->Stack[S->top];
    
    S->top--;

    return e;
}

void iterOrder(Treenode *root)
{
    StacktType S;
    initStack(&S);

    while(1)
    {
        for( ; root!=NULL ; root=root->left)
            push(&S, root);

        root = pop(&S);

        if(root == NULL) break;

        printf("[%d] ", root->data);

        root = root->right;
    }
}

Treenode* makeNode(element e, Treenode* left, Treenode* right)
{
    Treenode *node = (Treenode*)malloc(sizeof(Treenode));

    node->data = e;
    node->left = left;
    node->right = right;

    return node;
}

void preOrder(Treenode *root)
{
    if (root != NULL)
    {
        printf("[%d] ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Treenode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("[%d] ", root->data);
        inOrder(root->right);
    }
}
void postOrder(Treenode *root)
{
    if (root != NULL)
    {
        
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ", root->data);
    }
}

int main(){
    Treenode *N4 = makeNode(1, NULL, NULL);
    Treenode *N6 = makeNode(16, NULL, NULL);
    Treenode *N7 = makeNode(25, NULL, NULL);

    Treenode *N2 = makeNode(4, N4, NULL);
    Treenode *N3 = makeNode(20, N6, N7);

    Treenode *N1 = makeNode(15, N2, N3); // 루트 노드

    // printf("pre : "); preOrder(N1); printf("\n");
    // printf("in : "); inOrder(N1); printf("\n");
    // printf("post : "); postOrder(N1); printf("\n");

    iterOrder(N1);
    // levelOrder(N1);

    printf("\n\n\n");
    return 0;
}