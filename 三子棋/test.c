#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//������

void menu()
{
    printf("*********-������-*******\n");
    printf("*******   1.play  ******\n");
    printf("*******   0.exit  ******\n");
    printf("************************\n");
}

void game()
{
    char board[ROW][COL];
    init_board(board, ROW, COL);//��ʼ������Ϊ��
    print_board(board, ROW, COL);//��ӡ����
    char ret;
    int count = 0;//�ж�ƽ��
    while (1)
    {
        player_move(board, ROW, COL);//�����
        count++;
        system("cls");
        print_board(board, ROW, COL);
        //ret = is_win(board,ROW,COL);//�ж���Ӯ
        ret = is_win(board, ROW, COL, count);//�ж���Ӯ
        if (ret != 'C')
        {
            break;
        }
        computer_move(board, ROW, COL);//������
        count++;
        system("cls");
        print_board(board, ROW, COL);
        //ret = is_win(board, ROW, COL);
        ret = is_win(board, ROW, COL, count);//�ж���Ӯ
        if (ret != 'C')
        {
            break;
        }
    }
    if (ret == '*')
    {
        printf("��ϲ����ʤ��!!!\n");
    }
    else if (ret == '#')
    {
        printf("���ź�����ʧ����\n");
    }
    else if (ret == 'Q')
    {
        printf("ƽ��\n");
    }
}

void test()
{
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
            break;
        }
    } while (input);
}

int main()
{
    srand((unsigned int)time(NULL));
    test();
    return 0;
}