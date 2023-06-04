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
//     S->top = -1; // 스택 초기화.
// }

// void initQueue(QueueType *Q)
// {
//     Q->front = Q->rear = 0; // 원형 큐
// }

// int isEmpty(QueueType *Q)
// {
//     return Q->front == Q->rear; // front와 rear가 같으면 1을 반환, 다르면 0을 반환
// }

// void enqueue(QueueType * Q, TreeNode *e) // rear 증가시키고 넣기
// {
//     // isfull 체크 생략
//     Q->rear = (Q->rear + 1) % N; // 원형 큐
//     Q->Queue[Q->rear] = e;
// }

// TreeNode* dequeue(QueueType *Q) // front 증가시키고 제거하기
// {
//     // isempty 체크 생략
//     Q->front = (Q->front + 1) % N; // 원형 큐
//     return Q->Queue[Q->front];
// }



// /*
// 1. 트리의 루트 노드를 큐에 넣습니다.
// 2. 큐가 빌 때까지 다음의 동작을 반복합니다:
//    1. 큐에서 노드를 하나 꺼냅니다(Dequeue).
//    2. 해당 노드를 "방문"합니다. 보통은 노드의 값을 출력하거나, 해당 노드에서 필요한 작업을 수행합니다.
//    3. 꺼낸 노드의 왼쪽 자식 노드와 오른쪽 자식 노드(만약 있을 경우)를 큐에 넣습니다(Enqueue).

// 이렇게 하면, 먼저 큐에 들어간 노드가 먼저 방문되므로 (이것이 큐의 성질입니다) 각 레벨의 노드들이 왼쪽에서 오른쪽 순서로, 그리고 위에서 아래로 순서로 방문되게 됩니다. 
// */
// void levelOrder(TreeNode *root) // 레벨 순회
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
//     TreeNode *e = NULL; // 초기화
//     if(S->top >= 0)
//         e = S->Stack[S->top--];

//     return e;
// }

// void iterOrder(TreeNode *root) // 중위 순회. 반복적으로 스택을 이용
// {
//     StackType S;
//     initStack(&S);

//     while (1)
//     {
//         // 밑의 root=root->right에서 root에 20이 들어가는 순간에, 아래 for문에 들어간다.
//         for( ; root != NULL ; root = root->left) // 반복문을 돌려서 중위순회를 함. 노드 입장에서 왼쪽을 먼저 방문, 그 다음 노드의 키값, 그 다음 오른쪽
//             push(&S, root); // 스택에 노드를 넌다

//         root = pop(&S);
        
//         if(root == NULL) break; // 스택이 비어있으면 종료

//         printf("[%d] ", root->key); // 노드방문(출력)
 
//         root = root->right; 
// // 네, 그렇습니다. root->right의 값이 NULL이라면 root = root->right; 코드를 실행하게 되면, root에는 NULL 값이 할당됩니다.
// // 이렇게 root에 NULL이 할당된 후 다시 root = pop(&S);를 실행하면, 이전에 스택에 push 되었던 노드가 root로 설정됩니다. 
// // 이 과정을 통해 오른쪽 자식 노드가 없는 현재 노드에서 부모 노드나 다른 서브트리의 노드로 "되돌아갈" 수 있게 됩니다.
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

//     iterOrder(N1); // 중위 순회
//     // levelOrder(N1); // 레벨 순회

//     printf("\n\n");
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

void preOrder(TreeNode *root) // 전위 순환
{
    if(root != NULL)
    {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root) // 중위 순환
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("[%d] ", root->key);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root) // 후위 순환
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ", root->key);
    }
}

