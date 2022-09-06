#define _CRT_SECURE_NO_WARNINGS 1

//扫雷复习

#include"game.h"

void menu()
{
	printf("***---------------------***\n");
	printf("***----1.play 0.exit----***\n");
	printf("***---------------------***\n");
}

void game()
{
	//定义棋盘
	char mine[ROWS][COLS] = { 0 };//存放雷的信息
	char show[ROWS][COLS] = { 0 };//存放扫雷信息
	InitBoard(mine, ROWS, COLS, '0');//初始化棋盘
	InitBoard(show,ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);//打印棋盘
	SetMine(mine,ROW,COL);//布雷
	//DisplayBoard(mine, ROW, COL);//测试棋盘
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
				printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}