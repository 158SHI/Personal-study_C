#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

static int CheckByName(const struct Contact* ps,const char* name)
{
	int i = 0;
	_Bool flag = false;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(name, ps->data[i].name) == 0)
		{
			flag = true;
			return i;
		}
	}
	if (flag==false)
	{
		return -1;
	}
}

static CheckByTel(const struct Contact* ps, const char* tel)
{//������
	int i = 0;
	_Bool flag = false;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(tel, ps->data[i].tel) == 0)
		{
			flag = true;
			return i;
		}
	}
	if (flag == false)
	{
		return -1;
	}
}//������

//������PRO
static CheckByTelPro(const struct Contact* ps, const char* tel)
{
	_Bool flag = false;
	for (int i = 0; i < ps->size; i++)
	{
		if (strstr(ps->data[i].tel,tel) != NULL)
		{
			flag = true;
			return i;
		}
	}
	if (flag == false)
	{
		return -1;
	}
}

//����������ProMax
static CheckByTelProMax(const struct Contact* ps, const char* tel,int ReleTel[MAX],int* count)
{
	_Bool flag = false;
	for (int i = 0; i < ps->size; i++)
	{
		if (strstr(ps->data[i].tel, tel) != NULL)
		{
			flag = true;
			ReleTel[(*count)++] = i;
		}
	}
	if (flag == false)
	{
		return -1;
	}
}


void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����__\n");
	}
	else
	{
		printf("����������>: \b");
		scanf("%s", ps->data[ps->size].name);
		printf("����������>: \b");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�>: \b");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰>: \b");
		scanf("%s", ps->data[ps->size].tel);
		printf("�������ַ>: \b");
		scanf("%s", ps->data[ps->size].adrr);
		printf("��ӳɹ�__\n");
		ps->size++;
		system("pause");
		system("cls");
	}
}

void PrintOnce(const struct Contact* ps,int i)
{
	printf("%-20s\t%-3d\t%-5s\t%-20s\t%-25s\n",
		ps->data[i].name,
		ps->data[i].age,
		ps->data[i].sex,
		ps->data[i].tel,
		ps->data[i].adrr);
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("%-20s\t%-3s\t%-5s\t%-20s\t%-25s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (int i = 0; i < ps->size; i++)
		{
			PrintOnce(ps,i);//��ӡ����Ԫ��
		}
	}
}

void DelContact(struct Contact* ps)
{
	char name[name_max];
	printf("������Ҫɾ�����˵�����>:");
	scanf("%s", name);

	//���Ҷ�Ӧ������
	int ret = CheckByName(ps, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ����ݲ�����\n");
		system("pause");
		system("cls");
	}
	//ɾ��
	else
	{
		for (int j = ret; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
		system("pause");
		system("cls");
	}
}

static void OptionList()
{
	printf("**-------------**\n");
	printf("*--1.����������--*\n");
	printf("*--2.���绰����--*\n");
	printf("*-- 0.�˳����� --*\n");
	printf("**-------------**\n");
}

static enum List
{
	SEARCH_EXIT,
	SEARCH_NAME,
	SEARCH_TEL
};

static SearchByName(const struct Contact* ps)
{
	char name[name_max];
	printf("������Ҫ���ҵ�����>:");
	scanf("%s", name);
	int ret = CheckByName(ps, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ����ݲ�����\n");
	}
	else
	{
		printf("%-20s\t%-3s\t%-5s\t%-20s\t%-25s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		PrintOnce(ps, ret);//��ӡ����Ԫ��
	}
	system("pause");
	system("cls");
}

static SearchByTel(const struct Contact* ps)
{
	int RelevantTel[MAX] = { 0 };
	int count = 0;

	char tel[tel_max];
	printf("������Ҫ���ҵĵ绰����>:");
	scanf("%s", tel);
	int ret = CheckByTelProMax(ps,tel,RelevantTel,&count);
	if (ret == -1)
	{
		printf("Ҫ���ҵ����ݲ�����\n");
	}
	else
	{
		system("cls");
		printf("%-20s\t%-3s\t%-5s\t%-20s\t%-25s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (int i = 0; i < count; i++)
		{
			PrintOnce(ps, RelevantTel[i]);//��ӡ����Ԫ��
		}
	}
	system("pause");
}

void SearchContact(const struct Contact* ps)
{
	OptionList();
again:
	printf("��ѡ����ҷ�ʽ>:");
	int input = 0;
	scanf("%d", &input);
	switch (input)
	{
	case SEARCH_NAME:
		SearchByName(ps);
		break;
	case SEARCH_TEL:
		SearchByTel(ps);
		break;
	case SEARCH_EXIT:
		return;
	default:
		printf("ѡ�����������ѡ��\n");
		goto again;
		break;
	}
}