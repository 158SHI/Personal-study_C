#define _CRT_SECURE_NO_WARNINGS 1

//ɨ�׸�ϰ

#include"game.h"

void menu()
{
	printf("***---------------------***\n");
	printf("***----1.play 0.exit----***\n");
	printf("***---------------------***\n");
}

void game()
{
	//��������
	char mine[ROWS][COLS] = { 0 };//����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//���ɨ����Ϣ
	InitBoard(mine, ROWS, COLS, '0');//��ʼ������
	InitBoard(show,ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);//��ӡ����
	SetMine(mine,ROW,COL);//����
	//DisplayBoard(mine, ROW, COL);//��������
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
				printf("ѡ���������������\n");
			break;
		}
	} while (input);
	return 0;
}