#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType x);
void QueuePop(Queue* q);
void QueueDestory(Queue* q);
QDataType QueueHeadData(const Queue* q);
QDataType QueueTailData(const Queue* q);
_Bool QueueEmpty(Queue* q);
int QueueSize(const Queue* q);