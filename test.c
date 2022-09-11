#define _CRT_SECURE_NO_WARNINGS 1

//É¨À×
#include"game.h"

void menu()
{
	printf("***---------------------***\n");
	printf("***---1.play - 0.exit---***\n");
	printf("***---------------------***\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//¶¨Òå´æ´¢ÆåÅÌ
	char show[ROWS][COLS] = { 0 };//¶¨ÒåÏÔÊ¾ÆåÅÌ
	InitBoard(mine, ROWS, COLS,'0');//
	InitBoard(show, ROWS, COLS,'*');//³õÊ¼»¯ÆåÅÌ
	DisplayBoard(show, ROW, COL);//´òÓ¡ÆåÅÌ
	//DisplayBoard(mine, ROW, COL);//´òÓ¡²¢²âÊÔÆåÅÌ
	SetMine(mine, ROW, COL);//²¼À×
	//DisplayBoard(mine, ROW, COL);//´òÓ¡²¢²âÊÔÆåÅÌ
	FindMine(show, mine, ROW, COL);//É¨À×
}

int main(void)
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("ÇëÑ¡Ôñ>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("ÍË³öÓÎÏ·");
			break;
		default:
			printf("Ñ¡Ôñ´íÎó£¬ÇëÖØĞÂÑ¡Ôñ>:");
			break;
		}
	} while (input);
	return 0;
}


