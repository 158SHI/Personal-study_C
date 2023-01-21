#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void test1(void)
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 2);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);

	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 2);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
}

void test2(void)
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 2);

	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 2);

	if (!SeqListEmpty(&sl))
	{
		int pos = 0;
		while ((pos = SeqListFind(&sl, 3)) != -1)
		{
			SeqListModify(&sl, pos, 1);
		}
	}
}

void test3(void)
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 2);

	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 2);
	
	if (!SeqListEmpty(&sl))
	{
		//int pos = 0;
		//while ((pos = SeqListFind(&sl, 3)) != -1)
		//{
		//	SeqListDel(&sl, pos);
		//}
		int pos = SeqListFind(&sl, 3);
		SeqListInsert(&sl, pos, 1);
	}
}

void test4(void)
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 2);

	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 2);

	SeqListClear(&sl);

	SeqListDestory(&sl);
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}