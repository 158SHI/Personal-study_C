#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;





#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//**----------------------------------------------------
#define INIT_SIZE 10
#define EXP_SIZE 10

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
bool StackEmpty(const ST* st);

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
	assert(st->top > 0);//不允许栈为空
	return st->data[st->top - 1];
}

bool StackEmpty(const ST* st)
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
ST minPath;

void PrintStack(ST* ps)
{
	ST rPath;
	StackInit(&rPath);
	while (!StackEmpty(ps))
	{
		StackPush(&rPath, StackTopData(ps));
		StackPop(ps);
	}
	StackDestory(ps);
	while (StackSize(&rPath) > 1)
	{
		int* tmp = StackTopData(&rPath);
		printf("[%d,%d],", tmp[0], tmp[1]);
		StackPop(&rPath);
	}
	int* tmp = StackTopData(&rPath);
	printf("[%d,%d]", tmp[0], tmp[1]);
	StackPop(&rPath);

	StackDestory(&rPath);
}

void StackCopy(ST* sTDest, ST* sTSour)
{
	StackDestory(sTDest);
	StackInit(sTDest);
	sTDest->data = (STDataType*)malloc(sizeof(STDataType) * StackSize(sTSour));
	memcpy(sTDest->data, sTSour->data, sizeof(STDataType) * StackSize(sTSour));
	sTDest->top = sTSour->top;
	sTDest->capacity = sTSour->capacity;
}

void FindPath(int** maze, int row, int col, int x, int y, int p)
{
	int* Pos = (int*)malloc(sizeof(int) * 2);
	Pos[0] = x;
	Pos[1] = y;
	StackPush(&path, Pos);

	if (x < 0 || x >= row || y < 0 || y >= col || maze[x][y] != 1)
	{
		StackPop(&path);
		return;
	}

	if ((x == 0) && (y == col - 1))
	{
		if (p >= 0 && (StackEmpty(&minPath) || StackSize(&path) < StackSize(&minPath)))
		{
			StackCopy(&minPath, &path);
			//注意此时不能直接return
			//终点位置上下左右四个方向均无法到达，故执行：从终点位置向前重置路径为 1
		}
	}

	maze[x][y] = 2;

	FindPath(maze, row, col, x - 1, y, p - 3);
	FindPath(maze, row, col, x + 1, y, p);
	FindPath(maze, row, col, x, y - 1, p - 1);
	FindPath(maze, row, col, x, y + 1, p - 1);

	maze[x][y] = 1;
	StackPop(&path);
}

//int main()
//{
//	int row = 0;
//	int col = 0;
//	int p = 0;
//	scanf("%d %d %d", &row, &col, &p);
//
//	int** maze = (int**)malloc(sizeof(int*) * row);
//	for (int i = 0; i < row; i++)
//	{
//		maze[i] = (int*)malloc(sizeof(int) * col);
//	}
//
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			scanf("%d", &maze[i][j]);
//		}
//	}
//
//	StackInit(&path);
//	StackInit(&minPath);
//
//	FindPath(maze, row, col, 0, 0, p);
//
//	if (!StackEmpty(&minPath))
//	{
//		PrintStack(&minPath);
//	}
//	else
//	{
//		printf("Can not escape!\n");
//	}
//
//	for (int i = 0; i < row; i++)
//	{
//		free(maze[i]);
//		maze[i] = NULL;
//	}
//	maze = NULL;
//	return 0;
//}