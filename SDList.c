#define _CRT_SECURE_NO_WARNINGS 1

#include"SDList.h"

static SDList* BuyNewNode(ListDataType x)
{
	SDList* newnode = (SDList*)malloc(sizeof(SDList));
	if (newnode == NULL)
	{
		perror("BuyNewNode:");
		return NULL;
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
		return newnode;
	}
}

SDList* SDListInit(void)
{
	SDList* newnode = BuyNewNode(0);
	return newnode;
}

//void SDListPushBack(SDList* phead, ListDataType x)
//{
//	assert(phead);
//
//	SDList* newnode = BuyNewNode(x);
//	if (newnode == NULL)
//	{
//		return;
//	}
//
//	SDList* cur = phead;
//	while (cur->next != NULL)
//	{
//		cur = cur->next;
//	}
//	cur->next = newnode;
//}

void SDListPushBack(SDList* phead, ListDataType x)
{
	assert(phead);
	SDList* tail = phead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	SDListInsert(phead, tail->next, x);
}

//void SDListPushFront(SDList* phead, ListDataType x)
//{
//	assert(phead);
//	SDList* newnode = BuyNewNode(x);
//	if (newnode == NULL)
//	{
//		return;
//	}
//
//	SDList* first = phead->next;
//	phead->next = newnode;
//	newnode->next = first;
//}

void SDListPushFront(SDList* phead, ListDataType x)
{
	assert(phead);
	SDListInsert(phead, phead->next, x);
}

//void SDListPopBack(SDList* phead)
//{
//	assert(phead);
//
//	if (phead->next == NULL)
//	{
//		printf("NULL\n");
//		return;
//	}
//	else
//	{
//		SDList* pre = phead->next;
//		while (pre->next->next != NULL)
//		{
//			pre = pre->next;
//		}
//		SDList* tail = pre->next;
//
//		free(tail);
//		tail = NULL;
//
//		pre->next = NULL;
//	}
//}

void SDListPopBack(SDList* phead)
{
	assert(phead);
	if (phead->next == NULL)
	{
		printf("NULL\n");
		return;
	}
	else
	{
		SDList* tail = phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		SDListDelet(phead, tail);
	}
}

//void SDListPopFront(SDList* phead)
//{
//	assert(phead);
//	if (phead->next == NULL)
//	{
//		printf("NULL\n");
//		return;
//	}
//
//	SDList* first = phead->next;
//	SDList* second = phead->next->next;
//
//	free(first);
//	first = NULL;
//
//	phead->next = second;
//}

void SDListPopFront(SDList* phead)
{
	assert(phead);
	if (phead->next == NULL)
	{
		printf("NULL\n");
		return;
	}
	else
	{
		SDListDelet(phead, phead->next);
	}
}

void SDListPrint(const SDList* phead)
{
	assert(phead);
	SDList* cur = phead->next;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SDList* SDListSearch(const SDList* phead, const ListDataType x)
{
	SDList* cur = phead->next;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SDListDelet(SDList* phead, SDList* pos)
{
	SDList* next = pos->next;
	SDList* pre = phead;
	while (pre->next != pos)
	{
		pre = pre->next;
	}
	pre->next = next;
	
	free(pos);
	pos = NULL;
}

void SDListInsert(SDList* phead, SDList* pos, ListDataType x)
{
	SDList* pre = phead;
	while (pre->next != pos)
	{
		pre = pre->next;
	}
	SDList* newnode = BuyNewNode(x);
	if (newnode == NULL)
	{
		return;
	}

	pre->next = newnode;
	newnode->next = pos;
}

void SDListDestory(SDList* phead)
{
	SDList* n1 = phead->next;
	SDList* n2 = phead->next->next;

	while (n1 != NULL)
	{
		phead->next = n2;
		free(n1);
		n1 = n2;
		if (n2 != NULL)
		{
			n2 = n2->next;
		}
	}

	free(phead);
	phead = NULL;
}