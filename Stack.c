#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void InitStack(Stack* s)
{
	assert(s);
	s->data = (StackDataType*)malloc(sizeof(StackDataType) * INIT_SIZE);
	if (s->data == NULL)
	{
		perror("InitStack:");
		exit(-1);
	}
	s->size = 0;
	s->capacity = INIT_SIZE;
}

void IsFull(Stack* s)
{
	if (s->size == s->capacity)
	{
		StackDataType* tmp = realloc(s->data,
			sizeof(StackDataType) * (s->size + EXP_SIZE));
		if (tmp != NULL)
		{
			s->data = tmp;
			s->capacity += EXP_SIZE;
		}
	}
}

void StackPush(Stack* s, const StackDataType x)
{
	assert(s);

	IsFull(s);
	s->data[s->size] = x;
	s->size++;
}

void StackPop(Stack* s)
{
	assert(s);
	if (s->size == 0)
	{
		printf("NULL");
		return;
	}
	s->size--;
}

_Bool StackEmpty(Stack* s)
{
	assert(s);
	return s->size == 0;
}

StackDataType StackTopData(Stack* s)
{
	assert(s);
	return s->data[s->size - 1];
}

void StackDestory(Stack* s)
{
	assert(s);
	free(s->data);
	s->data = NULL;
}