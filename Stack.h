#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


#define INIT_SIZE 5
#define EXP_SIZE 5

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}ST;

void StackInit(ST* st);
void StackPush(ST* st, const STDataType x);
void StackPop(ST* st);
void StackDestory(ST* st);
STDataType StackTopData(const ST* st);
_Bool StackEmpty(const ST* st);
