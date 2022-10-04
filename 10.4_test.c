#define _CRT_SECURE_NO_WARNINGS 1

/*

二分法

1.寻找有序数组中的元素
2.有序二维数组查找
3.无序数组局部最小值查找
4.旋转数组查找

*/

//1.寻找有序数组中的元素
//#include<stdio.h>
//int main()
//{
//	int arr[] = { -1,2,4,5,7,8,9,11 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0, n;
//	int right = sz - 1;
//	scanf("%d", &n);
//	while (left<=right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid]>n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid]<n)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，该元素下标为%d\n", mid);
//			break;
//		}
//	}
//	if (left>right)
//	{
//		printf("无法找到该元素\n");
//	}
//	return 0;
//}

//2.二维数组查找
//#include<stdio.h>
//int main()
//{
//	int arr[4][4] =
//   { 2 ,3 ,4 ,5,
//	 6 ,7 ,8 ,9,
//	 10,11,12,13,
//	 14,15,16,17 };
//	int row = 0;
//	int col = 3, n;
//	scanf("%d", &n);
//	while (n != arr[row][col] && row>=0 && row<4 && col>=0 && col<4)
//	{
//		if (arr[row][col]>n)
//		{
//			col--;
//		}
//		else
//		{
//			row++;
//		}
//	}
//	if (n == arr[row][col])
//	{
//		printf("找到了，该元素下标为%d %d\n", row, col);
//	}
//	else
//	{
//		printf("无法找到该元素\n");
//	}
//	return 0;
//}

//无序数组中局部最小值查找
//二分法求一个无序数组中的任意一个局部最小值
//该数组中相邻两个元素都不相等
//#include<stdio.h>
//
//int Check(int sz, int arr[])
//{
//	int left = 0;
//	int right = sz - 1;
//	if (arr[left] < arr[left + 1])
//	{
//		return left;
//	}
//	else if (arr[right] < arr[right - 1])
//	{
//		return right;//判断两端
//	}
//	else//利用二分判断中间
//	{
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if ((arr[mid] < arr[mid - 1]) && (arr[mid] < arr[mid + 1]))
//			{
//				return mid;
//			}
//			else if (arr[mid] < arr[mid - 1] && arr[mid]>arr[mid+1])
//			{
//				left = mid + 1;
//			}
//			else//(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) || (arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
//			{
//				right = mid - 1;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,9,7,5,2,3,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = Check(sz, arr);
//	printf("该数组存在一个局部最小值，该元素下标为%d\n", ret);
//	return 0;
//}

//旋转数组的查找
//找出一个旋转数组中的最小元素

#include<stdio.h>
int main()
{
	int arr[] = { 5,6,1,2,3,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]>arr[right])//在左半部分
		{
			left = mid + 1;
		}
		else if (arr[mid]<arr[right])//在右半部分
		{
			right = mid;//不能mid-1,因为mid很可能是最小值
		}
		else
		{
			printf("该数组最小元素下标为%d\n", right);
			break;
		}
	}
	return 0;
}