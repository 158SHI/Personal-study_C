#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j = 0;
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j = 0;
	for ( i = 0; i <=row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for ( i = 1; i <=row; i++)
	{
		printf("%d ", i);
		for ( j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;//1��9
		y = rand() % col + 1;
		if (board[x][y]=='0')
		{
			//����
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1]) - 8*'0';
}

void ExcludeMine(char mine[ROWS][COLS], char show[ROWS][COLS],int x, int y)
{
	int ret = get_mine_count(mine,x,y);
	if (ret != 0)
	{
		show[x][y] = ret + '0';
		system("cls");
	}
	else
	{
		show[x][y] = ' ';
		if (show[x - 1][y] == '*')
		{
			ExcludeMine(mine, show, x - 1, y);
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
		if (show[x + 1][y] == '*')
		{
			ExcludeMine(mine, show, x + 1, y);
		}
		if (show[x + 1][y+1] == '*')
		{
			ExcludeMine(mine, show, x + 1, y+1);
		}
		if (show[x + 1][y-1] == '*')
		{
			ExcludeMine(mine, show, x + 1, y-1);
		}
	}
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x, y = 0;
	int win = 0;
	while(win<row*col-EASY_COUNT)
	{
		printf("������Ҫɨ�׵�λ�õ�����>:");
        scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			//�Ϸ�
			if (mine[x][y]=='1')//����
			{
				printf("���ź����㱻ը���ˣ�\n");
				DisplayBoard(mine, row, col);
				Sleep(2500);
				system("cls");
				break;
			}
			else//������
			{
				ExcludeMine(mine, show, x, y);//�жϺ���ʾ
				DisplayBoard(show, row, col);
			}
		}
		else
		{
			//���Ϸ�
			printf("����Ƿ�������������\n");
		}
	}
	if (win==row*col-EASY_COUNT)
	{
		printf("��ϲ��,���׳ɹ���\n");
	}
}