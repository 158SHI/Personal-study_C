#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void test(void)
{
	Queue q;
	InitQueue(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	QueueTailData(&q);
	QueueTopData(&q);

	QueuePop(&q);
	QueuePop(&q);

	QueueDestory(&q);
}

void test2(void)
{
	Queue q;
	InitQueue(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	
	if (!QueueEmpty(&q))
	{
		printf("Tail:%d\n", QueueTailData(&q));
		printf("Top:%d\n", QueueTopData(&q));
	}

	QueuePop(&q);
	QueuePop(&q);

	if (!QueueEmpty(&q))
	{
		printf("Tail:%d\n", QueueTailData(&q));
		printf("Top:%d\n", QueueTopData(&q));
	}

	QueueDestory(&q);
}

int main()
{
	test2();
	return 0;
}