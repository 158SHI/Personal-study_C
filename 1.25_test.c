#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void InsertSort(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int key = arr[i];
		int j = 0;
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > key)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = key;
	}
}

void PrintArr(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test1(void)
{
	//int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	int arr[] = { 2, 1, 4, 8, 3, 5, 7, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	PrintArr(arr, sz);
}

void ShellSort(int* arr, int sz)
{
	int group = sz;
	while (group > 1)
	{
		group /= 2;
		for (int i = 0; i < sz; i++)
		{
			int j = 0;
			int key = arr[i];
			for (j = i - group; j >= 0; j -= group)
			{
				if (arr[j] > key)
				{
					arr[j + group] = arr[j];
				}
				else
				{
					break;
				}
			}
			arr[j + group] = key;
		}
	}
}

void test2(void)
{
	int arr[] = { 2, 1, 4, 8, 3, 5, 7, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	PrintArr(arr, sz);
}

//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}

typedef struct Stu
{
	int x;
	int y;
}Stu;

void Print(int n, Stu s)
{
	printf("%d\n", s.x);
	printf("%d\n", s.y);
}

//int main()
//{
//	//Stu s = { 1, 2 };
//	return 0;
//}



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//**----------------------------------------------------
#define INIT_SIZE 5
#define EXP_SIZE 5

typedef int* STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}ST;

void StackInit(ST* st);
void StackPush(ST* st, const STDataType x);
void StackPop(ST* st);
void StackDestory(ST* st);
STDataType StackTopData(const ST* st);
_Bool StackEmpty(const ST* st);

void StackInit(ST* st)
{
	st->data = (STDataType*)malloc(INIT_SIZE * sizeof(STDataType));
	if (st->data == NULL)
	{
		perror("StackInit:");
		return;
	}
	st->capacity = INIT_SIZE;
	st->top = 0;
}

void StackPush(ST* st, const STDataType x)
{
	assert(st);
	if (st->top == st->capacity)
	{
		//expand
		STDataType* tmp = (STDataType*)realloc(st->data, sizeof(STDataType) * (st->top + EXP_SIZE));
		if (tmp != NULL)
		{
			st->data = tmp;
			st->capacity += EXP_SIZE;
		}
		else
		{
			perror("Expand:");
			return;
		}
	}
	st->data[st->top] = x;
	st->top++;
}

void StackPop(ST* st)
{
	assert(st);
	assert(st->top > 0);
	st->top--;
}

void StackDestory(ST* st)
{
	free(st->data);
	st->data = NULL;
}

STDataType StackTopData(const ST* st)
{
	assert(st);
	assert(st->top > 0);//²»ÔÊÐíÕ»Îª¿Õ
	return st->data[st->top - 1];
}

_Bool StackEmpty(const ST* st)
{
	assert(st);
	return st->top == 0;
}

int StackSize(const ST* st)
{
	return st->top;
}
//**----------------------------------------------------

ST path;

void PrintStack(ST* ps)
{
	ST rPath;
	StackInit(&rPath);
	while (!StackEmpty(ps))
	{
		StackPush(&rPath, StackTopData(ps));
		StackPop(ps);
	}
	while (!StackEmpty(&rPath))
	{
		int* tmp = StackTopData(&rPath);
		printf("(%d,%d)\n", tmp[0], tmp[1]);
		StackPop(&rPath);
	}
}

bool FindPath(int** maze, int row, int col, int x, int y)
{
	int* Pos = (int*)malloc(sizeof(int) * 2);
	Pos[0] = x;
	Pos[1] = y;
	StackPush(&path, Pos);

	if (x < 0 || x >= row || y < 0 || y >= col || maze[x][y] != 0)
	{
		StackPop(&path);
		return false;
	}

	if ((x == row - 1) && (y == col - 1))
	{
		return true;
	}

	maze[x][y] = 2;

	bool res = FindPath(maze, row, col, x - 1, y) ||
		FindPath(maze, row, col, x + 1, y) ||
		FindPath(maze, row, col, x, y - 1) ||
		FindPath(maze, row, col, x, y + 1);

	if (res == false)
	{
		StackPop(&path);
	}
	return res;
}

int main()
{
	int row = 0;
	int col = 0;
	scanf("%d %d", &row, &col);

	int** maze = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++)
	{
		maze[i] = (int*)malloc(sizeof(int) * col);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}

	StackInit(&path);
	FindPath(maze, row, col, 0, 0);
	PrintStack(&path);

	for (int i = 0; i < row; i++)
	{
		free(maze[i]);
		maze[i] = NULL;
	}
	maze = NULL;
	return 0;
}