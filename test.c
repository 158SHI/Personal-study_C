#define _CRT_SECURE_NO_WARNINGS 1

//扫雷

#include"game.h"

void menu()
{
	printf("***---------  *扫雷*  -------***\n");
	printf("***------ *  1.play  * ------***\n");
	printf("***------ *  0.exit  * ------***\n");
	printf("***--------------------------***\n");
}

void game()
{
	//定义棋盘
	//初始化棋盘
	//布雷
	//扫雷

	//定义棋盘
	char mine[ROWS][ROWS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化棋盘
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//打印棋盘测试
	//Displayboard(mine,ROWS,COLS);
	Displayboard(show, ROWS, COLS);

	//布雷
	Setmine(mine,ROWS,COLS);
	//Displayboard(mine,ROWS,COLS);

	//扫雷
	Swapmine(mine, show, ROWS, COLS);
}

int main()
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
			system("cls");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			Sleep(3000);
			system("cls");
			break;
		}
	} while (input);
	return 0;
}