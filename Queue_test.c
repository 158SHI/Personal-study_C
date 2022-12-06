#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void Test(void)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("%d\n", QueueHeadData(&q));
	printf("%d\n", QueueTailData(&q));

	QueuePop(&q);
	
	printf("%d\n", QueueHeadData(&q));

	QueueDestory(&q);
}

void Test2(void)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("%d\n", QueueSize(&q));

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueHeadData(&q));
		QueuePop(&q);
	}
	
	printf("\n%d\n", QueueSize(&q));
}

int main()
{
	Test2();
	return 0;
}