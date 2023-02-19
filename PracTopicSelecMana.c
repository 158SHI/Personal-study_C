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
	assert(mana && s_l);
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

	//加载数据
	LoadMessage(mana, s_l);
}

void Destory(Mana* mana, Stu_list* s_l)
{
	assert(mana && s_l);
	free(mana->topicList);
	mana->topicList = NULL;
	mana->sz = 0;
	mana->capacity = 0;

	free(s_l->stuList);
	s_l->stuList = NULL;
	s_l->sz = 0;
	s_l->capacity = 0;
}

void CheckCapAndExp(Stu_list* s_l, Mana* mana)
{
	assert(s_l || mana);

	if (s_l != NULL)
	{
		if (s_l->capacity == s_l->sz)
		{
			Stu* tmp = (Stu*)realloc(s_l->stuList,
				(s_l->capacity + EXP_SZ));
			if (tmp == NULL) {
				perror("CheckCapAndExp::realloc");
				exit(-1);
			}
			else {
				s_l->stuList = tmp;
				s_l->capacity += EXP_SZ;
			}
		}
	}
	else
	{
		if (mana->capacity == mana->sz)
		{
			Topic* tmp = (Topic*)realloc(mana->topicList,
				(mana->capacity + EXP_SZ));
			if (tmp == NULL) {
				perror("CheckCapAndExp::realloc");
				exit(-1);
			}
			else {
				mana->topicList = tmp;
				mana->capacity += EXP_SZ;
			}
		}
	}
}

void StuListPush(Stu_list* s_l, Stu* stu)
{
	assert(s_l && stu);
	CheckCapAndExp(s_l, NULL);
	s_l->stuList[s_l->sz] = *stu;
	s_l->sz++;
}

void ManaPush(Mana* mana, Topic* newtopic)
{
	assert(mana && newtopic);
	CheckCapAndExp(NULL, mana);
	mana->topicList[mana->sz] = *newtopic;
	mana->sz++;
}

//补丁变量
int sz = 0;
int capacity = 20;

void StuInTopicPush(Stu* stuListInTopic, Stu* stu)
{
	if (sz == capacity)
	{
		Stu* tmp = (Stu*)realloc(stuListInTopic, (capacity + 20));
		if (tmp != NULL)
		{
			stuListInTopic = tmp;
			capacity += 20;
		}
		else
		{
			perror("StuInTopicPush::realloc");
			exit(-1);
		}
	}
	stuListInTopic[sz] = *stu;
	sz++;
}

void LoadMessage(Mana* mana, Stu_list* s_l)
{
	Topic tmp_mana = { 0 };
	FILE* pfReadMana = fopen("mana.data", "rb");
	if (pfReadMana == NULL)
	{
		perror("LoadMessage::fopen");
		return;
	}
	while (fread(&tmp_mana, sizeof(Topic), 1, pfReadMana))
	{
		CheckCapAndExp(NULL, mana);
		mana->topicList[mana->sz] = tmp_mana;
		mana->sz++;
	}
	fclose(pfReadMana);
	pfReadMana = NULL;

	Stu tmp_s_l = { 0 };
	FILE* pfReadS_l = fopen("s_l.data", "rb");
	if (pfReadS_l == NULL)
	{
		perror("LoadMessage::fopen");
		return;
	}
	while (fread(&tmp_s_l, sizeof(Topic), 1, pfReadS_l))
	{
		CheckCapAndExp(s_l, NULL);
		s_l->stuList[s_l->sz] = tmp_s_l;
		s_l->sz++;
	}
	fclose(pfReadS_l);
	pfReadS_l = NULL;

	Stu tmp_supp = { 0 };
	Stu* aimStuList = mana->topicList->stuList;
	FILE* pfReadSupp = fopen("supp.data", "rb");
	if (pfReadSupp == NULL)
	{
		perror("LoadMessage::fopen");
		return;
	}
	while (fread(&tmp_supp, sizeof(Stu), 1, pfReadSupp))
	{
		

		if (sz == capacity)
		{
			Stu* tmp = (Stu*)realloc(aimStuList, (capacity + 20));
			if (tmp != NULL)
			{
				aimStuList = tmp;
				capacity += 20;
			}
			else
			{
				perror("StuInTopicPush::realloc");
				exit(-1);
			}
		}


		aimStuList[sz] = tmp_supp;
		sz++;
	}
	fclose(pfReadSupp);
	pfReadSupp = NULL;
}

void SavaMessage(Mana* mana, Stu_list* s_l)
{
	FILE* pfWriteMana = fopen("mana.data", "wb");
	if (pfWriteMana == NULL)
	{
		perror("SavaMessage::fopen");
	}
	else
	{
		for (int i = 0; i < mana->sz; i++)
		{
			fwrite(mana->topicList + i, sizeof(Topic), 1, pfWriteMana);
		}
		fclose(pfWriteMana);
		pfWriteMana = NULL;
	}

	FILE* pfWriteS_l = fopen("s_l.data", "wb");
	if (pfWriteS_l == NULL)
	{
		perror("SavaMessage::fopen");
	}
	else
	{
		for (int i = 0; i < mana->sz; i++)
		{
			fwrite(s_l->stuList + i, sizeof(Stu), 1, pfWriteS_l);
		}
		fclose(pfWriteS_l);
		pfWriteS_l = NULL;
	}

	FILE* pfWriteSupp = fopen("supp.data", "wb");
	if (pfWriteSupp == NULL)
	{
		perror("SavaMessage::fopen");
	}
	else
	{
		for (int i = 0; i < sz; i++)
		{
			fwrite(mana->topicList->stuList + i, sizeof(Stu), 1, pfWriteSupp);
		}
		fclose(pfWriteSupp);
		pfWriteSupp = NULL;
	}
}