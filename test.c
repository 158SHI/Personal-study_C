#define _CRT_SECURE_NO_WARNINGS 1

//ɨ��
#include"game.h"

void menu()
{
	printf("***---------------------***\n");
	printf("***---1.play - 0.exit---***\n");
	printf("***---------------------***\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//����洢����
	char show[ROWS][COLS] = { 0 };//������ʾ����
	InitBoard(mine, ROWS, COLS,'0');//
	InitBoard(show, ROWS, COLS,'*');//��ʼ������
	DisplayBoard(show, ROW, COL);//��ӡ����
	//DisplayBoard(mine, ROW, COL);//��ӡ����������
	SetMine(mine, ROW, COL);//����
	//DisplayBoard(mine, ROW, COL);//��ӡ����������
	FindMine(show, mine, ROW, COL);//ɨ��
}

int main(void)
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ�����������ѡ��>:");
			break;
		}
	} while (input);
	return 0;
}


