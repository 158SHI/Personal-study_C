#define _CRT_SECURE_NO_WARNINGS 1

#include"DList.h"


DList* DListInit(void)
{
	DList* head = (DList*)malloc(sizeof(DList));
	if (head == NULL)
	{
		perror("Init:");
		exit(-1);
	}

	head->data = 0;
	head->next = head;
	head->prev = head;

	return head;
}

DList* BuyNewNode(const DLdataType x)
{
	DList* newnode = (DList*)malloc(sizeof(DList));
	if (newnode == NULL)
	{
		perror("BuyNewNode:");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//void DListPushBack(DList* head, DLdataType x)
//{
//	assert(head);
//	DList* newnode = BuyNewNode(x);
//	
//	DList* tail = head->prev;
//
//	tail->next = newnode;
//	newnode->prev = tail;
//	newnode->next = head;
//	head->prev = newnode;
//}

void DListPushBack(DList* head, const DLdataType x)
{
	assert(head);
	DListInsert(head, head, x);
}

//void DListPushFront(DList* head, DLdataType x)
//{
//	DList* newnode = BuyNewNode(x);
//	DList* first = head->next;
//
//	head->next = newnode;
//	newnode->prev = head;
//	newnode->next = first;
//	first->prev = newnode;
//
//}

void DListPushFront(DList* head, const DLdataType x)
{
	assert(head);
	DListInsert(head, head->next, x);
}

void DListPrint(const DList* head)
{
	assert(head);
	DList* cur = head->next;
	while (cur != head)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//void DListPopBack(DList* head)
//{
//	//Á´±íÎª¿Õ
//	if (head->next == head)
//	{
//		printf("NULL ");
//		return;
//	}
//
//	DList* tail = head->prev;
//	DList* pre = tail->prev;
//	
//	free(tail);
//	tail = NULL;
//	pre->next = head;
//	head->prev = pre;
//}

void DListPopBack(DList* head)
{
	assert(head);
	if (head->next == head)
	{
		printf("NULL ");
		return;
	}
	DListDelet(head, head->prev);
}

//void DListPopFront(DList* head)
//{
//	if (head->next == head)
//	{
//		printf("NULL ");
//		return;
//	}
//	DList* first = head->next;
//	DList* second = head->next->next;
//
//	head->next = second;
//	second->prev = head;
//	free(first);
//	first = NULL;
//}

void DListPopFront(DList* head)
{
	assert(head);
	if (head->next == head)
	{
		printf("NULL ");
		return;
	}
	DListDelet(head, head->next);
}

DList* DListSearch(DList* head, const DLdataType x)
{
	assert(head);
	DList* cur = head->next;
	while (cur != head)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void DListDelet(DList* head, DList* pos)
{
	assert(head);

	DList* pre = pos->prev;
	DList* next = pos->next;

	pre->next = next;
	next->prev = pre;
	free(pos);
	pos = NULL;
}

void DListInsert(DList* head, DList* pos, DLdataType x)
{
	assert(head);

	DList* pre = pos->prev;
	DList* newnode = BuyNewNode(x);

	pre->next = newnode;
	newnode->prev = pre;
	newnode->next = pos;
	pos->prev = newnode;
}