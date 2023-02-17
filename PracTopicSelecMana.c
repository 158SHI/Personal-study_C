#define _CRT_SECURE_NO_WARNINGS 1

#include"PracTopicSelecMana.h"

void menu(void)
{
	printf("++---+实践课题选题管理系统+---++\n");
	printf("++----------------------------++\n");
	printf("++----1.学生端----2.教师端----++\n");
	printf("++----------------------------++\n");
	printf("++---------0.退出系统---------++\n");
	printf("++----------------------------++\n");
}

void InitList(Mana* mana, Stu_list* s_l)
{
	mana->topicList = (Topic*)malloc(sizeof(Topic) * DEFAULT_CAP);
	if (mana->topicList == NULL)
	{
		perror("InitList::malloc_mana");
		exit(-1);
	}
	mana->capacity = DEFAULT_CAP;
	mana->sz = 0;

	s_l->stuList = (Stu*)malloc(sizeof(Stu) * DEFAULT_CAP);
	if (s_l->stuList == NULL)
	{
		perror("InitList::malloc_s_l");
		exit(-1);
	}
	s_l->capacity = DEFAULT_CAP;
	s_l->sz = 0;
}

void Destory(Mana* mana, Stu_list* s_l)
{
	free(mana->topicList);
	mana->topicList = NULL;
	mana->sz = 0;
	mana->capacity = 0;

	free(s_l->stuList);
	s_l->stuList = NULL;
	s_l->sz = 0;
	s_l->capacity = 0;
}