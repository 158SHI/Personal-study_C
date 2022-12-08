#define _CRT_SECURE_NO_WARNINGS 1

#include"DList.h"

void Test(void)
{
	DList* head = DListInit();
	DListPushBack(head, 1);
	DListPushBack(head, 2);
	DListPushBack(head, 3);
	DListPushBack(head, 4);

	DListPrint(head);

	DListPushFront(head, 6);
	DListPushFront(head, 6);
	DListPushFront(head, 6);
	DListPrint(head);


	DListPopBack(head);
	DListPopBack(head);

	DListPrint(head);

	DListPopFront(head);
	DListPopFront(head);

	DListPrint(head);
}

void Test2(void)
{
	DList* head = DListInit();
	DListPushBack(head, 1);
	DListPushBack(head, 2);
	DListPushBack(head, 3);
	DListPushBack(head, 4);

	DListPrint(head);

	DList* pos = DListSearch(head, 3);
	if (pos != NULL)
	{
		DListDelet(head, pos);
	}

	DListPrint(head);
}

void Test3(void)
{
	DList* head = DListInit();
	DListPushBack(head, 1);
	DListPushBack(head, 2);
	DListPushBack(head, 3);
	
	DListPrint(head);


	DList* pos = DListSearch(head, 3);
	if (pos != NULL)
	{
		DListInsert(head, pos, 30);
		DListPopBack(head);
	}
	
	DListPrint(head);
}

int main()
{
	Test3();
	return 0;
}