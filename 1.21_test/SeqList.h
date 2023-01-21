#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define DEFAULT_CAPA 20
#define EXP_SZ 20

typedef int SeqListDataTp;

typedef struct SeqList
{
	SeqListDataTp* data;
	int size;
	int capacity;
}SeqList;

void SeqListInit(SeqList* sl);
void SeqListPushBack(SeqList* sl, const SeqListDataTp x);
void SeqListPopBack(SeqList* sl);
void SeqListPushFront(SeqList* sl, const SeqListDataTp x);
void SeqListPopFront(SeqList* sl);
int SeqListSz(SeqList* sl);
bool SeqListEmpty(SeqList* sl);
int SeqListFind(SeqList* sl, const SeqListDataTp aim);
void SeqListModify(SeqList* sl, const int pos, const SeqListDataTp aim);
void SeqListDel(SeqList* sl, const int pos);
void SeqListInsert(SeqList* sl, const int pos, const SeqListDataTp x);
void SeqListClear(SeqList* sl);
void SeqListDestory(SeqList* sl);