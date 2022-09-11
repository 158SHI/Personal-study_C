#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret)
{
	int i, j = 0;
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			board[i][j] = ret;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i,j = 0;
	for ( i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for ( i = 1; i <= row ; i++)
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
	int count = EAST_COUNT;
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
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

void ExcludeMine(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y)
{
	int ret = get_mine_count(mine,x,y);
	if (ret != 0)
	{
		show[x][y] = ret + '0';
	}
	else
	{
		show[x][y] = ' ';
		if (show[x-1][y-1]=='*')
		{
			ExcludeMine(show,mine,x - 1, y - 1);
		}
		if (show[x-1][y]=='*')
		{
			ExcludeMine(show, mine, x - 1, y);
		}
		if (show[x-1][y+1]=='*')
		{
			ExcludeMine(show, mine, x - 1, y + 1);
		}
		if (show[x][y-1]=='*')
		{
			ExcludeMine(show, mine, x, y - 1);
		}
		if (show[x][y+1]=='*')
		{
			ExcludeMine(show, mine, x, y + 1);
		}
		if (show[x+1][y-1]=='*')
		{
			ExcludeMine(show, mine, x + 1, y - 1);
		}
		if (show[x+1][y]=='*')
		{
			ExcludeMine(show, mine, x + 1, y);
		}
		if (show[x+1][y+1]=='*')
		{
			ExcludeMine(show, mine, x + 1, y + 1);
		}
	}
}

int CheckShow(char show[ROWS][COLS], int row, int col, int x, int y)
{
	int i, j = 0;
	int win = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			if (show[i][j]=='*')
			{
				win++;
				return win;
			}
		}
	}
}

void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int x, y = 0;
	while (1)
	{
		printf("请输入要扫雷的位置坐标>:");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col && show[x][y]=='*')//判断是否合法
		{
			//合法
			if (mine[x][y] == '1')//是雷
			{
				printf("很遗憾，你被炸死了!\n");
				DisplayBoard(mine, row, col);
				Sleep(3000);
				system("cls");
				break;
			}
			else//不是雷
			{
				ExcludeMine(show, mine, x, y);//判断和提示
				system("cls");
				DisplayBoard(show, row, col);
				int win = CheckShow(show, row, col, x, y);
				if (win==EAST_COUNT)
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
	}
	if (CheckShow == EAST_COUNT)
	{
		printf("恭喜你，扫雷成功！\n");
		DisplayBoard(mine, row, col);
	}
}