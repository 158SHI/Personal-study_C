#define _CRT_SECURE_NO_WARNINGS 1

//ɨ��

#include"game.h"

void menu()
{
	printf("        <<  ɨ��  >>\n");
	printf("***----------------------***\n");
	printf("***---1.play -- 0.exit---***\n");
	printf("***----------------------***\n");
}

void game()
{
	//��������
	char mine[ROWS][COLS] = { 0 };//��������׵�����
	char show[ROWS][COLS] = { 0 };//����ɨ�׵�����
	InitBoard(mine,ROWS,COLS,'0');//��ʼ������׵�����
	InitBoard(show, ROWS, COLS, '*');//��ʼ��ɨ������
	DisplayBoard(show,ROW,COL);//��ӡ����
	SetMine(mine,ROW,COL);//����
	FindMine(mine,show,ROW,COL);//ɨ��
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			Sleep(2000);
			system("cls");
			break;
		}
	} while (input);
}