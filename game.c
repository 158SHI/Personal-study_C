#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			//printf("---|---|---\n");
			for (int k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("�����>\n���������������>:");
	//�ж��Ƿ�Ϸ�
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			//�Ϸ�
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("��λ���ѱ�ռ�ã�����������\n");
			}
		}
		else
		{
			//���Ϸ�
			printf("����Ƿ�������������>:");
		}
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("��������>\n");
	Sleep(1200);
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

//char is_win(char board[ROW][COL], int row, int col)
char is_win(char board[ROW][COL], int row, int col, int count)

{
	/*
	����*���Ӯ
	����#����Ӯ
	����Qƽ��
	����C��Ϸ����
	*/

	//�ж���
	for (int i = 0; i < row; i++)
	{
		if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//�ж���
	for (int i = 0; i < col; i++)
	{
		if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	//�ж϶Խ���
	if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//�ж�ƽ��
	if (is_full(board,row,col,count) == 1)
	{
		return 'Q';
	}
	return 'C';
}

//int is_full(char board[ROW][COL], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			if (board[i][j] == ' ')
//			{
//				return 0;
//			}
//		}
//	}
//	return 1;
//}

static int is_full(char board[ROW][COL], int row, int col, int count)
{
	if (count == ROW*COL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}