#define _CRT_SECURE_NO_WARNINGS 1

//扫雷

#include"game.h"

void menu()
{
	printf("        <<  扫雷  >>\n");
	printf("***----------------------***\n");
	printf("***---1.play -- 0.exit---***\n");
	printf("***----------------------***\n");
}

void game()
{
	//创建棋盘
	char mine[ROWS][COLS] = { 0 };//创建存放雷的棋盘
	char show[ROWS][COLS] = { 0 };//创建扫雷的棋盘
	InitBoard(mine,ROWS,COLS,'0');//初始化存放雷的棋盘
	InitBoard(show, ROWS, COLS, '*');//初始化扫雷棋盘
	DisplayBoard(show,ROW,COL);//打印棋盘
	SetMine(mine,ROW,COL);//布雷
	FindMine(mine,show,ROW,COL);//扫雷
}

int main(void)
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择>:");
    	scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			Sleep(2000);
			system("cls");
			break;
		}
	} while (input);
}