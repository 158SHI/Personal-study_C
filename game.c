#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void InitBoard(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			board[i][j] = ' ';//将数组初始化为空
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		int j = 0;
		for ( j = 0; j < col; j++)//打印每一行的数据
		{
			printf(" %c ", board[i][j]);
			if (j<col-1)
			{
				printf("|");
			}
		}
		printf("\n");//打印每一行的数据
		if (i<row-1)
		{
			for ( j = 0; j < row; j++)//打印分隔行
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	printf("玩家下\n");
	printf("请输入要下棋的位置坐标>:");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已被占用,请重新输入>:");
			}
		}
		else
		{
			printf("非法输入，请重新输入>:");
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	printf("电脑下\n");
	Sleep(1700);
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL],int row,int col)
{
	int i, j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			if (board[i][j] ==  ' ')//棋盘没满
			{
				return 0;
			}
		}
	}
	return 1;//棋盘满了
}

int IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		if (board[i][0]==board[i][1] && board[i][1] == board[i][2] && board[i][0]!=' ')
		{
			return board[i][0];
		}
	}
	for ( i = 0; i < col; i++)
	{
		if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	if (IsFull(board,ROW,COL) == 1)
	{
		return'Q';
	}
	return 'C';
}