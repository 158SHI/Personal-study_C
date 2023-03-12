#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int TreeDataType;

typedef struct TreeNode
{
	TreeDataType data;
	struct TreeNode* leftChild;
	struct TreeNode* rightChild;
}TreeNode;

TreeNode* BuyNode(TreeDataType x)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	assert(newNode);
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	newNode->data = x;
	return newNode;
}

int main()
{
	TreeNode* root = BuyNode(1);
	TreeNode* n1 = BuyNode(2);
	TreeNode* n2 = BuyNode(3);
	TreeNode* n3 = BuyNode(4);
	TreeNode* n4 = BuyNode(5);
	root->leftChild = n1;
	root->rightChild = n2;
	n1->leftChild = n3;
	n1->rightChild = n4;

	return 0;
}