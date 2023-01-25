#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

SListNode* BuyNode(const SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		perror("BuyNode::malloc");
	}
	else
	{
		newNode->next = NULL;
		newNode->data = x;
		return newNode;
	}
}

void SListPushBack(SListNode** sl, const SLDataType x)
{
	SListNode* newNode = BuyNode(x);
	if (!(*sl))
	{
		*sl = newNode;
	}
	else
	{
		SListNode* cur = *sl;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void SListPopBack(SListNode** sl)
{
	if (!(*sl))
	{
		printf("NULL\n");
	}
	else
	{
		SListNode* cur = *sl;
		if (cur->next == NULL)
		{

		}
		else
		{

			while (cur->next->next)
			{
				cur = cur->next;
			}
			free(cur->next);
			cur->next = NULL;
		}
	}
}