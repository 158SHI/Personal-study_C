#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

void Test1(void)
{
	List* list = ListInit();
	
	ListPushBack(list, 1);
	ListPushBack(list, 1);
	ListPushBack(list, 1);
	ListPushBack(list, 1);
	
	ListPushFront(list, 2);
	ListPushFront(list, 2);
	ListPushFront(list, 2);
	ListPushFront(list, 2);

	ListPushBack(list, 3);

	ListPopFront(list);
	ListPopFront(list);

	ListPopBack(list);
	ListPopBack(list);

	ListPrint(list);

	ListDestory(list);
}

void Test2(void)
{
	List* list = ListInit();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPushBack(list, 5);

	ListPrint(list);

	List* pos = ListSearch(list, 3);
	if (pos == NULL)
	{
		printf("can't find it\n");
	}
	else
	{
		//opration
		ListDelete(list, pos);
		ListPrint(list);
	}

	ListDestory(list);
}

void Test3(void)
{
	List* list = ListInit();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPushBack(list, 5);

	ListPrint(list);

	List* pos = ListSearch(list, 3);
	ListInsert(list, pos, 66);

	ListPrint(list);
	
	ListDestory(list);
}

int main()
{
	Test1();
	return 0;
}