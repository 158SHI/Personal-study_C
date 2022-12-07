#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void StackInit(ST* st)
{
	st->data = (STDataType*)malloc(INIT_SIZE * sizeof(STDataType));
	if (st->data == NULL)
	{
		perror("StackInit:");
		return;
	}
	st->capacity = INIT_SIZE;
	st->top = 0;
}

void StackPush(ST* st, const STDataType x)
{
	assert(st);
	if (st->top == st->capacity)
	{
		//expand
		STDataType* tmp = (STDataType*)realloc(st->data, sizeof(STDataType) * (st->top + EXP_SIZE));
		if (tmp != NULL)
		{
			st->data = tmp;
			st->capacity += EXP_SIZE;
		}
		else
		{
			perror("Expand:");
			return;
		}
	}
	st->data[st->top] = x;
	st->top++;
}

void StackPop(ST* st)
{
	assert(st);
	assert(st->top > 0);
	st->top--;
}

void StackDestory(ST* st)
{
	free(st->data);
	st->data = NULL;
}

STDataType StackTopData(const ST* st)
{
	assert(st);
	assert(st->top > 0);//²»ÔÊÐíÕ»Îª¿Õ
	return st->data[st->top - 1];
}

_Bool StackEmpty(const ST* st)
{
	assert(st);
	return st->top == 0;
}
