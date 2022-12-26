#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void test(void)
{
	Stack s;
	InitStack(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	StackPush(&s, 8);
	StackPush(&s, 9);
	StackPush(&s, 10);
	StackPush(&s, 11);

	while (!StackEmpty(&s))
	{
		printf("%d ", StackTopData(&s));
		StackPop(&s);
	}

	StackDestory(&s);
}


int main()
{
	test();
	return 0;
}