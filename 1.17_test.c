#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//void InOrder(TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	InOrder(root->left);
//	printf("%d ", root->val);
//	InOrder(root->right);
//}

//void InOrder(TreeNode* root, int* OrderNums, int* sz, int k)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	if ((*sz) < k)
//	{
//		InOrder(root->left, OrderNums, sz, k);
//		OrderNums[(*sz)++] = root->val;
//		InOrder(root->right, OrderNums, sz, k);
//	}
//}

//int kthLargest(struct TreeNode* root, int k)
//{
//	//二叉搜索树的中序遍历为递增序列
//	int* inOrderNums = (int*)malloc(sizeof(int) * k);
//	int sz = 0;
//	InOrder(root, inOrderNums, &sz, k);
//
//	return inOrderNums[k - 1];
//}



//int TreeSz(TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	return TreeSz(root->left) + TreeSz(root->right) + 1;
//}
//
//void InOrder(TreeNode* root, int* OrderNums, int* sz)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	InOrder(root->left, OrderNums, sz);
//	OrderNums[(*sz)++] = root->val;
//	InOrder(root->right, OrderNums, sz);
//}
//
//int kthLargest(struct TreeNode* root, int k)
//{
//	//二叉搜索树的中序遍历为递增序列
//	int TreeSize = TreeSz(root);
//	int* inOrderNums = (int*)malloc(sizeof(int) * TreeSize);
//	int sz = 0;
//	InOrder(root, inOrderNums, &sz);
//
//	return inOrderNums[sz - k];
//}


void InOrderBack(struct TreeNode* root, int* OrderNums, int* sz, int k)
{
	if (root == NULL || (*sz) == k)
	{
		return;
	}

	InOrderBack(root->right, OrderNums, sz, k);
	if ((*sz) < k)
	{
		OrderNums[(*sz)++] = root->val;
	}
	InOrderBack(root->left, OrderNums, sz, k);
}

int kthLargest(struct TreeNode* root, int k)
{
	//二叉搜索树的中序遍历倒序为递减序列
	int* inOrderNums = (int*)malloc(sizeof(int) * k);
	int sz = 0;
	InOrderBack(root, inOrderNums, &sz, k);

	return inOrderNums[k - 1];
}

int main()
{
	TreeNode* A = (TreeNode*)malloc(sizeof(TreeNode));
	A->val = 2;
	A->left = NULL;
	A->right = NULL;

	TreeNode* B = (TreeNode*)malloc(sizeof(TreeNode));
	B->val = 1;
	B->left = NULL;
	B->right = NULL;

	TreeNode* C = (TreeNode*)malloc(sizeof(TreeNode));
	C->val = 3;
	C->left = NULL;
	C->right = NULL;

	A->left = B;
	A->right = C;

	int ret = kthLargest(A, 1);
	printf("%d\n", ret);
	//printf("%d\n", TreeSz(A));

	return 0;
}