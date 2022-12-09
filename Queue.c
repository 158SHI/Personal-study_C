#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->tail = NULL;
	q->head = NULL;
}

void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("newnode:");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (q->tail == NULL)
	{
		q->head = newnode;
		q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->head);//不允许队列为空

	//只有一个元素
	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = NULL;
		q->tail = NULL;
	}
	//有多个元素
	else
	{
		QueueNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
}

void QueueDestory(Queue* q)
{
	assert(q);
	assert(q->head);

	QueueNode* next = NULL;
	
	while (q->head)
	{
		next = q->head->next;
		free(q->head);
		q->head = next;
	}
	q->tail = NULL;
}

QDataType QueueHeadData(const Queue* q)
{
	assert(q);
	assert(q->head);
	return q->head->data;
}

QDataType QueueTailData(const Queue* q)
{
	assert(q);
	assert(q->head);
	return q->tail->data;
}

_Bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL;
}

int QueueSize(const Queue* q)
{
	QueueNode* cur = q->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}