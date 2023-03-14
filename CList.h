#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum pushOption
{
    CLASS,
    STU
};

typedef struct coordinate
{
	int C;
	int S;
}coordinate;

typedef coordinate* CListDataType;

typedef struct CListNode
{
	CListDataType data;
	struct CListNode* col;
	struct CListNode* row;
}CListNode;

CListNode* BuyCLTNode(coordinate* coor);
CListNode* CListInit(void);
//void CListInsert(CListNode* CListHead, coordinate* coor);
void CListPushFront(CListNode* CListHead, int Option, coordinate* coor, CListNode* newNode);
