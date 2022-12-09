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

//��ȱ���
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

//�ڵ����
int NodeSize(BTNode* root)
{
	//�սڵ㣬����0
	if (root == NULL)
	{
		return 0;
	}
	//���ǿսڵ㣬�ڵ������ 1 �� ���������������ڵ����֮��
	else
	{
		return NodeSize(root->LeftChild) + NodeSize(root->RightChild) + 1;
	}
}

//Ҷ�ڵ����
int LeafSize(BTNode* root)
{
	//�ǿսڵ㣬����Ҷ�ڵ㣬���� 0
	if (root == NULL)
	{
		return 0;
	}

	//��Ҷ�ڵ㣬���� 1
	else if ((root->LeftChild == NULL) && (root->RightChild == NULL))
	{
		return 1;
	}

	//���ǿսڵ�Ҳ����Ҷ�ڵ㣬����������������Ѱ��
	else
	{
		return LeafSize(root->LeftChild) + LeafSize(root->RightChild);
	}
}

//�������
void SeqOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
	{
		//�����ڵ�������
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		//��¼���е�ͷ�ڵ�
		BTNode* head = QueueHeadData(&q);

		//pop���е�ͷ���
		QueuePop(&q);
		printf("%c ", head->data);//�������ڵ�

		//�����ӽڵ�����ӽڵ㲻Ϊ������������
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
	//Ϊ�ղ���Ҫ����
	if (*root == NULL)
	{
		return 0;
	}

	//��������
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