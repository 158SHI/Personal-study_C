#define _CRT_SECURE_NO_WARNINGS 1

//ɨ��

#include"game.h"

void menu()
{
	printf("***---------  *ɨ��*  -------***\n");
	printf("***------ *  1.play  * ------***\n");
	printf("***------ *  0.exit  * ------***\n");
	printf("***--------------------------***\n");
}

void game()
{
	//��������
	//��ʼ������
	//����
	//ɨ��

	//��������
	char mine[ROWS][ROWS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//��ʼ������
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//��ӡ���̲���
	//Displayboard(mine,ROWS,COLS);
	Displayboard(show, ROWS, COLS);

	//����
	Setmine(mine,ROWS,COLS);
	//Displayboard(mine,ROWS,COLS);

	//ɨ��
	Swapmine(mine, show, ROWS, COLS);
}

int main()
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
			system("cls");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			Sleep(3000);
			system("cls");
			break;
		}
	} while (input);
	return 0;
}