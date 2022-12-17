#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void test(void)
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);

	while (!StackEmpty(&s))
	{
		printf("%d ", StackTopData(&s));
		StackPop(&s);
	}
}

int main()
{
	test();
	return 0;
}