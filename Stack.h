#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
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

void StackInit(Stack* s);
void StackPush(Stack* s, const StackDataType x);
void StackPop(Stack* s);
StackDataType StackTopData(Stack* s);
_Bool StackEmpty(Stack* s);