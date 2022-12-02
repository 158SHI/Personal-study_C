#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

typedef int SLDtype;

struct Slist
{
	SLDtype data;
	//int count;//������������Ƕ��һ����������������ݵ���ţ����ǲ�����������
	struct Slist* next;
};

typedef struct Slist Slist;

void SlistPushBack(Slist** pphead, SLDtype x);
void SlistPrint(const Slist** pphead);
void SlistPushFront(Slist** pphead, SLDtype x);
void SlistPopFront(Slist** pphead);
void SlistPopBack(Slist** pphead);
Slist* SlistSearch(const Slist** pphead, const SLDtype aim);
void SlistInsert(Slist** pphead, Slist* ins, SLDtype ins_num);
void SlistDelet(Slist** pphead, Slist* pos);
void SlistDestory(Slist** pphead);