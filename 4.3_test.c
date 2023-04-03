#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

typedef int BTDataTypt;

typedef struct BTNode
{
	BTDataTypt data;
	struct BTNode* leftChild;
	struct BTNode* rightChild;
}BTNode;

BTNode* BuyNode(BTDataTypt x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	assert(newNode);
	newNode->data = x;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

BTNode* CreatTree(void)
{
	BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(3);
	BTNode* n4 = BuyNode(4);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);

	n1->leftChild = n2;
	n1->rightChild = n3;
	n2->leftChild = n4;
	n3->leftChild = n5;
	n3->rightChild = n6;

	return n1;
}

void PreOrder_1(BTNode* root)
{
	Stack sT;
	StackInit(&sT);

	StackPush(&sT, root);
	while (!StackEmpty(&sT))
	{
		BTNode* cur = StackTop(&sT);
		StackPop(&sT);
		if (cur == NULL) {
			printf("NULL ");
		}
		else {
			printf("%d ", cur->data);
		}
		if (cur != NULL) {
			StackPush(&sT, cur->rightChild);
			StackPush(&sT, cur->leftChild);
		}
	}
	StackDestory(&sT);
}

void PreOrder_2(BTNode* root)
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder_2(root->leftChild);
	PreOrder_2(root->rightChild);
}

int main()
{
	BTNode* root = CreatTree();
	printf("�ǵݹ飺");
	PreOrder_1(root);
	printf("\n�ݹ飺");
	PreOrder_2(root);
	return 0;
}