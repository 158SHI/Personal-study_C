#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i, j = 0;
	for ( i = 0; i < ROWS; i++)
	{
		for ( j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j = 0;
	for ( i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for ( i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for ( j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int x, y = 0;
	int count = EASY_COUNT;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void ExcludeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int ret = get_mine_count(mine, show, x, y);
	if (ret != 0)
	{
		show[x][y] = ret + '0';
	}
	else
	{
		show[x][y] = ' ';
		if (show[x-1][y]=='*')
		{
			ExcludeMine(mine, show,x-1,y);
		}
		if (show[x - 1][y-1] == '*')
		{
			ExcludeMine(mine, show, x - 1, y-1);
		}
		if (show[x - 1][y+1] == '*')
		{
			ExcludeMine(mine, show, x - 1, y+1);
		}
		if (show[x][y-1] == '*')
		{
			ExcludeMine(mine, show, x, y-1);
		}
		if (show[x][y+1] == '*')
		{
			ExcludeMine(mine, show, x, y+1);
		}
		if (show[x+1][y] == '*')
		{
			ExcludeMine(mine, show, x + 1, y);
		}
		if (show[x + 1][y-1] == '*')
		{
			ExcludeMine(mine, show, x + 1, y-1);
		}
		if (show[x + 1][y+1] == '*')
		{
			ExcludeMine(mine, show, x + 1, y+1);
		}
	}
}

int CheckShow(char show[ROWS][COLS], int row, int col)//判断输赢
{
	int i, j = 0;
	int win = 0;
	for ( i = 1; i <=row; i++)
	{
		for ( j = 1; j <= col; j++)
		{
			if (show[i][j]== '*');
			{
				win++;
			}
		}
	}
	return win;
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int x, y = 0;
	int win = 0;
	while (1)//
	{
		printf("请输入要扫雷的位置的坐标(x/y) >:");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)//判断输入是否合法
		{
			//合法
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n");//是雷
				DisplayBoard(mine, ROW, COL);
				Sleep(3000);
				system("cls");
				break;
			}
			else//不是雷
			{
				ExcludeMine(mine, show, x, y);//判断和提示
				system("cls");
				DisplayBoard(show, ROW, COL);
				win = CheckShow(show, row, col);
				if (win==EASY_COUNT)
				{
					break;
				}
			}
		}
		else
		{
			//不合法
			printf("输入非法，请重新输入\n");
		}
		if (win==EASY_COUNT)
		{
			printf("恭喜你，扫雷成功！\n");
		}
	}
}