#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** sl, const SLDataType x);
void SListPopBack(SListNode** sl);