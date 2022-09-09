#define _CRT_SECURE_NO_WARNINGS 1

//������

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
	//�������̴��������Ϣ
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW,COL);//��ʼ������
	DisplayBoard(board,ROW,COL);//��ӡ����
	//����
	while (1)
	{
		PlayerMove(board, ROW, COL);//�����
		system("cls");
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret=Iswin(board,ROW,COL);//�ж���Ӯ
		if (ret!='C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//������
		system("cls");
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret=Iswin(board,ROW,COL);
		if (ret!='C')
		{
			break;
		}
	}
	if (ret='*')
	{
		printf("��ϲ�㣬���ʤ����\n");
	}
	else if(ret='#')
	{
		printf("���ź�����ʧ���ˣ�\n");
	}
	else
	{
		printf("˫��ƽ��\n");
	}
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
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}

	} while (input);
	return 0;
}