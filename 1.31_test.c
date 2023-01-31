#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool checkXMatrix(int** grid, int gridSize, int* gridColSize)
{
    int row = gridSize;
    int col = *gridColSize;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                if (grid[i][j] == 0) {
                    return false;
                }
            }
            else if (i + j == row - 1)
            {
                if (grid[i][j] == 0) {
                    return false;
                }
            }
            else
            {
                if (grid[i][j] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}