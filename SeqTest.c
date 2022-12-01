#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

static menu(void)
{
	printf("**-------------------------**\n");
	printf("**--1.AddBack--2.AddFront--**\n");
	printf("**--3.PopBack--4.PopFront--**\n");
	printf("**--5.Show---------0.Exit--**\n");
	printf("**-------------------------**\n");
}

void Test(SeqList* ps)
{
	InitSeqList(ps);//≥ı ºªØ
	int n = 0;

	do
	{
		system("cls");
		menu();
		printf("Chose your option:");
		scanf("%d", &n);
		switch (n)
		{
		case ADDBACK:
			SeqPushBack(ps, 1);
			break;
		case ADDFRONT:
			SeqPushFront(ps, 2);
			break;
		case POPBACK:
			SeqPopBack(ps);
			break;
		case POPFRONT:
			SeqPopFront(ps);
			break;
		case SHOW:
			Show(ps);
			break;
		case EXIT:
			Exit(ps);
			break;
		};
	} while (n);
}

int main()
{
	SeqList s;
	Test(&s);
	return 0;
}