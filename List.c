#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

List* BuyListNode(LDtype x)
{
	List* newnode = (List*)malloc(sizeof(List));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

List* ListInit(void)
{
	List* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//void ListPushBack(List* phead, LDtype x)
//{
//	assert(phead);
//	List* tail = phead->prev;
//	List* newnode = BuyListNode(x);
//
//	newnode->prev = tail;
//	tail->next = newnode;
//	phead->prev = newnode;
//	newnode->next = phead;
//}

void ListPushBack(List* phead, LDtype x)
{
	ListInsert(phead, phead, x);
}

void ListPrint(const List* phead)
{
	assert(phead);
	List* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//void ListPushFront(List* phead, LDtype x)
//{
//	assert(phead);
//	List* newnode = BuyListNode(x);
//	List* first = phead->next;//若不定义first,需要注意链接顺序
//
//	newnode->prev = phead;
//	phead->next = newnode;
//	newnode->next = first;
//	first->prev = newnode;
//}

void ListPushFront(List* phead, LDtype x)
{
	ListInsert(phead, phead->next, x);
}

//void ListPopFront(List* phead)
//{
//	assert(phead);
//	assert(phead->next != phead);//不允许链表为空
//
//	List* first = phead->next;
//	List* second = first->next;
//
//	free(first);
//	first = NULL;
//
//	phead->next = second;
//	second->prev = phead;
//}

void ListPopFront(List* phead)
{
	ListDelete(phead, phead->next);
}

//void ListPopBack(List* phead)
//{
//	assert(phead);
//	assert(phead != phead->next);//不允许链表为空
//
//	List* tail = phead->prev;
//	List* pre = tail->prev;
//
//	free(tail);
//	tail = NULL;
//	pre->next = phead;
//	phead->prev = pre;
//}

void ListPopBack(List* phead)
{
	ListDelete(phead, phead->prev);
}

List* ListSearch(List* phead, LDtype x)
{
	List* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListDelete(List* phead, List* pos)
{
	/*
	该接口可以另外实现头删和尾删，
	进行复用可大量减少工作量
	*/
	assert(phead);
	assert(pos != phead);

	List* pre = pos->prev;
	List* next = pos->next;

	pre->next = next;
	next->prev = pre;

	free(pos);
	pos = NULL;
}

void ListInsert(List* phead, List* pos, LDtype x)
{
	/*
	该接口可以另外实现头插和尾插，
	进行复用可大量减少工作量
	*/
	assert(phead);

	List* pre = pos->prev;
	List* newnode = BuyListNode(x);

	pre->next = newnode;
	newnode->prev = pre;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListDestory(List* phead)
{	
	while (phead->next != phead)
	{
		ListDelete(phead, phead->next);
	}
	free(phead);
	phead = NULL;
}