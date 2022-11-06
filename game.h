#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>


#define ROWS 11
#define COLS 11
#define ROW ROWS-2
#define COL COLS-2
#define EASY_COUNT 10

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void Displayboard(char board[ROWS][COLS], int rows, int cols);
void Setmine(char board[ROWS][COLS], int rows, int cols);
void Swapmine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols);
void Exclude(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y);
int get_win(char show[ROWS][COLS], int row, int col);