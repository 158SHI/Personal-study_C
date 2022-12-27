#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SeqList* sq)
{
	assert(sq);
	sq->data = (SeqListDataType*)malloc(sizeof(SeqListDataType) * INIT_SIZE);
	if (sq->data == NULL)
	{
		perror("InitSeqList:");
		exit(-1);
	}
	sq->size = 0;
	sq->capacity = INIT_SIZE;
}

_Bool SeqListEmpty(SeqList* sq)
{
	assert(sq);
	return sq->size == 0;
}

int SeqListSearch(SeqList* sq, const SeqListDataType x)
{
	assert(sq);
	for (int i = 0; i < sq->size; i++)
	{
		if (sq->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void JudgeAndExp(SeqList* sq)
{
	if (sq->size == sq->capacity)
	{
		SeqListDataType* tmp = (SeqListDataType*)realloc(sq->data, 
			sizeof(SeqListDataType) * (sq->size + EXP_SIZE));
		if (tmp != NULL)
		{
			sq->data = tmp;
			sq->capacity += EXP_SIZE;
		}
		else
		{
			perror("EXP:");
			exit(-1);
		}
	}
}

void SeqListPushHead(SeqList* sq, const SeqListDataType x)
{
	assert(sq);
	JudgeAndExp(sq);
	if (sq->size == 0)
	{
		SeqListPushBack(sq, x);
	}
	else
	{
		for (int i = sq->size - 1; i >= 0; i--)
		{
			sq->data[i + 1] = sq->data[i];
		}
		sq->data[0] = x;
		sq->size++;
	}
}

void SeqListPushBack(SeqList* sq, const SeqListDataType x)
{
	assert(sq);
	sq->data[sq->size] = x;
	sq->size++;
}

void SeqListDisplay(SeqList* sq)
{
	assert(sq);
	if (sq->size == 0)
	{
		printf("NULL\n");
	}
	else
	{
		for (int i = 0; i < sq->size; i++)
		{
			printf("%d ", sq->data[i]);
		}
		printf("\n");
	}
}

void SeqListPopBack(SeqList* sq)
{
	assert(sq);
	assert(sq->size != 0);
	sq->size--;
}

void SeqListPopHead(SeqList* sq)
{
	assert(sq);
	assert(sq->size != 0);
	for (int i = 0; i < sq->size - 1; i++)
	{
		sq->data[i] = sq->data[i + 1];
	}
	sq->size--;
}