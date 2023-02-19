#define _CRT_SECURE_NO_WARNINGS 1

#include"PracTopicSelecMana.h"

static enum TeacherOption
{
	EXIT,
	PUBLISH_LESSON,
	DELETE_LESSON,
	CHECK_LESSON,
	CHECK_STU,
	SEARCH_STU
};

void TeacherOption(void)
{
	printf("+------------------------+\n");
	printf("+-------1.��������-------+\n");
	printf("+-------2.ɾ������-------+\n");
	printf("+-----3.�鿴ȫ������-----+\n");
	printf("+---4.�鿴ѡ��ѧ����Ϣ---+\n");
	printf("+-----5.����ѧ����Ϣ-----+\n");
	printf("+---------0.ע��---------+\n");
	printf("+------------------------+\n");
}

void TeacherLoginSuccessfully(void)
{
	printf("��½�ɹ�_\n");
}

void PublishLesson(Mana* mana)
{
	system("cls");
	Topic* newTopic = (Topic*)malloc(sizeof(Topic));
	printf("�������������>:");
	scanf("%s", newTopic->name);
	printf("������ָ����ʦ>:");
	scanf("%s", newTopic->adviser);
	newTopic->num = mana->sz + 1;
	newTopic->numOfStu = 0;
	ManaPush(mana, newTopic);
	printf("��ӳɹ�_\n");
}

void DeleteLesson(Mana* mana)
{
	int delNum = 0;
	printf("��ѡ��Ҫɾ���Ŀ�������>:");
	scanf("%d", &delNum);
	
	if (delNum == mana->sz)
	{
		(mana->sz)--;
	}
	else
	{
		for (int i = delNum; i < mana->sz; i++)
		{
			(mana->topicList[i].num)--;
			mana->topicList[i - 1] = mana->topicList[i];
		}
		(mana->sz)--;
	}
}

void PrintStuOnce(Stu* stu)
{
	printf("%-10s\t%-5d\t%-5s\t%-12s\t%-15s\t%-20s\n",
		stu->name, stu->age, stu->sex, stu->ID, stu->major, stu->class);
}


void CheckLesson(Mana* mana)
{
	CheckAllTopic(mana);
	printf("�����������Բ鿴ѡ���ÿ����ѧ����Ϣ_\n����0���˳���ҳ��_\n");
	printf("��ѡ��>:");
	int input = 0;
	do
	{
		scanf("%d", &input);
		if (input == 0 || (input > 0 && input <= mana->sz))
		{
			if (input == 0)
			{
				break;
			}
			else
			{
				Topic* aimTopic = mana->topicList + (input - 1);
				if (aimTopic->numOfStu == 0) {
					printf("�ÿ����ѡ������Ϊ0_\n");
				}
				else {
					system("cls");
					printf("������Ϣ_:\n");
					printf("%-5s\t%-20s\t%-5s\t%-10s\n",
						"������", "��������", "ѡ������", "ָ����ʦ");
					printf("%-10d\t%-20s\t%-10d\t%-10s\n",
						aimTopic->num, aimTopic->name, aimTopic->numOfStu, aimTopic->adviser);
					printf("ѡ��ѧ����Ϣ:_\n");
					printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\t%-20s\n",
						"����", "����", "�Ա�", "ѧ��", "רҵ", "�༶");
					for (int i = 0; i < aimTopic->numOfStu; i++)
					{
						PrintStuOnce(aimTopic->stuList + i);
					}
				}
			}
		}
		else
		{
			printf("����Ƿ�������������>:\n");
		}
	} while (input);
}

void CheckStu(Stu_list* s_l)
{
	if (s_l->sz == 0)
	{
		printf("�б�Ϊ��_\n");
	}
	else
	{
		bool flag = false;
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\t%-20s\n",
			"����", "����", "�Ա�", "ѧ��", "רҵ", "�༶");
		for (int i = 0; i < s_l->sz; i++)
		{
			if ((s_l->stuList + i)->topicNum != 0)
			{
				flag = true;
				PrintStuOnce(s_l->stuList + i);
			}
		}
		if (!flag)
		{
			printf("�б�Ϊ��_\n");
		}
	}

}

void SearchStu(Stu_list* s_l)
{
	/*����д��
	* ��
	*/


}

void TeacherTermibal(Mana* mana, Stu_list* s_l)
{
	TeacherLoginSuccessfully();
/*
	��������
	ɾ������
	�޸Ŀ�����Ϣ
	�鿴������Ϣ �������Ȿ����Ϣ��ѡ��ѧ����Ϣ
	�鿴ѡ��ѧ����Ϣ
	����ĳ��ѡ��ѧ������Ϣ
	�޸Ĳ��ҳ�ѧ����ѡ����Ϣ
*/
	int input = 0;
	do
	{
		TeacherOption();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case PUBLISH_LESSON:
			PublishLesson(mana);
			break;
		case DELETE_LESSON:
			DeleteLesson(mana);
			break;
		case CHECK_LESSON:
			CheckLesson(mana);
			break;
		case CHECK_STU:
			CheckStu(s_l);
			break;
		case SEARCH_STU:
			SearchStu(s_l);
			break;
		case EXIT:
			system("cls");
			printf("�˳���¼_\n");
			break;
		default:
			printf("�Ƿ�ѡ�������ѡ��:>");
			break;
		}
	} while (input);
}