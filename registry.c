#define _CRT_SECURE_NO_WARNINGS 1

#include "registry.h"

registry* CreatRegistry(int CNum, int SNum)
{
	registry* newRegistry = (registry*)malloc(sizeof(registry));
	assert(newRegistry);
	newRegistry->ClassList = (CListNode**)malloc(sizeof(CListNode*) * CNum);
	newRegistry->StuList = (CListNode**)malloc(sizeof(CListNode*) * SNum);
	assert(newRegistry->ClassList && newRegistry->StuList);
	for (int i = 0; i < CNum; i++) {
		(newRegistry->ClassList)[i] = CListInit();
	}
	for (int i = 0; i < SNum; i++) {
		(newRegistry->StuList)[i] = CListInit();
	}
	return newRegistry;
}

void RegistryPush(registry* registry, coordinate* coor)
{
    CListNode* newNode = BuyCLTNode(coor);
    CListPushFront((registry->StuList)[coor->S], STU, coor, newNode);
    CListPushFront((registry->ClassList)[coor->C], CLASS, coor, newNode);
}

void RegistryDelet(registry* registry, coordinate* coor)
{

}
