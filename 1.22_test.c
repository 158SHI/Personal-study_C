#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    if (matrixSize == 0 || *matrixColSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int row = matrixSize;
    int col = *matrixColSize;
    *returnSize = 0;
    int* retNums = (int*)malloc(sizeof(int) * row * col);

    int up = 0;
    int down = row - 1;
    int left = 0;
    int right = col - 1;
    while (up <= down && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            retNums[(*returnSize)++] = matrix[up][i];
        }

        for (int i = up + 1; i <= down; i++)
        {
            retNums[(*returnSize)++] = matrix[i][right];
        }

        if (left < right&& up < down)
        {
            for (int i = right - 1; i > left; i--)
            {
                retNums[(*returnSize)++] = matrix[down][i];
            }

            for (int i = down; i > up; i--)
            {
                retNums[(*returnSize)++] = matrix[i][left];
            }
        }
        up++;
        down--;
        left++;
        right--;
    }
    return retNums;
}

//int main()
//{
//    int* a1 = (int*)malloc(sizeof(int) * 3);
//    int* a2 = (int*)malloc(sizeof(int) * 3);
//    int* a3 = (int*)malloc(sizeof(int) * 3);
//    a1[0] = 1; a1[1] = 2; a1[2] = 3; a1[3] = 4;
//    a2[0] = 5; a2[1] = 6; a2[2] = 7; a2[3] = 8;
//    a3[0] = 9; a3[1] = 10; a3[2] = 11; a3[3] = 12;
//    int* arr[] = { a1, a2, a3 };
//    int retSz = 0;
//    spiralOrder(arr, 3, 4, &retSz);
//    return 0;
//}