/*
이진 탐색 트리(Binary Search Tree)에서 삽입 연산을 수행하는 방법은 다음과 같습니다:

1. 먼저 삽입하려는 값을 가진 노드를 생성합니다. 

2. 트리가 비어있다면, 새로운 노드를 루트 노드로 만듭니다.

3. 트리가 비어있지 않다면, 루트 노드부터 시작하여 삽입하려는 값과 비교합니다. 
    - 삽입하려는 값이 현재 노드의 값보다 작다면, 현재 노드의 왼쪽 자식 노드로 이동합니다. 왼쪽 자식 노드가 없다면, 새로운 노드를 왼쪽 자식 노드로 설정합니다.
    - 삽입하려는 값이 현재 노드의 값보다 크다면, 현재 노드의 오른쪽 자식 노드로 이동합니다. 오른쪽 자식 노드가 없다면, 새로운 노드를 오른쪽 자식 노드로 설정합니다.

4. 위 과정을 반복하여 적절한 위치를 찾아 삽입하려는 값을 가진 노드를 배치합니다. 이 때, 이진 탐색 트리의 속성이 유지되어야 합니다. 
즉, 각 노드의 왼쪽 서브트리에 있는 모든 노드의 값은 현재 노드의 값보다 작아야 하고, 오른쪽 서브트리에 있는 모든 노드의 값은 현재 노드의 값보다 커야 합니다.
*/
TreeNode* insertNode(TreeNode* root, element key) // 삽입 연산
{
    if(root == NULL)
        return makeNode(key);
    
    if(key < root->key)
        root->left = insertNode(root->left, key);
    else if(key > root->key)
        root->right = insertNode(root->right, key);
    
    return root;
}   

TreeNode* minValueNode(TreeNode *root)
{
    TreeNode* p = root;
    while(p->left != NULL)
    {
        p=p->left;
    }
    return p;
}

TreeNode* deleteNode(TreeNode *root, element key)
{
    if(root == NULL) // 삭제하려는 노드가 없는 경우. 에러 발생을 막는 것
        return NULL;
    
    if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else // key를 찾았다면
    {
        if(root->left == NULL) // 단말 노드 또는 오른쪽 자식만 있는 경우
        {
            TreeNode *temp = root->right; // 일단 기억을 시킴
            free(root);
            return temp;
        }
        else if(root->right == NULL) // 왼쪽 자식만 있는 경우
        {
            TreeNode *temp = root->left; // 일단 기억을 시킴
            free(root);
            return temp;
        }
        else // 양쪽 자식이 다 있는 경우
        {
            TreeNode *temp = minValueNode(root->right); // 계승자
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    return root;
}

int getNodeCount(TreeNode *root) // 노드의 개수
{
    int count = 0; // 노드 개수 세는 변수

    if(root != NULL)
        count = 1+getNodeCount(root->left) + getNodeCount(root->right);

    return count;
}

int getLeafCount(TreeNode *root) // 단말노드의 개수
{
    int count = 0; // 노드 개수

    if(root != NULL)
    {
        if(root->left == NULL && root->right == NULL)
            return 1;
        else    
            count = getLeafCount(root->left) + getLeafCount(root->right);
    }
    return count;
}

int main()
{
    TreeNode *root = NULL;
/* 이진탐색트리
1. 모든 원소의 키는 유일한 키를 가진다.
2. 왼쪽 서브 트리 키들은 루트 키보다 작다.
3. 오른쪽 서브 트리 키들은 루트 키보다 크다.
4. 왼쪽과 오른쪽 서브 트리도 이진 탐색 트리이다.
*/

    root = insertNode(root, 35); root = insertNode(root, 68); 
    root = insertNode(root, 99); root = insertNode(root, 18);
    root = insertNode(root, 7); root = insertNode(root, 3);
    root = insertNode(root, 12); root = insertNode(root, 26);
    root = insertNode(root, 22); root = insertNode(root, 30);

    preOrder(root); getchar();

    deleteNode(root, 18);

    preOrder(root); 

    printf("node : %d, leaf node : %d", getNodeCount(root), getLeafCount(root));

    printf("\n\n\n");
    return 0;
}   

/*
이진탐색트리의 탐색, 삽입, 삭제 연산의 시간복잡도는 트리의 높이에

*/