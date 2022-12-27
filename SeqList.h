#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define INIT_SIZE 10
#define EXP_SIZE 10

typedef int SeqListDataType;

typedef struct SeqList
{
	SeqListDataType* data;
	int size;
	int capacity;
}SeqList;

void SeqListInit(SeqList* sq);
_Bool SeqListEmpty(SeqList* sq);
int SeqListSearch(SeqList* sq, const SeqListDataType x);
void SeqListPushHead(SeqList* sq, const SeqListDataType x);
void SeqListPushBack(SeqList* sq, const SeqListDataType x);
void SeqListDisplay(SeqList* sq);
void SeqListPopBack(SeqList* sq);
void SeqListPopHead(SeqList* sq);