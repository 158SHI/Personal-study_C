#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"

void menu()
{
	printf("***--------------------***\n");
	printf("***---1.play  0.exit---***\n");
	printf("***--------------------***\n");
}

void game() 
{
	int ret = 0;
	char board[ROW][COL] = { 0 }; //创建数组存放棋子信息
	InitBoard(board, ROW, COL); //初始化棋盘
	DisplayBoard(board, ROW, COL); //打印棋盘
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家移动
		system("cls");
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret=IsWin(board,ROW,COL);//判断输赢
		// ret='*'玩家赢
		//ret='#'电脑赢
		//ret='Q'平局
		//ret='C'游戏继续
		if (ret != 'C')
		{
			break;
		}
		ComptuerMove(board, ROW, COL);//电脑移动
		system("cls");
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret=IsWin(board,ROW,COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("恭喜你取得胜利！\n");
		Sleep(2000);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("很遗憾，你失败了\n");
		Sleep(2000);
		system("cls");
	}
	else
	{
		printf("双方平局\n");
	}
}

 main(void)
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
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}