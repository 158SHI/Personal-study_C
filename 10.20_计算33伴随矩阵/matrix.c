#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"

void InitMat(int matrix[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void DisplayMat(int matrix[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void PutinMat(int matrix[3][3], int row, int col)
{
	printf("������һ��3*3����:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\n");
}

void AdjMat(int matrix[3][3], int row, int col)//����������
{
	 /*
	 ����������
	 1.���������������ʽ
	 2.����������ʽ�Ľ������¾���
	 //��������Ĵ�������ʽ�ŵ��¾�����
	 */
	CaculateA(matrix,row,col);//���������������ʽ
	//��������������ʽ�ŵ��¾���
}

CaculateA(int matrix[3][3], int row, int col)//���������������ʽ
{	
	int A1[2][2] =
	{
		matrix[1][1],matrix[1][2],
		matrix[2][1],matrix[2][2]
	};
	int A1n = CacuA(A1);//�����������ʽ��ֵ

	//for (int i = 0; i < 2; i++)
	//{
	//	for (int j = 0; j < 2; j++)
	//	{
	//		printf("%d ", A1[i][j]);
	//	}
	//	printf("\n");
	//}//����

	//printf("%d\n", A1n);//����

	int A2[2][2] =
	{
		matrix[1][0],matrix[1][2],
		matrix[2][0],matrix[2][2]
	};
	int A2n = -CacuA(A2);

	int A3[2][2] =
	{
		matrix[1][0],matrix[1][1],
		matrix[2][0],matrix[2][1]
	};
	int A3n = CacuA(A3);

	int A4[2][2] =
	{
		matrix[0][1],matrix[0][2],
		matrix[2][1],matrix[2][2]
	};
	int A4n = -CacuA(A4);

	int A5[2][2] =
	{
		matrix[0][0],matrix[0][2],
		matrix[2][0],matrix[2][2]
	};
	int A5n = CacuA(A5);

	int A6[2][2] =
	{
		matrix[0][0],matrix[0][1],
		matrix[2][0],matrix[2][1]
	};
	int A6n = -CacuA(A6);

	int A7[2][2] =
	{
		matrix[0][1],matrix[0][2],
		matrix[1][1],matrix[1][2]
	};
	int A7n = CacuA(A7);

	int A8[2][2] =
	{
		matrix[0][0],matrix[0][2],
		matrix[1][0],matrix[1][2]
	};
	int A8n = -CacuA(A8);

	int A9[2][2] =
	{
		matrix[0][0],matrix[0][1],
		matrix[1][0],matrix[1][1]
	};
	int A9n = CacuA(A9);


	NewMat(A1n, A2n, A3n, A4n, A5n, A6n, A7n, A8n, A9n);//�����¾���

}

int CacuA(int A[2][2])//�����������ʽ��ֵ
{
	int T = A[0][0] * A[1][1];
	int F = A[0][1] * A[1][0];
	return T - F;
}

void NewMat(A1n, A2n, A3n, A4n, A5n, A6n, A7n, A8n, A9n)//�����¾���
{
	int New[3][3] =
	{
		A1n,A4n,A7n,
		A2n,A5n,A8n,
		A3n,A6n,A9n
	};
	//DisplayMat(New,ROW,COL);//��ӡ�����Բ���

	//����������
	PrintNewMat(New,ROW,COL);
}

PrintNewMat(int New[3][3],int row,int col)
{
	printf("�þ���İ������Ϊ��\n");
	for (int i = 0; i < row; i++)
	{
		printf("|");
		for (int j = 0; j < col; j++)
		{
			printf("%3d ", New[i][j]);
		}
		printf("|\n");
	}
}