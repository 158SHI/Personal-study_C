#pragma once

#include<stdio.h>
#include<string.h>

#define N 5


struct user
{
	char name[20];
	char number[20];
};

void input(struct user* a);
void sort(struct user* a);
void output(struct user* a);