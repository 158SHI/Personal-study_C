#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* ChildLeft;
	struct BinaryTreeNode* ChildRight;
}BTNode;

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);//访问根
	PrevOrder(root->ChildLeft);//左子树
	PrevOrder(root->ChildRight);//右子树
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->ChildLeft);
	printf("%c ", root->data);
	InOrder(root->ChildRight);
}

void BackOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	BackOrder(root->ChildLeft);
	BackOrder(root->ChildRight);
	printf("%c ", root->data);

}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->ChildLeft = NULL;
	A->ChildRight = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->ChildLeft = NULL;
	B->ChildRight = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->ChildLeft = NULL;
	C->ChildRight = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->ChildLeft = NULL;
	D->ChildRight = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->ChildLeft = NULL;
	E->ChildRight = NULL;

	BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	F->data = 'F';
	F->ChildLeft = NULL;

	A->ChildLeft = B;
	A->ChildRight = C;
	
	B->ChildLeft = D;
	B->ChildRight = E;

	//PrevOrder(A);

	//InOrder(A);

	BackOrder(A);

	return 0;
}