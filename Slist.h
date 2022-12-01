#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int SLDtype;

struct Slist
{
	SLDtype data;
	struct Slist* next;
};

typedef struct Slist Slist;

void Print(Slist* phead);
void SLPushBack(Slist** pphead, SLDtype x);
void SLPushFront(Slist** pphead, SLDtype x);