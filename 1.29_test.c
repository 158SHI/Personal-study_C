#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int n = matrixSize;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < (n + 1) / 2; j++)
        {
            //注意理清4个关键位置的坐标间的数学关系
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
}