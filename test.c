#define _CRT_SECURE_NO_WARNINGS 1

//三子棋

#include"game.h"

void menu()
{
	printf("***----------------------***\n");
	printf("***---1.play -- 0.exit---***\n");
	printf("***----------------------***\n");
}

void game()
{
	char ret = 0;
	//创建棋盘存放棋子信息
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW,COL);//初始化棋盘
	DisplayBoard(board,ROW,COL);//打印棋盘
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下
		system("cls");
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret=Iswin(board,ROW,COL);//判断输赢
		if (ret!='C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下
		system("cls");
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret=Iswin(board,ROW,COL);
		if (ret!='C')
		{
			break;
		}
	}
	if (ret='*')
	{
		printf("恭喜你，获得胜利！\n");
	}
	else if(ret='#')
	{
		printf("很遗憾，你失败了！\n");
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
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}

	} while (input);
	return 0;
}