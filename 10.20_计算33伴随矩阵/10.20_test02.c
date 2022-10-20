#define _CRT_SECURE_NO_WARNINGS 1

/*
项目描述：输入一个3*3矩阵，输出该矩阵的伴随矩阵
*/

#include"test.h"

int main()
{
	/*
	1.输入矩阵
	2.计算伴随矩阵
	*/

	int matrix[3][3] = {0};
	InitMat(matrix,ROW,COL);//初始化矩阵
	//DisplayMat(matrix, ROW, COL);//打印矩阵以测试
	PutinMat(matrix, ROW, COL);//输入矩阵
	//DisplayMat(matrix, ROW, COL);//打印矩阵以测试
	AdjMat(matrix,ROW,COL);//计算伴随矩阵

	return 0;
}