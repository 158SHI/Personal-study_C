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
	printf("+--1.�鿴ȫ��ѡ��--+\n");
	printf("+--2.�鿴�ҵ�ѡ��--+\n");
	printf("+--3.�޸��ҵ�ѡ��--+\n");
	printf("+----4.����ѡ��----+\n");
	printf("+----0.�˳���½----+\n");
	printf("+------------------+\n");
}

static void NewStuLogin(Stu* newStu)
{
	assert(newStu);
	printf("�û�ע��>\n");
	printf("�������������>:");
	scanf("%s", newStu->name);
	printf("�������������>:");
	scanf("%d", &(newStu->age));
	printf("����������Ա�>:");
	scanf("%s", newStu->sex);
	printf("���������רҵ>:");
	scanf("%s", newStu->major);
	printf("��������İ༶>:");
	scanf("%s", newStu->class);
}

void StuLoginSuccessfully(const Stu* stu, Stu_list* s_l)
{
	assert(stu && s_l);
	system("cls");
	printf("��½�ɹ�_\n");
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\t%-20s\n",
		"����", "����", "�Ա�", "ѧ��", "רҵ", "�༶");
	printf("%-10s\t%-5d\t%-5s\t%-12s\t%-20s\t%-20s\n", 
		stu->name, stu->age, stu->sex, stu->ID, stu->major, stu->class);
	StuListPush(s_l, stu);//��ѧ����Ϣ����ע���
}

Stu* StuLogin(Stu_list* s_l)
{
	assert(s_l);
	char Id[ID_MAX] = { 0 };
	printf("���������ѧ��>:");
	scanf("%s", Id);

	//������ѧ����Ϣ�б��в���ѧ����Ϣ
	for (int i = 0; i < s_l->sz; i++)
	{
		if (strcmp((s_l->stuList + i)->ID, Id) == 0)
		{
			//ֱ�ӵ�½
			printf("��½�ɹ�_\n");
			return s_l->stuList + i;
		}
	}
	
	//�û������ڣ��Զ�ע��
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
		printf("��ʦ��δ��������_\n");
	}
	else
	{
		printf("%-5s\t%-20s\t%-5s\t%-10s\n",
			"������", "��������", "ѡ������", "ָ����ʦ");
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
		printf("���ѡ���б�Ϊ��_\n");
	}
	else
	{
		system("cls");
		Topic* myTopic = mana->topicList + (stu->topicNum - 1);
		printf("�ҵĿ���_\n");
		printf("%-5s\t%-20s\t%-5s\t%-10s\n",
			"������", "��������", "ѡ������", "ָ����ʦ");
		printf("%-10d\t%-20s\t%-10d\t%-10s\n",
			myTopic->num, myTopic->name, myTopic->numOfStu, myTopic->adviser);
	}
}

void ModifyMyTopic(Stu* stu, Mana* mana)
{
	assert(stu && mana);
	if (stu->topicNum == 0)
	{
		printf("���ѡ���б�Ϊ��_\n");
	}
	else
	{
		system("cls");
		int oldNum = stu->topicNum;
		int newNum = 0;
		printf("�������¿�����>:");
		while (1)
		{
			scanf("%d", &newNum);
			if (newNum > 0 && newNum <= mana->sz)
			{
				((mana->topicList + (oldNum - 1))->numOfStu)--;
				stu->topicNum = newNum;
				((mana->topicList + (newNum - 1))->numOfStu)++;
				system("cls");
				printf("�޸ĳɹ�_\n");
				break;
			}
			else
			{
				printf("ѡ��Ƿ���������ѡ��_\n");
			}
		}
	}
}

void SelectTopic(Stu* stu, Mana* mana)
{
	while (1)
	{
		printf("������������>:");
		int num = 0;
		scanf("%d", &num);
		if (num > 0 && num <= mana->sz)
		{
			stu->topicNum = num;
			((mana->topicList + (stu->topicNum - 1))->numOfStu)++;
			//��������
			(mana->topicList + (stu->topicNum - 1))->stuList = (Stu*)malloc(sizeof(Stu) * 20);
			StuInTopicPush((mana->topicList + (stu->topicNum - 1))->stuList, stu);
			system("cls");
			printf("ѡ��ɹ�_\n");
			break;
		}
		else
		{
			printf("����Ƿ���ÿ��ⲻ���ڣ�������ѡ��>:");
		}
	}
}

void StudentTerminal(Mana* mana, Stu_list* s_l)
{
	assert(s_l && mana);
	//ѧ����½
	Stu* stu = StuLogin(s_l);
	StuLoginSuccessfully(stu, s_l);
	int input = 0;
	do
	{
		StuOption();
		printf("��ѡ��>:");
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
			printf("�˳���¼_\n");
			break;
		default:
			printf("�Ƿ�ѡ�������ѡ��_\n");
			break;
		}
	} while (input);
}