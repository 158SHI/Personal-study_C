#define _CRT_SECURE_NO_WARNINGS 1

#include"game02.h"


void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
    for (int i = 0; i <= row; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i <= col; i++)
    {
        printf("--");
    }

    printf("\n");

    for (int i = 1; i <= row; i++)
    {
        printf("%d|", i);
        for (int j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("||\n");
    }
    for (int i = 0; i <= col; i++)
    {
        printf("--");
    }
    printf("\n");
}

void Setmine(char board[ROWS][COLS], int rows, int cols)
{
    int times = EASY_COUNT;
    while (times)
    {
        int x = rand() % 9 + 1;
        int y = rand() % 9 + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            times--;
        }
    }
}

int Swapmine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols, int* count)
{
    /*
    1.被炸死或者扫雷成功返回0
    2.否则返回1
    */
    int x, y;
    while (1)
    {
        printf("请输入要扫雷的坐标\n");
        printf("(若要退出该操作，请输入0 0)\n>:");
        scanf("%d %d", &x, &y);
        if (x == 0 && y == 0)
        {
            system("cls");
            Displayboard(show, ROW, COL);
            return 1;
        }
        //判断输入是否合法
        if (x > 0 && x <= ROW && y > 0 && y <= COL)
        {
            //合法
            if (show[x][y] != '*')
            {
                printf("该位置已被检查!\n");
                continue;
            }

            if (mine[x][y] == '1')//是雷
            {
                printf("很遗憾，你被炸死了！\n");
                Sleep(3000);
                system("cls");
                Displayboard(show, ROW, COL);
                Displayboard(mine, ROW, COL);
                return 0;
            }
            else//不是雷
            {
                Exclude(mine, show, x, y);//判断和提示
                system("cls");
                Displayboard(show, ROW, COL);
                print_count(count);

                int win = get_win(show, ROW, COL);
                if (win == EASY_COUNT)
                {
                    printf("恭喜你，扫雷成功!!!\n");
                    Displayboard(mine, ROW, COL);
                    return 0;
                }
                return 1;
            }
        }
        else
        {
            //不合法
            printf("输入非法，请重新输入\n");
        }
    }
    return 1;
}

int get_win(char show[ROWS][COLS], int row, int col)
{
    int ret = 0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (show[i][j] == '*')
            {
                ret++;
            }
        }
    }
    return ret;
}

void Exclude(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
    int counts = get_mine_count(mine, x, y);
    if (counts != 0)
    {
        show[x][y] = counts + '0';
    }
    else
    {
        show[x][y] = ' ';
        if (show[x - 1][y - 1] == '*' && ((x - 1) >= 1 && (x - 1) <= ROW) && ((y - 1) >= 1 && (y - 1) <= COL))
        {
            Exclude(mine, show, x - 1, y - 1);
        }
        if (show[x][y - 1] == '*' && (x >= 1 && x <= ROW) && ((y - 1) >= 1 && (y - 1) <= COL))
        {
            Exclude(mine, show, x, y - 1);
        }
        if (show[x + 1][y - 1] == '*' && ((x + 1) >= 1 && (x + 1) <= ROW) && ((y - 1) >= 1 && (y - 1) <= COL))
        {
            Exclude(mine, show, x + 1, y - 1);
        }
        if (show[x - 1][y] == '*' && ((x - 1) >= 1 && (x - 1) <= ROW) && (y >= 1 && y <= COL))
        {
            Exclude(mine, show, x - 1, y);
        }
        if (show[x + 1][y] == '*' && ((x + 1) >= 1 && (x + 1) <= ROW) && (y >= 1 && y <= COL))
        {
            Exclude(mine, show, x + 1, y);
        }
        if (show[x - 1][y + 1] == '*' && ((x - 1) >= 1 && (x - 1) <= ROW) && ((y + 1) >= 1 && (y + 1) <= COL))
        {
            Exclude(mine, show, x - 1, y + 1);
        }
        if (show[x][y + 1] == '*' && (x >= 1 && x <= ROW) && ((y + 1) >= 1 && (y + 1) <= COL))
        {
            Exclude(mine, show, x, y + 1);
        }
        if (show[x + 1][y + 1] == '*' && ((x + 1) >= 1 && (x + 1) <= ROW) && ((y + 1) >= 1 && (y + 1) <= COL))
        {
            Exclude(mine, show, x + 1, y + 1);
        }
    }
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x - 1][y - 1] +
        mine[x][y - 1] +
        mine[x + 1][y - 1] +
        mine[x - 1][y] +
        mine[x + 1][y] +
        mine[x - 1][y + 1] +
        mine[x][y + 1] +
        mine[x + 1][y + 1] - 8 * '0';
}

void mark_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int* count)
{
    int x, y;
    while (1)
    {
        printf("请输入要标记的坐标\n");
        printf("(若要退出标记，请输入0 0)\n>:");
        scanf("%d %d", &x, &y);
        if (x == 0 && y == 0)
        {
            system("cls");
            Displayboard(show, row, col);
            break;
        }

        if (x > 0 && x <= row && y > 0 && y <= col)
        {
            //合法
            if (show[x][y] == '#')
            {
                printf("该位置已被标记，请重新输入>\n");
            }
            else if (show[x][y] == ' ')
            {
                printf("该位置无法被标记，请重新输入>\n");
            }
            else
            {
                if (mine[x][y] == '1')
                {
                    (*count)--;
                }
                show[x][y] = '#';
                system("cls");
                Displayboard(show, row, col);
                print_count(count);
                break;
            }
        }
        else
        {
            //非法
            printf("输入非法，请重新输入>");
        }
    }
}

void unmark_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int* count)
{
    int x, y;
    while (1)
    {
        printf("请输入要标记的坐标\n");
        printf("(若要退出该操作，请输入0 0)\n>:");
        scanf("%d %d", &x, &y);
        if (x == 0 && y == 0)
        {
            system("cls");
            Displayboard(show, ROW, COL);
            break;
        }
        if (x > 0 && x <= row && y > 0 && y <= col)
        {
            //合法
            if (show[x][y] != '#')
            {
                printf("该位置未被标记，请重新输入>\n");
            }
            else
            {
                if (mine[x][y] == '1')
                {
                    (*count)++;
                }
                show[x][y] = '*';
                system("cls");
                Displayboard(show, row, col);
                print_count(count);
                break;
            }
        }
        else
        {
            //非法
            printf("输入非法，请重新输入>\n");
        }
    }
}

void print_count(int* count)
{
    printf("\n剩余雷的数量:%d\n", *count);
}