#define _CRT_SECURE_NO_WARNINGS 1

//三子棋复习
#include"game.h"

void menu()
{
	printf("***-------------------***\n");
	printf("***---1.play 0.exit---***\n");
	printf("***-------------------***\n");
}

void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };//创建数组存放棋盘信息
	InitBoard(board,ROW,COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下
		system("cls");
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret=IsWin(board, ROW, COL);//判断输赢
		//ret=='*',玩家赢
		//ret =='#'电脑赢
		//ret == 'C' 继续
		//ret == 'Q' 平局
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下
		system("cls");
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret=IsWin(board, ROW, COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("恭喜你，获得胜利!\n");
		Sleep(2000);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("很遗憾，你输了\n");
		Sleep(2000);
		system("cls");
	}
	else
	{
		printf("双方平局\n");
	}
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