#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define ROWS 11
#define COLS 11
#define ROW ROWS-2
#define COL COLS-2
#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int row, int col, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
void ExcludeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int get_mine_count(char mine[ROWS][COLS],char show[ROWS][COLS], int x,int y);