#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DLdataType;

typedef struct DListNode
{
	DLdataType data;
	struct DListNode* prev;
	struct DListNode* next;
}DList;

DList* DListInit(void);
void DListPushBack(DList* head, const DLdataType x);
void DListPushFront(DList* head, const DLdataType x);
void DListPrint(const DList* head);
void DListPopBack(DList* head);
void DListPopFront(DList* head);
DList* DListSearch(DList* head, const DLdataType x);
void DListDelet(DList* head, DList* pos);
void DListInsert(DList* head, DList* pos, DLdataType x);