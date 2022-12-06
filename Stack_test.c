#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void Test(void)
{
	ST st;
	StackInit(&st);

	if (StackEmpty(&st))
	{
		printf("Empty\n");
	}

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);


	StackPop(&st);
	StackPop(&st);

	if (!StackEmpty(&st))
	{
		printf("NO empty\n");
		printf("%d\n", StackTopData(&st));
	}
	StackDestory(&st);
}

void Test2(void)
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTopData(&st));
		StackPop(&st);
	}

	StackDestory(&st);
}

int main()
{
	Test2();
	return 0;
}