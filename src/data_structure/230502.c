// #include <stdio.h>
// #include <stdlib.h>

// #define N 10

// typedef int element;

// typedef struct TreeNode{
//     element key;
//     struct TreeNode *left, *right;
// }TreeNode;

// typedef struct 
// {
//     TreeNode *Stack[N]; 
//     int top; // 스택
// }StackType;

// typedef struct 
// {
//     TreeNode *Queue[N];
//     int front, rear; // 큐
// }QueueType;

// void initStack(StackType *S)
// {
//     S->top = -1;
// }

// void initQueue(QueueType *Q)
// {
//     Q->front = Q->rear = 0; // 원형 큐
// }

// int isEmpty(QueueType *Q)
// {
//     return Q->front == Q->rear; // 원형 큐
// }

// void enqueue(QueueType * Q, TreeNode *e)
// {
//     // isfull 체크 생략
//     Q->rear = (Q->rear + 1) % N;
//     Q->Queue[Q->rear] = e;
// }

// TreeNode* dequeue(QueueType *Q)
// {
//     // isempty 체크 생략
//     Q->front = (Q->front + 1) % N;
//     return Q->Queue[Q->front];
// }

// void levelOrder(TreeNode *root)
// {
//     QueueType Q;
//     initQueue(&Q);

//     enqueue(&Q, root);
//     while(!isEmpty(&Q))
//     {
//         root = dequeue(&Q);
//         printf("[%d] ", root->key);

//         if(root->left != NULL)
//             enqueue(&Q, root->left);

//         if(root->right != NULL)
//             enqueue(&Q, root->right);
//     }
// }

// void push(StackType *S, TreeNode *e)
// {
//     if(S->top < N-1)
//         S->Stack[++S->top] = e;
// }

// TreeNode* pop(StackType *S)
// {
//     TreeNode *e = NULL;
//     if(S->top >= 0)
//         e = S->Stack[S->top--];

//     return e;
// }

// void iterOrder(TreeNode *root) // 중위 순회
// {
//     StackType S;
//     initStack(&S);

//     while (1)
//     {
//         for( ; root != NULL ; root = root->left) // 반복문을 돌려서 중위순회를 함. 노드 입장에서 왼쪽을 먼저 방문, 그 다음 노드의 키값, 그 다음 오른쪽
//             push(&S, root); // 스택에 노드를 넌다

//         root = pop(&S);
        
//         if(root == NULL) break; // while문 빠져나가기용

//         printf("[%d] ", root->key);

//         root = root->right;
//     }
// }

// TreeNode* makeNode(element key, TreeNode *left, TreeNode *right)
// {
//     TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
//     node->key = key;
//     node->left = left;
//     node->right = right;

//     return node;
// }

// void preOrder(TreeNode *root)
// {
//     if(root != NULL)
//     {
//         printf("[%d] ", root->key);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }

// void inOrder(TreeNode *root)
// {
//     if(root != NULL)
//     {
//         inOrder(root->left);
//         printf("[%d] ", root->key);
//         inOrder(root->right);
//     }
// }

// void postOrder(TreeNode *root)
// {
//     if(root != NULL)
//     {
//         postOrder(root->left);
//         postOrder(root->right);
//         printf("[%d] ", root->key);
//     }
// }


// int main()
// {
//     TreeNode *N4 = makeNode(1, NULL, NULL);
//     TreeNode *N6 = makeNode(16, NULL, NULL);
//     TreeNode *N7 = makeNode(25, NULL, NULL);

//     TreeNode *N2 = makeNode(4, N4, NULL);
//     TreeNode *N3 = makeNode(20, N6, N7);

//     TreeNode *N1 = makeNode(15, N2, N3);

//     // printf("pre : "); preOrder(N1); printf("\n");
//     // printf("in : "); inOrder(N1); printf("\n");
//     // printf("post : "); postOrder(N1); printf("\n");

//     // iterOrder(N1); // 중위 순회
//     levelOrder(N1); // 레벨 순회

//     return 0;
// }   




#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode* makeNode(element key)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void preOrder(TreeNode *root)
{
    if(root != NULL)
    {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("[%d] ", root->key);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ", root->key);
    }
}

TreeNode* insertNode(TreeNode* root, element key)
{
    if(root == NULL)
        return makeNode(key);
    
    if(key < root->key)
        root->left = insertNode(root->left, key);
    else if(key > root->key)
        root->right = insertNode(root->right, key);
    
    return root;
}   

int main()
{
    TreeNode *root = NULL;
// 이진탐색트리
    root = insertNode(root, 35); root = insertNode(root, 68); 
    root = insertNode(root, 99); root = insertNode(root, 18);
    root = insertNode(root, 7); root = insertNode(root, 3);
    root = insertNode(root, 12); root = insertNode(root, 26);
    root = insertNode(root, 22); root = insertNode(root, 30);

    preOrder(root);
    return 0;
}   