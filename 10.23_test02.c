#define _CRT_SECURE_NO_WARNINGS 1

//字符指针
//1.存放一个字符的地址
//2.存放一个字符串首元素的地址

#include<stdio.h>
//int main()
//{
//	char arr[20] = "Hello,world";
//	char* pc = &arr;
//	printf("%s\n", arr);//存放的是首元素的地址
//	printf("%s\n", pc);//以首元素的地址找到整个数组并打印
//
//	const char* p = "abcdef";//常量字符串
//	printf("%c\n", *p);
//	printf("%s\n", p);//将首字符的地址存到p中
//}

//#include<stdio.h>
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char* p1 = "abcdef";//常量字符串
//	char* p2 = "abcdef";
//	if (arr1==arr2)
//	{
//		printf("hehe\n");//不打印
//	}
//	if (p1==p2)//p1、p2指向同一个位置
//	{
//		printf("haha\n");//haha
//	}
//	return 0;
//}

//指针数组
//#include<stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2, 3, 4, 5, 6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };//用指针数组存放三个数组的首元素地址,以维护三个数组
//	int psz = sizeof(parr) / sizeof(parr[0]);
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0; i < psz; i++)//遍历三个数组的首元素地址
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));//遍历每个数组中的元素
//		}
//		printf("\n");
//	}
//	return 0;
//}

////数组指针
//#include<stdio.h>
//int main()
//{
//	//arr - 首元素地址
//	//&arr[0] - 首元素地址
//	//&arr - 数组的地址
//	
//	int arr[10] = {2,3,4,5,6};
//	int(*p)[10] = &arr;// [ ]的优先级较高，(*p)表示p是一个指针，指向一个长度为10的数组
//	
//	char* arr[5];//是一个存放char*类型元素的数组
//	char* (*parr) [5] = &arr;//*说明parr是指针，parr是指针变量名，[5]说明parr指向的数组长度是5，char*说明parr指向的数组元素类型是char*
//	return 0;
//}

//指针数组的使用

//数组的形式
void print1(int arr[3][5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//指针的形式
void print2(int(*p)[5], int row, int col)//二维数组传参时传的是第一行的地址
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *((*p + i) + j));
			//printf("%d ", ( * (p + i))[j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print1(arr,3,5);
	printf("--------------------------\n");
	print2(arr, 3, 5);
	return 0;
}