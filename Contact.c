#define _CRT_SECURE_NO_WARNINGS 1

#include"Contact.h"

void menu(void)
{
	printf("+-------------------------+\n");
	printf("+---------Contact---------+\n");
	printf("+---1.Add-------2.Delet---+\n");
	printf("+---3.Search---4.Modify---+\n");
	printf("+---5.Show------6.Clear---+\n");
	printf("+---7.Sort-------0.Exit---+\n");
	printf("+-------------------------+\n");
}

void ScreePauAndCl(void)
{
	system("pause");
	system("cls");
}

void PrintOnce(Contact* Con, int aim)
{
	printf("%-20s\t%-5s\t%-3d\t%-20s\t%-20s\n",
		Con->info[aim].name,
		Con->info[aim].sex,
		Con->info[aim].age,
		Con->info[aim].number,
		Con->info[aim].adress);
}

void ContactInit(Contact* Con)
{
	assert(Con);
	Con->size = 0;
	memset(Con->info, 0, sizeof(Con->info));
}

void AddOnce(Contact* Con, int aim)
{
	printf("������������");
	scanf("%s", Con->info[aim].name);
	printf("�������Ա�");
	scanf("%s", Con->info[aim].sex);
	printf("���������䣺");
	scanf("%d", &Con->info[aim].age);
	printf("������绰��");
	scanf("%s", Con->info[aim].number);
	printf("�������ַ��");
	scanf("%s", Con->info[aim].adress);
}

void ContactAdd(Contact* Con)
{
	AddOnce(Con, Con->size);
	(Con->size)++;
	printf("��ӳɹ�_\n");
	ScreePauAndCl();
}

int CheckByName(Contact* Con, char* aim)
{
	for (int i = 0; i < Con->size; i++)
	{
		if (!strcmp(Con->info[i].name, aim))
		{
			return i;
		}
	}
	return -1;
}


void ContactDelet(Contact* Con)
{
	assert(Con);
	if (!Con->size)
	{
		printf("ͨѶ¼Ϊ��_\n");
		return;
	}

	char name_in[NAME_MAX] = { 0 };
	printf("��������ҵ��˵�����:");
	scanf("%s", name_in);
	int pos = CheckByName(Con, name_in);
	if (pos == -1)
	{
		printf("�����������Ϣ_\n");
	}
	else
	{
		memmove(Con->info + pos, Con->info + pos + 1,
			sizeof(Con->info[0]) * (Con->size - pos));
		(Con->size)--;
		printf("ɾ���ɹ�_\n");
	}
	ScreePauAndCl();
}

void OptionList(void)
{
	printf("+----------------------+\n");
	printf("+--------Search--------+\n");
	printf("+---1.Search by name---+\n");
	printf("+--2.Search by number--+\n");
	printf("+----------------------+\n");
}

void CheckByTel(Contact* Con, int* TelList, int* TelListSz)
{
	printf("������绰���룺");
	char num[NUMBER_MAX] = { 0 };
	scanf("%s", num);
	for (int i = 0; i < Con->size; i++)
	{
		if (strstr(Con->info[i].number, num))
		{
			TelList[(*TelListSz)++] = i;
		}
	}
}

void SearchByNum(Contact* Con)
{
	int TelList[50] = { 0 };
	int TelListSz = 0;
	CheckByTel(Con, TelList, &TelListSz);
	if (!TelListSz)
	{
		printf("�����������Ϣ_\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-3s\t%-20s\t%-20s\n",
			"����", "�Ա�", "����", "�绰", "��ַ");
		for (int i = 0; i < TelListSz; i++)
		{
			PrintOnce(Con, TelList[i]);
		}
	}
}

void SearchByName(Contact* Con)
{
	char name_in[NAME_MAX] = { 0 };
	printf("��������ҵ��˵�����:");
	scanf("%s", name_in);
	int pos = CheckByName(Con, name_in);
	if (pos == -1)
	{
		printf("�����������Ϣ_\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-3s\t%-20s\t%-20s\n",
			"����", "�Ա�", "����", "�绰", "��ַ");
		PrintOnce(Con, pos);
	}
}

void ContactSearch(const Contact* Con)
{
again:
	OptionList();
	printf("��ѡ����ҷ�ʽ:");
	int input = 0;
	scanf("%d", &input);
	switch (input)
	{
	case SEARBYNAME:
		SearchByName(Con);
		ScreePauAndCl();
		break;
	case SEARBYNUM:
		SearchByNum(Con);
		ScreePauAndCl();
		break;
	default:
		system("cls");
		printf("ѡ��Ƿ�_\n");
		goto again;
		break;
	}
}

void ContactModify(Contact* Con)
{
	char name_in[NAME_MAX] = { 0 };
	printf("������Ҫ�޸ĵ��˵�����:");
	scanf("%s", name_in);
	int pos = CheckByName(Con, name_in);
	if (pos == -1)
	{
		printf("�����������Ϣ_\n");
	}
	else
	{
		AddOnce(Con, pos);
		printf("�޸ĳɹ�_\n");
	}
	ScreePauAndCl();
}

void ContactShow(const Contact* Con)
{
	assert(Con);
	if (!Con->size)
	{
		printf("ͨѶ¼Ϊ��_\n");
		ScreePauAndCl();
	}
	else
	{
		system("cls");
		printf("%-20s\t%-5s\t%-3s\t%-20s\t%-20s\n", 
			"����", "�Ա�", "����", "�绰", "��ַ");
		for (int i = 0; i < Con->size; i++)
		{
			PrintOnce(Con, i);
		}
	}
}

void ContactClear(Contact* Con)
{
	assert(Con);
	Con->size = 0;
	printf("����ɹ�_\n");
	ScreePauAndCl();
}

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((Contact*)e1)->info->name, 
		((Contact*)e2)->info->name);
}

void ContactSort(Contact* Con)
{
	qsort(Con->info, Con->size, sizeof(Con->info[0]), cmp_name);
	printf("����ɹ�_\n");
	ScreePauAndCl();
}