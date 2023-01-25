#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

void test1(void)
{
	SListNode* sl = NULL;
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);

	SListPopBack(&sl);
}

int main()
{
	test1();
	return 0;
}