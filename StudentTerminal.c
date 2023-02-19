#define _CRT_SECURE_NO_WARNINGS 1

#include"PracTopicSelecMana.h"

 enum StuOption
{
	EXIT,
	CHECK_ALL,
	CHECK_MINE,
	MODIFY_MINE,
	SELECT_TOPIC
};

static void StuOption(void)
{
	printf("+------------------+\n");
	printf("+--1.查看全部选题--+\n");
	printf("+--2.查看我的选题--+\n");
	printf("+--3.修改我的选题--+\n");
	printf("+----4.进行选题----+\n");
	printf("+----0.退出登陆----+\n");
	printf("+------------------+\n");
}

static void NewStuLogin(Stu* newStu)
{
	assert(newStu);
	printf("用户注册>\n");
	printf("请输入你的姓名>:");
	scanf("%s", newStu->name);
	printf("请输入你的年龄>:");
	scanf("%d", &(newStu->age));
	printf("请输入你的性别>:");
	scanf("%s", newStu->sex);
	printf("请输入你的专业>:");
	scanf("%s", newStu->major);
	printf("请输入你的班级>:");
	scanf("%s", newStu->class);
}

void StuLoginSuccessfully(const Stu* stu, Stu_list* s_l)
{
	assert(stu && s_l);
	system("cls");
	printf("登陆成功_\n");
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\t%-20s\n",
		"姓名", "年龄", "性别", "学号", "专业", "班级");
	printf("%-10s\t%-5d\t%-5s\t%-12s\t%-20s\t%-20s\n", 
		stu->name, stu->age, stu->sex, stu->ID, stu->major, stu->class);
	StuListPush(s_l, stu);//将学生信息加入注册表
}

Stu* StuLogin(Stu_list* s_l)
{
	assert(s_l);
	char Id[ID_MAX] = { 0 };
	printf("请输入你的学号>:");
	scanf("%s", Id);

	//在已有学生信息列表中查找学号信息
	for (int i = 0; i < s_l->sz; i++)
	{
		if (strcmp((s_l->stuList + i)->ID, Id) == 0)
		{
			//直接登陆
			printf("登陆成功_\n");
			return s_l->stuList + i;
		}
	}
	
	//用户不存在，自动注册
	Stu* newStu = (Stu*)malloc(sizeof(Stu));
	if (newStu == NULL) {
		perror("StuLogin::newStu_malloc");
		exit(-1);
	}
	strcpy(newStu->ID, Id);
	newStu->topicNum = 0;
	NewStuLogin(newStu);
	return newStu;
}

void PrintTopicOnce(Topic* topic)
{
	assert(topic);
	printf("%-10d\t%-20s\t%-10d\t%-10s\n",
		topic->num, topic->name, topic->numOfStu, topic->adviser);
}

void CheckAllTopic(Mana* mana)
{
	assert(mana);
	system("cls");
	if (mana->sz == 0)
	{
		printf("教师暂未发布课题_\n");
	}
	else
	{
		printf("%-5s\t%-20s\t%-5s\t%-10s\n",
			"课题编号", "课题名称", "选报人数", "指导教师");
		for (int i = 0; i < mana->sz; i++)
		{
			PrintTopicOnce(mana->topicList + i);
		}
	}
}

void CheckMyTopic(Stu* stu, Mana* mana)
{
	assert(stu && mana);
	if (stu->topicNum == 0)
	{
		printf("你的选题列表为空_\n");
	}
	else
	{
		system("cls");
		Topic* myTopic = mana->topicList + (stu->topicNum - 1);
		printf("我的课题_\n");
		printf("%-5s\t%-20s\t%-5s\t%-10s\n",
			"课题编号", "课题名称", "选报人数", "指导教师");
		printf("%-10d\t%-20s\t%-10d\t%-10s\n",
			myTopic->num, myTopic->name, myTopic->numOfStu, myTopic->adviser);
	}
}

void ModifyMyTopic(Stu* stu, Mana* mana)
{
	assert(stu && mana);
	if (stu->topicNum == 0)
	{
		printf("你的选题列表为空_\n");
	}
	else
	{
		system("cls");
		int oldNum = stu->topicNum;
		int newNum = 0;
		printf("请输入新课题编号>:");
		while (1)
		{
			scanf("%d", &newNum);
			if (newNum > 0 && newNum <= mana->sz)
			{
				((mana->topicList + (oldNum - 1))->numOfStu)--;
				stu->topicNum = newNum;
				((mana->topicList + (newNum - 1))->numOfStu)++;
				system("cls");
				printf("修改成功_\n");
				break;
			}
			else
			{
				printf("选择非法，请重新选择_\n");
			}
		}
	}
}

void SelectTopic(Stu* stu, Mana* mana)
{
	while (1)
	{
		printf("请输入课题序号>:");
		int num = 0;
		scanf("%d", &num);
		if (num > 0 && num <= mana->sz)
		{
			stu->topicNum = num;
			((mana->topicList + (stu->topicNum - 1))->numOfStu)++;
			//补丁函数
			(mana->topicList + (stu->topicNum - 1))->stuList = (Stu*)malloc(sizeof(Stu) * 20);
			StuInTopicPush((mana->topicList + (stu->topicNum - 1))->stuList, stu);
			system("cls");
			printf("选题成功_\n");
			break;
		}
		else
		{
			printf("输入非法或该课题不存在，请重新选择>:");
		}
	}
}

void StudentTerminal(Mana* mana, Stu_list* s_l)
{
	assert(s_l && mana);
	//学生登陆
	Stu* stu = StuLogin(s_l);
	StuLoginSuccessfully(stu, s_l);
	int input = 0;
	do
	{
		StuOption();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case CHECK_ALL:
			CheckAllTopic(mana);
			break;
		case CHECK_MINE:
			CheckMyTopic(stu, mana);
			break;
		case MODIFY_MINE:
			ModifyMyTopic(stu, mana);
			break;
		case SELECT_TOPIC:
			SelectTopic(stu, mana);
			break;
		case EXIT:
			system("cls");
			printf("退出登录_\n");
			break;
		default:
			printf("非法选项，请重新选择_\n");
			break;
		}
	} while (input);
}