#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define INIT_SIZE 10
#define EXP_SIZE 5

typedef int StackDataType;

typedef struct Stack
{
	StackDataType* pdata;
	int size;
	int capacity;
}Stack;

void StackInit(Stack* s);
void StackPush(Stack* s, StackDataType x);