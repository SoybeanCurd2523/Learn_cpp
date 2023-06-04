#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode{ // 트리 ( 완전 이진 트리 : 왼쪽부터 오른쪽 채워짐 )
    element key; // 데이터
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 자식 노드를 가르키는 포인터. 자기참조구조체
}TreeNode;

TreeNode* makeNode(element key, TreeNode *left, TreeNode *right)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = left;
    node->right = right;

    return node;
}

void preOrder(TreeNode *root) // 전위 순회. 루트->왼쪽 서브트리 ->오른쪽 서브트리
{
    if(root != NULL)
    {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root) // 중위 순회. 왼쪽 서브트리->루트->오른쪽 서브트리
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("[%d] ", root->key);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root) // 후위 순회. 왼쪽 서브트리 -> 오른쪽 서브트리->루트
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ", root->key);
    }
}


int main()
{
    TreeNode *N4 = makeNode(1, NULL, NULL);
    TreeNode *N6 = makeNode(16, NULL, NULL);
    TreeNode *N7 = makeNode(25, NULL, NULL);

    TreeNode *N2 = makeNode(4, N4, NULL);
    TreeNode *N3 = makeNode(20, N6, N7);

    TreeNode *N1 = makeNode(15, N2, N3); // 루트 노드

    printf("pre : "); preOrder(N1); printf("\n");
    printf("in : "); inOrder(N1); printf("\n");
    printf("post : "); postOrder(N1); printf("\n");

    return 0;
}   

// #include <stdio.h>
// #include <stdlib.h>

// typedef int element;
// typedef struct Treenode{
//     element data;
//     struct Treenode* left, *right; 
// }Treenode;

// int main(){
//     Treenode *n1, *n2, *n3;
//     n1 = (Treenode*)malloc(sizeof(Treenode));
//     n2 = (Treenode*)malloc(sizeof(Treenode));
//     n3 = (Treenode*)malloc(sizeof(Treenode));

//     n1->data = 10;
//     n1->left = n2;
//     n1->right = n3;

//     n2->data = 20;
//     n2->left = NULL;
//     n2->right = NULL;

//     n3->data = 30;
//     n3->left = NULL;
//     n3->right = NULL;

//     free(n1); free(n2); free(n3);

//     return 0;
// }