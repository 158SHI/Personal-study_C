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
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int rows, int cols);
int Swapmine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols, int* count);
void Exclude(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int get_win(char show[ROWS][COLS], int row, int col);
void mark_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int* count);
void unmark_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int* count);
void print_count(int* count);