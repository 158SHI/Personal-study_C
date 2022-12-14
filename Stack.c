#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void StackInit(Stack* s)
{
	s->pdata = (StackDataType*)calloc(INIT_SIZE, sizeof(StackDataType));
	s->size = 0;
	s->capacity = INIT_SIZE;
}

void IsFullAndExpand(Stack* s)
{
	if (s->size == s->capacity)
	{
		StackDataType* tmp = (StackDataType*)realloc(s->pdata,
			sizeof(StackDataType) * (s->size + EXP_SIZE));
		if (tmp != NULL)
		{
			s->pdata = tmp;
		}
	}
}

void StackPush(Stack* s, StackDataType x)
{
	IsFullAndExpand(s);
	s->pdata[s->size] = x;
	s->size++;
}