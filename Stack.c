#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void StackInit(Stack* s)
{
	assert(s);
	s->data = (StackDataType*)malloc(sizeof(StackDataType) * INIT_SIZE);
	if (s->data == NULL)
	{
		perror("StackInit:");
		exit(-1);
	}
	s->size = 0;
	s->capacity = INIT_SIZE;
}

void StackPush(Stack* s, const StackDataType x)
{
	assert(s);

	if (s->size == s->capacity)
	{
		StackDataType* tmp = (StackDataType*)realloc(s->data,
			(s->size + EXP_SIZE) * sizeof(StackDataType));
		if (tmp != NULL)
		{
			s->data = tmp;
			s->capacity += EXP_SIZE;
		}
		else
		{
			perror("Expand:");
			exit(-1);
		}
	}
	s->data[s->size] = x;
	s->size++;
}

void StackPop(Stack* s)
{
	assert(s);
	s->size--;
}

StackDataType StackTopData(Stack* s)
{
	assert(s);
	assert(s->size != 0);
	return s->data[s->size - 1];
}

_Bool StackEmpty(Stack* s)
{
	return s->size == 0;
}