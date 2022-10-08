#define _CRT_SECURE_NO_WARNINGS 1


/*
二维数组的查找

在一个二维数组中（每一个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样一个二维数组和一个整数，判断数组中是否含有该数。
若有，请输出该元素的下标。
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

//插入排序
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
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

例如：{1, 2, 3, 4, 5, 6, 7} 调整后为：{1, 3, 5, 7, 2, 4, 6}。
*/
#include<stdio.h>

void Resorb(int arr[], int sz)
{
	for (int i = 1; i < sz; i++)
	{
		if (arr[i]%2 != 0)//若是奇数，进入排序
		{
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] % 2 == 0)//若是偶数，继续左移
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