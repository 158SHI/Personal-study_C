#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//三子棋

void menu()
{
    printf("*********-三子棋-*******\n");
    printf("*******   1.play  ******\n");
    printf("*******   0.exit  ******\n");
    printf("************************\n");
}

void game()
{
    char board[ROW][COL];
    init_board(board, ROW, COL);//初始化棋盘为空
    print_board(board, ROW, COL);//打印棋盘
    char ret;
    int count = 0;//判断平局
    while (1)
    {
        player_move(board, ROW, COL);//玩家下
        count++;
        system("cls");
        print_board(board, ROW, COL);
        //ret = is_win(board,ROW,COL);//判断输赢
        ret = is_win(board, ROW, COL, count);//判断输赢
        if (ret != 'C')
        {
            break;
        }
        computer_move(board, ROW, COL);//电脑下
        count++;
        system("cls");
        print_board(board, ROW, COL);
        //ret = is_win(board, ROW, COL);
        ret = is_win(board, ROW, COL, count);//判断输赢
        if (ret != 'C')
        {
            break;
        }
    }
    if (ret == '*')
    {
        printf("恭喜你获得胜利!!!\n");
    }
    else if (ret == '#')
    {
        printf("很遗憾，你失败了\n");
    }
    else if (ret == 'Q')
    {
        printf("平局\n");
    }
}

void test()
{
    int input = 0;
    do
    {
        menu();
        printf("请选择>:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误，请重新选择\n");
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