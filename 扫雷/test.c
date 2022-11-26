#define _CRT_SECURE_NO_WARNINGS 1

//扫雷

#include"game02.h"

const void menu()
{
    printf("***---------  *扫雷*  -------***\n");
    printf("***------ *  1.play  * ------***\n");
    printf("***------ *  0.exit  * ------***\n");
    printf("***--------------------------***\n");
}

const void chose_list()
{
    printf("\n|----------------|\n");
    printf("|---- 1.扫雷 ----|\n");
    printf("|--- 2.标记雷 ---|\n");
    printf("|--3.取消标记雷--|\n");
    printf("|----------------|\n");
    printf("\n");
}

void game()
{
    int count = EASY_COUNT;
    //定义棋盘
    //初始化棋盘
    //布雷
    // 
    //扫雷

    //定义棋盘
    char mine[ROWS][ROWS] = { 0 };
    char show[ROWS][COLS] = { 0 };

    //初始化棋盘
    Initboard(mine, ROWS, COLS, '0');
    Initboard(show, ROWS, COLS, '*');

    //Displayboard(mine,ROWS,COLS);//打印棋盘测试

    //布雷
    Setmine(mine, ROWS, COLS);
    Displayboard(show, ROW, COL);
    print_count(&count);
    //Displayboard(mine,ROWS,COLS);//测试

    int ret = 1;
    int input = 0;
    while (ret)
    {
        chose_list();//选择列表
        printf("请选择你的操作>:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            //扫雷
            ret = Swapmine(mine, show, ROWS, COLS, &count);
            break;
        case 2:
            mark_mine(show, mine, ROW, COL, &count);//标记雷
            break;
        case 3:
            unmark_mine(show, mine, ROW, COL, &count);//取消标记雷
            break;
        default:
            system("cls");
            Displayboard(show, ROW, COL);
            printf("选择错误，请重新选择>\n");
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
        printf("请选择>:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            system("cls");
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误，请重新选择\n");
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