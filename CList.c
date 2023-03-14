#define _CRT_SECURE_NO_WARNINGS 1

#include "CList.h"

CListNode* BuyCLTNode(coordinate* coor)
{
	CListNode* newNode = (CListNode*)malloc(sizeof(CListNode));
	assert(newNode);
	newNode->data = (coordinate*)malloc(sizeof(coordinate));
	assert(newNode->data);
	newNode->col = NULL;
	newNode->row = NULL;
	newNode->data->C = coor->C;
	newNode->data->S = coor->S;
	return newNode;
}

CListNode* CListInit(void)
{
	CListNode* newHead = (CListNode*)malloc(sizeof(CListNode));
	assert(newHead);
	coordinate coor = { -1, -1 };
	newHead = BuyCLTNode(&coor);
    newHead->col = newHead;
    newHead->row = newHead;
	return newHead;
}

//void CListInsert(CListNode* CListHead, coordinate* coor)
//{
//    int C = coor->C;
//    int S = coor->S;
//    CListNode* newNode = BuyCLTNode(coor);
//    CListNode* cur = CListHead->col;
//    CListNode* prev = CListHead;
//    CListNode* nextNode = cur->col;
//    if(cur == CListHead)
//    {
//        CListHead->col = newNode;
//        newNode->col = CListHead;
//    }
//    else
//    {
//        while(cur != CListHead)
//        {
//            if(prev == CListHead && cur->data->S > S)
//            {
//                prev->col = newNode;
//                newNode->col = cur;
//            }
//            else
//            {
//                if(cur->data->S < S && nextNode->data->S > S) {
//                    cur->col = newNode;
//                    newNode->col = nextNode;
//                }
//                else {
//                    prev = cur;
//                    cur = nextNode;
//                    nextNode = nextNode->col;
//                }
//            }
//        }
//    }
//}

void CListPushFront(CListNode* CListHead, int Option, coordinate* coor, CListNode* newNode)
{
    //STU
    if(Option)
    {
        CListNode* nextNode = CListHead->row;
        CListHead->row = newNode;
        newNode->row= nextNode;
    }
    //CLASS
    else
    {
        CListNode* nextNode = CListHead->col;
        CListHead->col = newNode;
        newNode->col = nextNode;
    }
}
