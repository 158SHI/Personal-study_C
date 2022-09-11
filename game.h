#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define ROWS 11
#define COLS 11
#define ROW ROWS-2
#define COL COLS-2
#define EAST_COUNT 10


void InitBoard(char board[ROWS][COLS], int rows, int cols,char ret);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col);
void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);
void ExcludeMine(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y);
int CheckShow(char show[ROWS][COLS], int row, int col, int x, int y);