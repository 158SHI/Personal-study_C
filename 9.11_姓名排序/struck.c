#define _CRT_SECURE_NO_WARNINGS 1

#include"struck.h"

void input(struct user* a)
{
	int i = 0;
	printf("�������û��������͵绰���룬�ÿո����\n");
	for ( i = 0; i < N; i++)
	{
		scanf("%s %s",a[i].name,a[i].number);
	}
}

void sort(struct user* a)
{
	int i, j = 0;
	struct user t;
	for ( i = 0; i < N-1; i++)
	{
		for ( j = i+1; j < N; j++)//ѡ������
		{
			if (strcmp(a[i].name,a[j].name)>0)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

void output(struct user* a)
{
	printf("�����������>:\n");
	int i = 0;
	for ( i = 0; i < N; i++)
	{
		printf("%s %s\n", a[i].name, a[i].number);
	}
}