#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

typedef char BTdataType;

typedef struct BinaryTree
{
	BTdataType data;
	struct BinaryTree* LeftChild;
	struct BinaryTree* RightChild;
}BTNode;

//深度遍历
void PreOrder(BTNode* root)
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

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->LeftChild);
	printf("%c ", root->data);
	InOrder(root->RightChild);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->LeftChild);
	PostOrder(root->RightChild);
	printf("%c ", root->data);
}

//节点个数
int NodeSize(BTNode* root)
{
	//空节点，返回0
	if (root == NULL)
	{
		return 0;
	}
	//不是空节点，节点个数是 1 加 左子树和右子树节点个数之和
	else
	{
		return NodeSize(root->LeftChild) + NodeSize(root->RightChild) + 1;
	}
}

//叶节点个数
int LeafSize(BTNode* root)
{
	//是空节点，不含叶节点，返回 0
	if (root == NULL)
	{
		return 0;
	}

	//是叶节点，返回 1
	else if ((root->LeftChild == NULL) && (root->RightChild == NULL))
	{
		return 1;
	}

	//不是空节点也不是叶节点，向左子树和右子树寻找
	else
	{
		return LeafSize(root->LeftChild) + LeafSize(root->RightChild);
	}
}

//层序遍历
void SeqOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
	{
		//将根节点放入队列
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		//记录队列的头节点
		BTNode* head = QueueHeadData(&q);

		//pop队列的头结点
		QueuePop(&q);
		printf("%c ", head->data);//访问树节点

		//若左子节点或右子节点不为空则将其放入队列
		if (head->LeftChild)
		{
			QueuePush(&q, head->LeftChild);
		}
		if (head->RightChild)
		{
			QueuePush(&q, head->RightChild);
		}
	}
}

void TreeDestory(BTNode** root)
{
	//为空不需要销毁
	if (*root == NULL)
	{
		return 0;
	}

	//后续销毁
	TreeDestory(&((*root)->LeftChild));
	TreeDestory(&((*root)->RightChild));
	free(*root);
	*root = NULL;
}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->LeftChild = NULL;
	A->RightChild = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->LeftChild = NULL;
	B->RightChild = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->LeftChild = NULL;
	C->RightChild = NULL;
	
	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->LeftChild = NULL;
	D->RightChild = NULL;
	
	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->LeftChild = NULL;
	E->RightChild = NULL;
	
	BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	F->data = 'F';
	F->LeftChild = NULL;
	F->RightChild = NULL;

	A->LeftChild = B;
	A->RightChild = C;
	B->LeftChild = D;
	B->RightChild = E;
	C->RightChild = F;
	
	printf("NodeSize:%d\n", NodeSize(A));
	printf("LeafSize:%d\n", LeafSize(A));

	PreOrder(A);
	printf("\n");
	
	InOrder(A);
	printf("\n");
	
	PostOrder(A);
	printf("\n");
	
	SeqOrder(A);

	TreeDestory(&A);

	return 0;
}