#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void InitQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

QueueNode* BuyNode(QueueDataType x)
{
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (NewNode == NULL)
	{
		perror("Buynode:");
		exit(-1);
	}
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

void QueuePush(Queue* q, QueueDataType x)
{
	assert(q);

	QueueNode* NewNode = BuyNode(x);
	if (q->tail == NULL)
	{
		q->head = NewNode;
		q->tail = NewNode;
	}
	else
	{
		q->tail->next = NewNode;
		q->tail = NewNode;
	}
}

_Bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL;
}

QueueDataType QueueTailData(Queue* q)
{
	assert(q);
	assert(q->head);
	return q->tail->data;
}

QueueDataType QueueTopData(Queue* q)
{
	assert(q);
	assert(q->head);
	return q->head->data;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->head->next);//不允许只剩一个元素

	QueueNode* next = q->head->next;
	free(q->head);
	q->head = next;
}

void QueueDestory(Queue* q)
{
	while (q->head->next)
	{
		QueuePop(q);
	}
	free(q->head);
	q->head = NULL;
	q->tail = NULL;
}