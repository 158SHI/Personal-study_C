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
{//待升级
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
}//待升级

//升级版PRO
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

//超级升级版ProMax
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
		printf("通讯录已满__\n");
	}
	else
	{
		printf("请输入姓名>: \b");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄>: \b");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别>: \b");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话>: \b");
		scanf("%s", ps->data[ps->size].tel);
		printf("请输入地址>: \b");
		scanf("%s", ps->data[ps->size].adrr);
		printf("添加成功__\n");
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
		printf("通讯录为空\n");
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("%-20s\t%-3s\t%-5s\t%-20s\t%-25s\n", "姓名", "年龄", "性别", "电话", "地址");
		for (int i = 0; i < ps->size; i++)
		{
			PrintOnce(ps,i);//打印单个元素
		}
	}
}

void DelContact(struct Contact* ps)
{
	char name[name_max];
	printf("请输入要删除的人的姓名>:");
	scanf("%s", name);

	//查找对应的数据
	int ret = CheckByName(ps, name);
	if (ret == -1)
	{
		printf("要查找的数据不存在\n");
		system("pause");
		system("cls");
	}
	//删除
	else
	{
		for (int j = ret; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
		system("pause");
		system("cls");
	}
}

static void OptionList()
{
	printf("**-------------**\n");
	printf("*--1.按姓名查找--*\n");
	printf("*--2.按电话查找--*\n");
	printf("*-- 0.退出查找 --*\n");
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
	printf("请输入要查找的姓名>:");
	scanf("%s", name);
	int ret = CheckByName(ps, name);
	if (ret == -1)
	{
		printf("要查找的数据不存在\n");
	}
	else
	{
		printf("%-20s\t%-3s\t%-5s\t%-20s\t%-25s\n", "姓名", "年龄", "性别", "电话", "地址");
		PrintOnce(ps, ret);//打印单个元素
	}
	system("pause");
	system("cls");
}

static SearchByTel(const struct Contact* ps)
{
	int RelevantTel[MAX] = { 0 };
	int count = 0;

	char tel[tel_max];
	printf("请输入要查找的电话号码>:");
	scanf("%s", tel);
	int ret = CheckByTelProMax(ps,tel,RelevantTel,&count);
	if (ret == -1)
	{
		printf("要查找的数据不存在\n");
	}
	else
	{
		system("cls");
		printf("%-20s\t%-3s\t%-5s\t%-20s\t%-25s\n", "姓名", "年龄", "性别", "电话", "地址");
		for (int i = 0; i < count; i++)
		{
			PrintOnce(ps, RelevantTel[i]);//打印单个元素
		}
	}
	system("pause");
}

void SearchContact(const struct Contact* ps)
{
	OptionList();
again:
	printf("请选择查找方式>:");
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
		printf("选择错误，请重新选择\n");
		goto again;
		break;
	}
}