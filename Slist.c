#define _CRT_SECURE_NO_WARNINGS 1

#include"Slist.h"

void Print(Slist* phead)
{
	Slist* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLPushBack(Slist** pphead, SLDtype x)
{
	Slist* newnode = (Slist*)malloc(sizeof(Slist));
	if (newnode == NULL)
	{
		return;
	}
	newnode->next = NULL;
	newnode->data = x;

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		Slist* tail = *pphead;

		//��β�ڵ�
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//�����½ڵ�
		tail->next = newnode;
	}
}

void SLPushFront(Slist** pphead, SLDtype x)
{
	Slist* newnode = (Slist*)malloc(sizeof(Slist));
	newnode->next = NULL;
	newnode->data = x;

	newnode->next = *pphead;
}