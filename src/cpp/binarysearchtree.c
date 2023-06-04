#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
}TreeNode;

void preOrder(TreeNode* root)
{
    if(root != NULL)
    {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}   

TreeNode* makeNode(element key) // 깡통 노드 만들어서 반환
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

TreeNode* insertNode(TreeNode* root, element key)
{
    if(root == NULL)
        root = makeNode(key);

    if(key < root->key)
        root->left = insertNode(root->left, key);
    else if(key > root->key)
        root->right = insertNode(root->right, key);


    return root;
}

TreeNode* deleteNode(TreeNode* root, element key)
{
    if(root == NULL)
        return NULL; // error check

    if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    
}

int main(){
    TreeNode *root = NULL;

    root = insertNode(root, 35);
    root = insertNode(root, 68);
    root = insertNode(root, 18);

    root = insertNode(root, 7);
    root = insertNode(root, 26);
    root = insertNode(root, 99);

    root = insertNode(root, 3);
    root = insertNode(root, 12);
    root = insertNode(root, 22);
    root = insertNode(root, 30);

    preOrder(root);


    printf("\n\n\n");
    return 0;
}
