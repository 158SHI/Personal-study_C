#pragma once

#include<string.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
#include<stdbool.h>

enum Option
{
	EXIT,
	ADDBACK,
	ADDFRONT,
	POPBACK,
	POPFRONT,
	SHOW
};


// µœ÷À≥–Ú±Ì

#define Init 5
#define Add 5

typedef int SqType;

typedef struct SeqList
{
	SqType* parr;
	int size;
	int SizeMax;
}SeqList;


void InitSeqList(SeqList* ps);
void SeqPushBack(SeqList* ps, SqType x);
void SeqPushFront(SeqList* ps, SqType x);
void SeqPopBack(SeqList* ps);
void SeqPopFront(SeqList* ps);
void Show(SeqList* ps);
void Exit(SeqList* ps);