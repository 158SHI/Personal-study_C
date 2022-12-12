#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QueueDataType;

typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	//用两个指针维护队列
	QueueNode* head;
	QueueNode* tail;
}Queue;

void InitQueue(Queue* q);
void QueuePush(Queue* q, QueueDataType x);
void QueuePop(Queue* q);
_Bool QueueEmpty(Queue* q);
QueueDataType QueueTailData(Queue* q); 
QueueDataType QueueTopData(Queue* q);
void QueueDestory(Queue* q);