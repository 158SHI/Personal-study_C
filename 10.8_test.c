#define _CRT_SECURE_NO_WARNINGS 1


/*
��ά����Ĳ���

��һ����ά�����У�ÿһ��һά����ĳ�����ͬ����
ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ����������������һ����ά�����һ���������ж��������Ƿ��и�����
���У��������Ԫ�ص��±ꡣ
*/

//#include<stdio.h>
//
//int Check(int arr[4][4],int n,int row,int col)
//{
//	while (n != arr[row][col] && row>=0 && row<4 && col>=0 && col<4)
//	{
//		if (n > arr[row][col])
//		{
//			row++;
//		}
//		else
//		{
//			col--;
//		}
//	}
//	if (n == arr[row][col])
//	{
//		printf("%d %d\n", row, col);
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int arr[4][4] = {
//	2,3,4,5,
//	6,7,8,9,
//	10,11,12,13,
//	14,15,16,17 };
//	int row = 0;
//	int col = 3;
//	int n;
//	while (printf("Please input the number you want to find>:"),scanf("%d", &n) != EOF)
//	{
//		int ret = Check(arr, n, row, col);
//		if (ret == 0)
//		{
//			printf("No\n");
//		}
//	}
//	return 0;
//}

//��������
//#include<stdio.h>
//
//void Sert_sord(int arr[], int sz)
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int key = arr[i];
//		int j = i - 1;
//		while (j>=0 && arr[j]>key)
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = key;
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,2,5,3,8,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Sert_sorb(arr);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

���磺{1, 2, 3, 4, 5, 6, 7} ������Ϊ��{1, 3, 5, 7, 2, 4, 6}��
*/
#include<stdio.h>

void Resorb(int arr[], int sz)
{
	for (int i = 1; i < sz; i++)
	{
		if (arr[i]%2 != 0)//������������������
		{
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] % 2 == 0)//����ż������������
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Resorb(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}