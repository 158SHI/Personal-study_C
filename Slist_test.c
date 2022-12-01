#define _CRT_SECURE_NO_WARNINGS 1

#include"Slist.h"

void Test(void)
{
	Slist* slist = NULL;//

	SLPushBack(&slist, 1);
	SLPushBack(&slist, 2);
	SLPushBack(&slist, 3);
	SLPushBack(&slist, 4);
	SLPushBack(&slist, 5);

	SLPushFront(&slist, 6);
	SLPushFront(&slist, 6);
	SLPushFront(&slist, 6);

	Print(slist);

}

int main()
{
	Test();
	return 0;
}