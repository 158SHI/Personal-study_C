#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void test1(void)
{
	Slist* Slinklist = NULL;

	SlistPushFront(&Slinklist, 2);
	SlistPushFront(&Slinklist, 2);
	SlistPushFront(&Slinklist, 2);
	SlistPushFront(&Slinklist, 2);

	SlistPushBack(&Slinklist, 1);
	SlistPushBack(&Slinklist, 1);
	SlistPushBack(&Slinklist, 1);
	SlistPushBack(&Slinklist, 1);

	SlistPopFront(&Slinklist);
	SlistPopBack(&Slinklist);

	SlistPrint(&Slinklist);

	SlistDestory(&Slinklist);
}

void test2(void)
{
	Slist* Slinklist = NULL;

	SlistPushBack(&Slinklist, 1);
	SlistPushBack(&Slinklist, 1);
	SlistPushBack(&Slinklist, 1);

	SlistPopFront(&Slinklist);
	SlistPopFront(&Slinklist);
	SlistPopFront(&Slinklist);
	SlistPopFront(&Slinklist);

	SlistPopBack(&Slinklist);
	
	SlistDestory(&Slinklist);
}

void test3(void)
{
	Slist* Slinklist = NULL;

	SlistPushBack(&Slinklist, 1);
	SlistPushBack(&Slinklist, 2);
	SlistPushBack(&Slinklist, 3);

	Slist* Ins = SlistSearch(&Slinklist, 1);
	if (Ins != NULL)
	{
		SlistInsert(&Slinklist, Ins, 10);
	}

	SlistPrint(&Slinklist);

	SlistDestory(&Slinklist);
}

void test4(void)
{
	Slist* Slinklist = NULL;

	SlistPushBack(&Slinklist, 1);
	SlistPushBack(&Slinklist, 2);
	SlistPushBack(&Slinklist, 3);
	SlistPushBack(&Slinklist, 4);

	Slist* pos = SlistSearch(&Slinklist, 1);
	if (pos != NULL)
	{
		SlistDelet(&Slinklist, pos);
	}

	SlistPrint(&Slinklist);

	SlistDestory(&Slinklist);
}

void test5(void)
{
	Slist* Slinklist = NULL;

	SlistPushBack(&Slinklist, 1);
	SlistPushBack(&Slinklist, 1);
	SlistPushBack(&Slinklist, 1);

	SlistPrint(&Slinklist);
	SlistDestory(&Slinklist);
}

int main()
{
	test5();
	return 0;
}