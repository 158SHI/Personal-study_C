#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

void _Exchange(struct TreeNode** left, struct TreeNode** right)
{
    if (left == NULL && right == NULL)
    {
        return;
    }

    if (*left == NULL && *right != NULL)
    {
        *left = *right;
        *right = NULL;
        return;
    }
    else if (*left != NULL && *right == NULL)
    {
        *right = *left;
        *left = NULL;
        return;
    }
    else
    {
        int tmp = (*left)->val;
        (*left)->val = (*right)->val;
        (*right)->val = tmp;
    }

    _Exchange((*left)->left, (*right)->right);
    _Exchange((*left)->right, (*right)->left);

    //return;
}

struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    //struct TreeNode* s = root->left;
    //struct TreeNode* t = root->right;

    _Exchange(&(root->left), &(root->right));

    return root;
}

void PreOrder(TreeNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    printf("%d ", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{
    TreeNode* t1 = (TreeNode*)malloc(sizeof(TreeNode));
    t1->val = 1;
    t1->left = NULL;
    t1->right = NULL;

    TreeNode* t2 = (TreeNode*)malloc(sizeof(TreeNode));
    t2->val = 2;
    t2->left = NULL;
    t2->right = NULL;

    TreeNode* t3 = (TreeNode*)malloc(sizeof(TreeNode));
    t3->val = 3;
    t3->left = NULL;
    t3->right = NULL;

    t1->left = t2;
    t1->right = NULL;

    invertTree(t1);

    PreOrder(t1);
    return 0;
}

//struct TreeNode* invertTree(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return NULL;
//    }
//
//    struct TreeNode* left = invertTree(root->left);
//    struct TreeNode* right = invertTree(root->right);
//
//    root->left = right;
//    root->right = left;
//
//    return root;
//}