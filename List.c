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
//	List* first = phead->next;//��������first,��Ҫע������˳��
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
//	assert(phead->next != phead);//����������Ϊ��
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
//	assert(phead != phead->next);//����������Ϊ��
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
	�ýӿڿ�������ʵ��ͷɾ��βɾ��
	���и��ÿɴ������ٹ�����
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
	�ýӿڿ�������ʵ��ͷ���β�壬
	���и��ÿɴ������ٹ�����
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