#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void CheckCap(struct Contact* ps)
{
	/*
	��Ա������
	δ��������
	*/
	if (ps->size == ps->capacity)
	{
		//����
		//ÿ������5������
		struct PeopInfo* ptr = (struct PeopInfo*)realloc(ps->data, (ps->capacity + 5) * sizeof(struct PeopInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 5;//����ֻ���ڴ�������Ҫcapa���������к����ж�
			//printf("���ݳɹ�");
		}
	}
}

static void ScreePauAndCl()
{
	system("pause");
	system("cls");
}

static int CheckByName(const struct Contact* ps,const char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(name, ps->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//static int CheckByTel(const struct Contact* ps, const char* tel)
//{//������
//	int i = 0;
//	_Bool flag = false;
//	for (i = 0; i < ps->size; i++)
//	{
//		if (strcmp(tel, ps->data[i].tel) == 0)
//		{
//			flag = true;
//			return i;
//		}
//	}
//	if (flag == false)
//	{
//		return -1;
//	}
//}//������
//
////������PRO
//static int CheckByTelPro(const struct Contact* ps, const char* tel)
//{
//	_Bool flag = false;
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (strstr(ps->data[i].tel,tel) != NULL)
//		{
//			flag = true;
//			return i;
//		}
//	}
//	if (flag == false)
//	{
//		return -1;
//	}
//}

//����������ProMax
static int CheckByTelProMax(const struct Contact* ps, const char* tel,int* ReleTel,int* count)
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
	//���ٿռ�
	ps->data = (struct PeopInfo*)malloc(DEFAULT_CAP * sizeof(struct PeopInfo));//���ó�ʼ����Ϊ5
	
	ps->size = 0;
	ps->capacity = DEFAULT_CAP;

	//���ļ��е���Ϣ���ص�ͨѶ¼
	LoadContact(ps);
}

void LoadContact(struct Contact* ps)
{
	struct PeopInfo tmp = { 0 };
	FILE* pfRead = fopen("Contact.data", "rb");
	if (pfRead==NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}

	//������ʱ����0��loadֹͣ
	while (fread(&tmp, sizeof(struct PeopInfo), 1, pfRead))
	{
		CheckCap(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

static void AddConOnce(struct Contact* ps,int aim)
{
	printf("����������>: \b");
	scanf("%s", ps->data[aim].name);
	printf("����������>: \b");
	scanf("%d", &(ps->data[aim].age));
	printf("�������Ա�>: \b");
	scanf("%s", ps->data[aim].sex);
	printf("������绰>: \b");
	scanf("%s", ps->data[aim].tel);
	printf("�������ַ>: \b");
	scanf("%s", ps->data[aim].adrr);
	printf("��ӳɹ�__\n");
}

void AddContact(struct Contact* ps)
{
	CheckCap(ps);//���Ԫ�ظ���������������

	AddConOnce(ps, ps->size);
	ps->size++;
	ScreePauAndCl();
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
		ScreePauAndCl();
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
		ScreePauAndCl();
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
		ScreePauAndCl();
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
	ScreePauAndCl();
}

static SearchByTel(const struct Contact* ps,int cap)
{
	//int RelevantTel[MAX] = { 0 };
	int* RelevantTel = (int*)malloc(cap * sizeof(int));
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
		SearchByTel(ps,ps->capacity);
		break;
	case SEARCH_EXIT:
		return;
	default:
		printf("ѡ�����������ѡ��\n");
		goto again;
		break;
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[name_max];
	printf("������Ҫ�޸ĵ��˵�����>:");
	scanf("%s", name);
	int ret = CheckByName(ps, name);
	if (ret == -1)
	{
		printf("�����Ϣ������\n");
		ScreePauAndCl();
	}
	else
	{
		AddConOnce(ps, ret);
		ScreePauAndCl();
	}
}

int CompByName(const void* e1,const void* e2)
{
	return strcmp(((struct PeopInfo*)e1)->name, ((struct PeopInfo*)e2)->name);
}

void SortContact(struct Contact* ps)
{
	//����������
	qsort(ps->data, ps->size, sizeof(ps->data[0]), CompByName);
}

void DestoryContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("Contact.data", "wb");
	if (pfWrite==NULL)
	{
		printf("SaveContact:%s\n", strerror(errno));
		return;
	}

	for (int i = 0; i < ps->size; i++)//���д��
	{
		fwrite(&(ps->data[i]), sizeof(struct PeopInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}