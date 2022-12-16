#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef char TreeDataType;

typedef struct TreeNode
{
	TreeDataType data;
	struct TreeNode* LeftChild;
	struct TreeNode* RightChild;
}TreeNode;

void PreOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PreOrder(root->LeftChild);
	PreOrder(root->RightChild);
}

//二叉树的最大深度
int MaxDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int LeftDepth = MaxDepth(root->LeftChild);
	int RightDepth = MaxDepth(root->RightChild);

	return LeftDepth > RightDepth ? LeftDepth + 1 : RightDepth + 1;
}




//int main()
//{
//	TreeNode* A = (TreeNode*)malloc(sizeof(TreeNode));
//	A->data = 'A';
//	A->LeftChild = NULL;
//	A->RightChild = NULL;
//
//	TreeNode* B = (TreeNode*)malloc(sizeof(TreeNode));
//	B->data = 'B';
//	B->LeftChild = NULL;
//	B->RightChild = NULL;
//
//	TreeNode* C = (TreeNode*)malloc(sizeof(TreeNode));
//	C->data = 'C';
//	C->LeftChild = NULL;
//	C->RightChild = NULL;
//
//	TreeNode* D = (TreeNode*)malloc(sizeof(TreeNode));
//	D->data = 'D';
//	D->LeftChild = NULL;
//	D->RightChild = NULL;
//
//	TreeNode* E = (TreeNode*)malloc(sizeof(TreeNode));
//	E->data = 'E';
//	E->LeftChild = NULL;
//	E->RightChild = NULL;
//
//	//TreeNode* F = (TreeNode*)malloc(sizeof(TreeNode));
//	//F->data = 'F';
//	//F->LeftChild = NULL;
//	//F->RightChild = NULL;
//
//
//	A->LeftChild = B;
//	A->RightChild = C;
//	B->LeftChild = D;
//	B->RightChild = E;
//	//D->LeftChild = F;
//
//	PreOrder(A);
//	printf("\n");
//	printf("MaxDepth:%d\n", MaxDepth(A));
//	return 0;
//}


//typedef struct TreeNode
//{
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;    
//}TreeNode;
//
//struct TreeNode* createTreeNode(int val) {
//    struct TreeNode* ret = malloc(sizeof(struct TreeNode));
//    ret->val = val;
//    ret->left = ret->right = NULL;
//    return ret;
//}
//
//struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
//{
//    //如果节点为空则创建一个树节点并返回
//    if (root == NULL)
//    {
//        root = createTreeNode(val);
//        return root;
//    }
//
//    struct TreeNode* pos = root;
//
//    while (pos != NULL)
//    {
//        //
//        if (val < pos->val)
//        {
//            if (pos->left == NULL) 
//            {
//                //插到左边
//                pos->left = createTreeNode(val);
//                break;
//            }
//
//            //无法插入，左移
//            else
//            {
//                pos = pos->left;
//            }
//        }
//        else
//        {
//            if (pos->right == NULL)
//            {
//                //插到右边
//                pos->right = createTreeNode(val);
//                break;
//            }
//            else
//            {
//                //无法插入，右移
//                pos = pos->right;
//            }
//        }
//    }
//
//    return root;
//}

//struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
//{
//    struct TreeNode* NewNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//
//    if (root == NULL)
//    {
//        return NewNode;
//    }
//
//    if (root->left == NULL && root->right == NULL)
//    {
//        if (val > root->val)
//        {
//            root->right = NewNode;
//        }
//        else
//        {
//            root->left = NewNode;
//        }
//    }
//    else if (val < root->val)
//    {
//        if (root->left == NULL)
//        {
//            root->left = NewNode;
//        }
//        else
//        {
//            insertIntoBST(root->left, val);
//        }
//    }
//    else if (val > root->val)
//    {
//        if (root->right == NULL)
//        {
//            root->right = NewNode;
//        }
//        else
//        {
//            insertIntoBST(root->right, val);
//        }
//    }
//
//    return root;
//}

//int main()
//{
//	TreeNode* A = (TreeNode*)malloc(sizeof(TreeNode));
//	A->data = 'A';
//	A->LeftChild = NULL;
//	A->RightChild = NULL;
//
//	TreeNode* B = (TreeNode*)malloc(sizeof(TreeNode));
//	B->data = 'B';
//	B->LeftChild = NULL;
//	B->RightChild = NULL;
//
//	TreeNode* C = (TreeNode*)malloc(sizeof(TreeNode));
//	C->data = 'C';
//	C->LeftChild = NULL;
//	C->RightChild = NULL;
//
//	TreeNode* D = (TreeNode*)malloc(sizeof(TreeNode));
//	D->data = 'D';
//	D->LeftChild = NULL;
//	D->RightChild = NULL;
//
//	TreeNode* E = (TreeNode*)malloc(sizeof(TreeNode));
//	E->data = 'E';
//	E->LeftChild = NULL;
//	E->RightChild = NULL;
//
//
//	A->LeftChild = B;
//	A->RightChild = C;
//	B->LeftChild = D;
//	B->RightChild = E;
//
//    return 0;
//}
