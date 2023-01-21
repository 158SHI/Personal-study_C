#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SeqList* sl)
{
	assert(sl);
	sl->data = (SeqListDataTp*)malloc(sizeof(SeqListDataTp) *
		DEFAULT_CAPA);
	if (sl->data == NULL)
	{
		perror("SeqListInit::malloc:");
	}
	else
	{
		sl->size = 0;
		sl->capacity = DEFAULT_CAPA;
	}
}

void CheckCap(SeqList* sl)
{
	assert(sl);
	if (sl->size == sl->capacity)
	{
		SeqListDataTp* tmp = (SeqListDataTp*)realloc(sl->data,
			sizeof(SeqListDataTp) * (EXP_SZ + sl->capacity));
		if (tmp == NULL)
		{
			perror("Check::realloc");
		}
		else
		{
			sl->data = tmp;
			sl->capacity += EXP_SZ;
		}
	}
	else if (sl->capacity - sl->size > EXP_SZ)
	{
		SeqListDataTp* tmp = (SeqListDataTp*)realloc(sl->data,
			sizeof(SeqListDataTp) * (sl->size + EXP_SZ));
		if (tmp == NULL)
		{
			perror("Check::realloc");
		}
		else
		{
			sl->data = tmp;
			sl->capacity = sl->size + EXP_SZ;
		}
	}
}

void SeqListPushBack(SeqList* sl, const SeqListDataTp x)
{
	assert(sl);
	CheckCap(sl);
	sl->data[sl->size] = x;
	sl->size++;
}

void SeqListPopBack(SeqList* sl)
{
	assert(sl);
	if (sl->size == 0)
	{
		printf("NULL\n");
		return;
	}
	sl->data[sl->size - 1] = 0;
	sl->size--;
	CheckCap(sl);
}

void SeqListPushFront(SeqList* sl, const SeqListDataTp x)
{
	assert(sl);
	CheckCap(sl);
	memmove(sl->data + 1, sl->data, 
		sizeof(SeqListDataTp) * sl->size);
	sl->data[0] = x;
	sl->size++;
}

void SeqListPopFront(SeqList* sl)
{
	assert(sl);
	if (sl->size == 0)
	{
		printf("NULL\n");
		return;
	}
	memmove(sl->data, sl->data + 1,
		sizeof(SeqListDataTp) * sl->size);
	sl->data[sl->size - 1] = 0;
	sl->size--;
	CheckCap(sl);
}

int SeqListSz(SeqList* sl)
{
	assert(sl);
	return sl->size;
}

int SeqListCap(SeqList* sl)
{
	assert(sl);
	return sl->capacity;
}

bool SeqListEmpty(SeqList* sl)
{
	assert(sl);
	return sl->size == 0;
}

int SeqListFind(SeqList* sl, const SeqListDataTp aim)
{
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->data[i] == aim)
		{
			return i;
		}
	}
	return -1;
}

void SeqListModify(SeqList* sl, const int pos, const SeqListDataTp aim)
{
	assert(sl);
	sl->data[pos] = aim;
}

void SeqListDel(SeqList* sl, const int pos)
{
	assert(sl);
	if (sl->size == 0)
	{
		printf("NULL\n");
		return;
	}
	memmove(sl->data + pos, sl->data + pos + 1,
		sizeof(SeqListDataTp) * (sl->size - pos - 1));
	sl->data[sl->size - 1] = 0;
	sl->size--;
	CheckCap(sl);
}

void SeqListInsert(SeqList* sl, const int pos, const SeqListDataTp x)
{
	assert(sl);
	assert(pos <= (sl->size - 1));
	CheckCap(sl);
	memmove(sl->data + pos + 1, sl->data + pos,
		sizeof(SeqListDataTp) * (sl->size - pos));
	sl->data[pos] = x;
	sl->size++;
}

void SeqListClear(SeqList* sl)
{
	assert(sl);
	memset(sl->data, 0, sizeof(SeqListDataTp) * sl->size);
	sl->size = 0;
	CheckCap(sl);
}

void SeqListDestory(SeqList* sl)
{
	assert(sl);
	free(sl->data);
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}