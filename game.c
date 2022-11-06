#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int rows, int cols)
{
	for (int i = 0; i <= ROW; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 0; i <= COL; i++)
	{
		printf("--");
	}

	printf("\n");

	for (int i = 1; i <= ROW; i++)
	{
		printf("%d|", i);
		for (int j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("||\n");
	}
	for (int i = 0; i < COLS; i++)
	{
		printf("- ");
	}
	printf("\n");
}

void Setmine(char board[ROWS][COLS], int rows, int cols)
{
	int times = EASY_COUNT;
	while (times)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			times--;
		}
	}
}

void Swapmine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
	int x, y;
	while (1)
	{
		printf("������Ҫɨ�׵�����>:");
		scanf("%d %d", &x, &y);
		//�ж������Ƿ�Ϸ�
		if (x > 0 && x <= ROW && y > 0 && y <= COL)
		{
			//�Ϸ�
			if (mine[x][y] == '1')//����
			{
				printf("���ź����㱻ը���ˣ�\n");
				Sleep(3000);
				system("cls");
				Displayboard(mine, ROWS, COLS);
				break;
			}
			else//������
			{
				Exclude(mine, show, x, y);//�жϺ���ʾ
				//�ж���Ӯ
				system("cls");
				Displayboard(show, ROWS, COLS);

				int win = get_win(show, ROW, COL);
				if (win == EASY_COUNT)
				{
					printf("��ϲ�㣬ɨ�׳ɹ�!!!\n");
					Displayboard(mine, ROWS, COLS);
					break;
				}
			}
		}
		else
		{
			//���Ϸ�
			printf("����Ƿ�������������\n");
		}
	}
}

int get_win(char show[ROWS][COLS], int row, int col)
{
	int ret = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				ret++;
			}
		}
	}
	return ret;
}

void Exclude(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y)
{
	int counts = get_mine_count(mine,x,y);
	if (counts != 0)
	{
		show[x][y] = counts + '0';
	}
	else
	{
		show[x][y] = ' ';
		if (show[x-1][y-1] == '*')
		{
			Exclude(mine, show, x-1, y-1);
		}
		if (show[x][y-1] == '*')
		{
			Exclude(mine, show, x, y-1);
		}
		if (show[x+1][y-1] == '*')
		{
			Exclude(mine, show, x+1, y-1);
		}
		if (show[x-1][y] =='*')
		{
			Exclude(mine, show, x-1, y);
		}
		if (show[x+1][y] == '*')
		{
			Exclude(mine, show, x+1, y);
		}
		if (show[x-1][y+1]=='*')
		{
			Exclude(mine, show, x-1, y+1);
		}
		if (show[x][y+1] == '*')
		{
			Exclude(mine, show, x, y+1);
		}
		if (show[x+1][y+1] == '*')
		{
			Exclude(mine, show, x+1, y+1);
		}
	}
}

int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x - 1][y] +
		mine[x + 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] - 8 * '0';
}