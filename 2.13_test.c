#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"

void PlayerInit(Player* p)
{
	p->x = 0;
	p->y = 0;
}

void PrintMap(int map[5][5], int row, int col, Player p)
{
	printf("+");
	for (int i = 0; i < col; i++)
	{
		printf("-");
		if (i < col - 1)
		{
			printf(" ");
		}
	}
	printf("+\n");
	for (int i = 0; i < row; i++)
	{
		printf("|");
		for (int j = 0; j < col; j++)
		{
			if (i == p.x && j == p.y)
			{
				printf("*");
			}
			else
			{
				if (map[i][j] == 0)
				{
					printf(" ");
				}
				else
				{
					printf("#");
				}
			}

			if (j < col - 1)
			{
				printf(" ");
			}
		}		
		printf("|\n");
	}
	printf("+");
	for (int i = 0; i < col; i++)
	{
		printf("-");
		if (i < col - 1)
		{
			printf(" ");
		}
	}
	printf("+\n");
}

void PrintMap2(int map[5][5], int row, int col, Player p)
{
	printf("+");
	for (int i = 0; i < col; i++)
	{
		printf("-");
		if (i < col - 1)
		{
			printf(" ");
		}
	}
	printf("+\n");
	for (int i = 0; i < row; i++)
	{
		printf("|");
		for (int j = 0; j < col; j++)
		{
			if (i == p.x && j == p.y)
			{
				if (map[i][j] == 1)
				{
					printf("#");
				}
				else
				{
					printf("*");
				}
			}
			else
			{
				if (map[i][j] == 0 || map[i][j] == 2)
				{
					printf(" ");
				}
				else
				{
					printf("#");
				}
			}

			if (j < col - 1)
			{
				printf(" ");
			}
		}
		printf("|\n");
	}
	printf("+");
	for (int i = 0; i < col; i++)
	{
		printf("-");
		if (i < col - 1)
		{
			printf(" ");
		}
	}
	printf("+\n");
}

bool Judge(Player* p, int map[5][5], int row, int col)
{
	if (p->x == row - 1 && p->y == col - 1)
	{
		return true;
	}
	return false;
}

void PlayerMove(Player* p, int map[5][5], int row, int col)
{
	char input = 0;
	printf("Input your dirction >:");
	scanf("%c", &input);
	switch (input)
	{
	case 'W':
	case 'w':
		if ((p->x) - 1 >= 0 && map[(p->x) - 1][p->y] != 1)
		{
			p->x--;
		}
		break;
	case 'S':
	case 's':
		if ((p->x) + 1 < row && map[(p->x) + 1][p->y] != 1)
		{
			p->x++;
		}
		break;
	case 'A':
	case 'a':
		if ((p->y) - 1 >= 0 && map[p->x][(p->y) - 1] != 1)
		{
			p->y--;
		}
		break;
	case 'D':
	case 'd':
		if ((p->y) + 1 < col && map[p->x][(p->y) + 1] != 1)
		{
			p->y++;
		}
		break;
	default:
		break;
	}
}

void test(void)
{
	Player p;
	PlayerInit(&p);
	int map[5][5] = {
		0, 1, 0, 0, 0,
		0, 1, 1, 1, 0,
		0, 0, 0, 0, 0,
		0, 1, 1, 1, 0,
		0, 0, 0, 1, 0
	};

	PrintMap(map, 5, 5, p);
	while (1)
	{
		PlayerMove(&p, map, 5, 5);
		system("cls");
		PrintMap(map, 5, 5, p);
		if (Judge(&p, map, 5, 5))
		{
			printf("You Win!\n");
			break;
		}
	}
}

//DFS寻路
bool FindPath(int map[5][5], int row, int col, int x, int y, Player* p)
{

	int* Pos = (int*)malloc(sizeof(int) * 2);
	p->x = x;
	p->y = y;

	Sleep(100);
	system("cls");
	printf("Checking the way......\n");
	PrintMap2(map, row, col, *p);

	if (x < 0 || x >= row || y < 0 || y >= col || map[x][y] != 0) {
		return false;
	}

	if ((x == row - 1) && (y == col - 1)) {
		return true;//到达出口，返回
	}

	map[x][y] = 2;//标记该位置已被搜索

	//搜索四个方向
	bool res = FindPath(map, row, col, x - 1, y, p) ||
		FindPath(map, row, col, x + 1, y, p) ||
		FindPath(map, row, col, x, y - 1, p) ||
		FindPath(map, row, col, x, y + 1, p);

	return res;
}



void test2(void)
{
	Player p;
	PlayerInit(&p);
	int map[5][5] = {
		0, 1, 0, 0, 0,
		0, 1, 1, 1, 0,
		0, 0, 0, 0, 0,
		0, 1, 1, 1, 0,
		0, 0, 0, 1, 0
	};

	PrintMap2(map, 5, 5, p);
	FindPath(map, 5, 5, p.x, p.y, &p);
	if (p.x == 4 && p.y == 4)
	{
		printf("Find the destination!\n");
	}
	//while (1)
	//{
	//	PlayerMove(&p, map, 5, 5);
	//	system("cls");
	//	PrintMap(map, 5, 5, p);
	//	if (Judge(&p, map, 5, 5))
	//	{
	//		printf("You Win!\n");
	//		break;
	//	}
	//}
}


int main()
{
	test2();
	return 0;
}