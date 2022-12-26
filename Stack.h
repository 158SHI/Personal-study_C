#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define INIT_SIZE 10
#define EXP_SIZE 10

typedef int StackDataType;

typedef struct Stack
{
	StackDataType* data;
	int size;
	int capacity;
}Stack;

void InitStack(Stack* s);
void StackPush(Stack* s, const StackDataType x);
void StackPop(Stack* s);
_Bool StackEmpty(Stack* s);
StackDataType StackTopData(Stack* s);
void StackDestory(Stack* s);