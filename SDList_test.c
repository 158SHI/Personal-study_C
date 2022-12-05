#define _CRT_SECURE_NO_WARNINGS 1

#include"SDList.h"

void Test(void)
{
	SDList* list = SDListInit();

	SDListPushBack(list, 1);
	SDListPushBack(list, 2);
	SDListPushBack(list, 3);
	SDListPushBack(list, 4);

	SDListPushFront(list, 6);
	SDListPushFront(list, 6);
	SDListPushFront(list, 6);

	SDListPopBack(list);
	SDListPopBack(list);
	SDListPopBack(list);

}

void Test2(void)
{
	SDList* list = SDListInit();
	SDListPushFront(list, 1);
	SDListPushFront(list, 1);
	SDListPushFront(list, 1);

	SDListPushBack(list, 2);
	SDListPushBack(list, 2);
	SDListPushBack(list, 2);

	SDListPrint(list);

	SDListPopFront(list);
	SDListPopFront(list);
	SDListPopFront(list);

	SDListPrint(list);
}

void Test3(void)
{
	SDList* list = SDListInit();
	SDListPushBack(list, 1);
	SDListPushBack(list, 2);
	SDListPushBack(list, 3);
	SDListPushBack(list, 4);
	
	SDListPrint(list);

	SDList* pos = SDListSearch(list, 3);
	if (pos != NULL)
	{
		//SDListDelet(list, pos);
		SDListInsert(list, pos, 30);
	}

	SDListPrint(list);

	SDListDestory(list);
}

int main()
{
	Test3();
	return 0;
}