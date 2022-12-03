#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LDtype;

typedef struct List
{
	LDtype data;
	struct List* next;
	struct List* prev;
}List;

List* ListInit(void);
void ListDestory(List* phead);
void ListPushBack(List* phead, LDtype x);
void ListPrint(const List* phead);
void ListPushFront(List* phead, LDtype x);
void ListPopBack(List* phead);
void ListPopFront(List* phead);
List* ListSearch(List* phead, LDtype x);
void ListDelete(List* phead, List* pos);
void ListInsert(List* phead, List* pos, LDtype);