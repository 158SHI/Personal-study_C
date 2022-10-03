#define _CRT_SECURE_NO_WARNINGS 1

//有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
//#include<stdio.h>
//int main()
//{
//	int x, y, z;
//	int count = 0;
//	for ( x = 1; x < 5; x++)
//	{
//		for ( y = 1; y < 5; y++)
//		{
//			for ( z = 1; z < 5; z++)
//			{
//				if (x!=y && y!=z && x!=z)
//				{
//					int num = x * 100 + y * 10 + z;
//					printf("%d ", num);
//					count++;
//				}
//			}
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}//穷举法


/*

二维数组的查找

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输出要查找元素的下标。

*/

//二分法
//#include<stdio.h>
//int main()
//{
//	int arr[4][4] = { 
//		1 ,2 ,3 ,4,
//		5 ,6 ,7 ,8,
//		9,10,11,12,
//	    13,14,15,16};
//	int row = 0;
//	int col = 3;
//	int n;
//	scanf("%d", &n);
//	while (arr[row][col] != n)
//	{
//		if (arr[row][col]>n)//若右上角元素比目标元素大，则该列元素都比目标元素大
//		{
//			col--;
//		}
//		else//若右上角元素比目标元素小，则该行元素都比目标元素小
//		{
//			row++;
//		}
//	}
//	printf("%d %d", row, col);
//	return 0;
//}


/*

二维数组的查找

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

*/

//#include<stdio.h>
//
//int Judge(int arr[4][4], int row, int col, int n)
//{
//	while (row>=0 && row<4 && col>=0 && col<4)//判断row,col的合法性。若在寻找过程中变为非法，则说明数组中不含目标元素
//	{
//		if (arr[row][col] > n)
//		{
//			col--;
//		}
//		else if (arr[row][col] < n)
//		{
//			row++;
//		}
//		else//找到了目标元素，说明含有该元素，返回 1
//		{
//			return 1;
//			break;
//		}
//	}
//	return 0;//为找到该元素，返回 0
//}
//
//int main()
//{
//	int arr[4][4] = {
//		1 ,2 ,3 ,4,
//		5 ,6 ,7 ,8,
//		9,10,11,12,
//		13,14,15,16 };
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int row = 0;
//		int col = 3;
//		int ret = Judge(arr, row, col, n);//进行判断
//		if (ret == 1)
//		{
//			printf("true\n");
//		}
//		else
//		{
//			printf("false\n");
//		}
//	}
//	return 0;
//}

//求第n个斐波那契数
#include<stdio.h>

//递归
//int Fib(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//非递归

//#include<stdio.h>
//int main()
//{
//	int a = 1, b = 0, c = 0, n;
//	scanf("%d", &n);
//	for (int i = 0 ; i < n ; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	printf("%d\n", c);
//	return 0;
//}

//青蛙跳台阶
//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 1, c = 0;
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	printf("%d", c);
//	return 0;
//}


/*

旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

*/

//二分法
#include<stdio.h>
int main()
{
	int arr[] = { 4,5,6,2,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0, right = sz - 1;
	while (left<right)
	{
		int mid = left + (right - left) / 2; //避免溢出
		if (arr[mid]>arr[right])//在左半部分
		{
			left = mid + 1;
		}
		else if (arr[mid]<arr[right])//在右半部分
		{
			right = mid;//不能mid-1，因为mid很有可能是最小值
		}
		else//arr[mid]==arr[right]
		{
			right--;//不能left++,因为可能错过最小值
		}
	}
	printf("%d\n", arr[left]);
	return 0;
}