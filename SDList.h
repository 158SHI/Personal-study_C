#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int ListDataType;

typedef struct SDList
{
	ListDataType data;
	struct SDList* next;
}SDList;

SDList* SDListInit(void);
void SDListPushBack(SDList* phead, ListDataType x);
void SDListPushFront(SDList* phead, ListDataType x);
void SDListPopBack(SDList* phead);
void SDListPopFront(SDList* phead);
void SDListPrint(const SDList* phead);
SDList* SDListSearch(const SDList* phead, const ListDataType x);
void SDListDelet(SDList* phead, SDList* pos);
void SDListInsert(SDList* phead, SDList* pos, ListDataType x);
void SDListDestory(SDList* phead);