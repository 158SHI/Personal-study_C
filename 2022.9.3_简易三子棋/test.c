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
	char board[ROW][COL] = { 0 }; //����������������Ϣ
	InitBoard(board, ROW, COL); //��ʼ������
	DisplayBoard(board, ROW, COL); //��ӡ����
	//����
	while (1)
	{
		PlayerMove(board, ROW, COL);//����ƶ�
		system("cls");
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret=IsWin(board,ROW,COL);//�ж���Ӯ
		// ret='*'���Ӯ
		//ret='#'����Ӯ
		//ret='Q'ƽ��
		//ret='C'��Ϸ����
		if (ret != 'C')
		{
			break;
		}
		ComptuerMove(board, ROW, COL);//�����ƶ�
		system("cls");
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret=IsWin(board,ROW,COL);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��ϲ��ȡ��ʤ����\n");
		Sleep(2000);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("���ź�����ʧ����\n");
		Sleep(2000);
		system("cls");
	}
	else
	{
		printf("˫��ƽ��\n");
	}
}

 main(void)
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
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}