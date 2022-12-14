#pragma once

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>

#define name_max 20
#define sex_max 5
#define tel_max 20
#define adrr_max 30
#define DEFAULT_CAP 5//设置初始容量为5

enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

struct PeopInfo
{
	char name[name_max];
	int age;
	char sex[sex_max];
	char tel[tel_max];
	char adrr[adrr_max];
};

struct Contact
{
	struct PeopInfo *data;//存放信息
	int size;//记录当前元素个数
	int capacity;//记录通讯录当前的容量
};

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortContact(struct Contact* ps);
void DestoryContact(struct Contact* ps);
void SaveContact(struct Contact* ps);
void LoadContact(struct Contact* ps);