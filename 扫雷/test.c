#define _CRT_SECURE_NO_WARNINGS 1

//ɨ��

#include"game02.h"

const void menu()
{
    printf("***---------  *ɨ��*  -------***\n");
    printf("***------ *  1.play  * ------***\n");
    printf("***------ *  0.exit  * ------***\n");
    printf("***--------------------------***\n");
}

const void chose_list()
{
    printf("\n|----------------|\n");
    printf("|---- 1.ɨ�� ----|\n");
    printf("|--- 2.����� ---|\n");
    printf("|--3.ȡ�������--|\n");
    printf("|----------------|\n");
    printf("\n");
}

void game()
{
    int count = EASY_COUNT;
    //��������
    //��ʼ������
    //����
    // 
    //ɨ��

    //��������
    char mine[ROWS][ROWS] = { 0 };
    char show[ROWS][COLS] = { 0 };

    //��ʼ������
    Initboard(mine, ROWS, COLS, '0');
    Initboard(show, ROWS, COLS, '*');

    //Displayboard(mine,ROWS,COLS);//��ӡ���̲���

    //����
    Setmine(mine, ROWS, COLS);
    Displayboard(show, ROW, COL);
    print_count(&count);
    //Displayboard(mine,ROWS,COLS);//����

    int ret = 1;
    int input = 0;
    while (ret)
    {
        chose_list();//ѡ���б�
        printf("��ѡ����Ĳ���>:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            //ɨ��
            ret = Swapmine(mine, show, ROWS, COLS, &count);
            break;
        case 2:
            mark_mine(show, mine, ROW, COL, &count);//�����
            break;
        case 3:
            unmark_mine(show, mine, ROW, COL, &count);//ȡ�������
            break;
        default:
            system("cls");
            Displayboard(show, ROW, COL);
            printf("ѡ�����������ѡ��>\n");
            break;
        }
    }
}

void test()
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
}

int main()
{
    test();
    return 0;
}