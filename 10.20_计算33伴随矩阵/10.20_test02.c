#define _CRT_SECURE_NO_WARNINGS 1

/*
��Ŀ����������һ��3*3��������þ���İ������
*/

#include"test.h"

int main()
{
	/*
	1.�������
	2.����������
	*/

	int matrix[3][3] = {0};
	InitMat(matrix,ROW,COL);//��ʼ������
	//DisplayMat(matrix, ROW, COL);//��ӡ�����Բ���
	PutinMat(matrix, ROW, COL);//�������
	//DisplayMat(matrix, ROW, COL);//��ӡ�����Բ���
	AdjMat(matrix,ROW,COL);//����������

	return 0;
}