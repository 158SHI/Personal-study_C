#pragma once

#include "CList.h"

typedef struct registry
{
	CListNode** StuList;
	CListNode** ClassList;
}registry;

registry* CreatRegistry(int CNum, int SNum);
//void RegistryInsert(registry* registry, coordinate* coor);
void RegistryPush(registry* registry, coordinate* coor);
void RegistryDelet(registry* registry, coordinate* coor);
