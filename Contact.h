#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define NAME_MAX 20
#define SEX_MAX 5
#define NUMBER_MAX 20
#define ADRESS_MAX 20
#define CAPACITY 1000

typedef struct PeopInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char number[NUMBER_MAX];
	char adress[ADRESS_MAX];
}PeopInfo;

typedef struct Contact
{
	PeopInfo info[CAPACITY];
	int size;
}Contact;

enum MenuOption
{
	EXIT,
	ADD,
	DELET,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR,
	SORT
};

enum SearOption
{
	SEARBYNAME = 1,
	SEARBYNUM
};

void menu(void);
void ContactInit(Contact* Con);
void ContactAdd(Contact* Con);
void ContactSearch(const Contact* Con);
void ContactDelet(Contact* Con);
void ContactModify(Contact* Con);
void ContactShow(const Contact* Con);
void ContactClear(Contact* Con);
void ContactSort(Contact* Con);