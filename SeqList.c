#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//实现功能接口

void InitSeqList(SeqList* ps)
{
	assert(ps);
	SqType* str = malloc(Init * sizeof(SqType));
	if (str == NULL)
	{
		printf("Init:%s\n", strerror(errno));
		system("pause");
		return;
	}
	else
	{
		ps->parr = str;
		ps->size = 0;
		ps->SizeMax = Init;

		memset(ps->parr, 0, ps->SizeMax * sizeof(SqType));
	}
}

static void IsFUll(SeqList* ps)
{
	if (ps->size == ps->SizeMax)
	{
		SqType* str = realloc(ps->parr, sizeof(SqType) * (Add + ps->SizeMax));
		if (str != NULL)
		{
			ps->parr = str;
			ps->SizeMax += Add;
			memset(&(ps->parr[ps->size]), 0, Add * sizeof(SqType));
		}
	}
	else
	{
		printf("Realloc:%s\n", strerror(errno));
		system("pause");
		return;
	}
}

static _Bool IsEmpty(SeqList* ps)
{
	if (ps->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SeqPushBack(SeqList* ps, SqType x)
{
	assert(ps);
	IsFUll(ps);
	ps->parr[ps->size] = x;
	ps->size++;
}

void SeqPushFront(SeqList* ps, SqType x)
{
	assert(ps);

	IsFUll(ps);
	SqType cur = ps->size - 1;
	while (cur >= 0)
	{
		ps->parr[cur + 1] = ps->parr[cur];
		cur--;
	}
	ps->parr[0] = x;

	ps->size++;
}

void SeqPopBack(SeqList* ps)
{
	assert(ps);

	if (IsEmpty(ps))
	{
		printf("Empty__\n");
		system("pause");

		return;
	}

	ps->parr[ps->size - 1] = 0;
	ps->size--;
}

void SeqPopFront(SeqList* ps)
{
	assert(ps);

	if (IsEmpty(ps))
	{
		printf("Empty__\n");
		system("pause");

		return;
	}

	SqType cur = 0;
	while (cur < ps->size -1)
	{
		ps->parr[cur] = ps->parr[cur + 1];
		cur++;
	}
	ps->parr[ps->size - 1] = 0;
	ps->size--;
}

void Show(const SeqList* ps)
{
	assert(ps);

	if (IsEmpty(ps))
	{
		printf("Empty__\n");
		system("pause");
		return;
	}

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->parr[i]);
	}
	printf("\n");
	system("pause");
}

void Exit(SeqList* ps)
{
	free(ps->parr);
	ps->parr = NULL;
}