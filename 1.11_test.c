#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//int main()
//{
//	int a = 122140;
//	char arr[10] = { 0 };
//	sprintf(arr, "%d", a);
//	int tmp = arr[2] - '0' + (arr[1] - '0') * 10;
//	int len = strlen(arr);
//	return 0;
//}

int Max(int* nums, int size)
{
	if (size == 1)
	{
		return nums[0];
	}
	else if (size == 2)
	{
		return nums[0] > nums[1] ? nums[0] : nums[1];
	}
	else
	{
		int k1 = Max(nums, size - 2) + nums[size - 1];
		int k2 = Max(nums, size - 1);
		return k1 > k2 ? k1 : k2;
	}
}

//int main()
//{
//	int arr[] = { 2, 7, 9, 3, 1 };
//	int ret = Max(arr, 5);
//	return 0;
//}

void test01(void)
{
	int a = 10;
	int* pa = &a;//pa是一个一级指针
	int** ppa = &pa;//ppa是一个二级指针
	**ppa = 20;//通过二级指针操作数据
}

void test02(void)
{
	int a = 10;
	int* pa = &a;
}

void test03(void)
{
	const char* p = "hello world!";
}

int Add(int x, int y)
{
	int sum = x + y;
	return sum;
}

void test04(void)
{
	int a = 10;
	int b = 20;
	int ret = Add(a, b);
}

#include<assert.h>

size_t my_strlen(const char* p)
{
	assert(p);
	const char* end = p;
	while (*end++);
	return end - p - 1;
}

void test05(void)
{
	char arr[10] = "ada";
	printf("%zd\n", my_strlen(arr));
}

//int main()
//{
//	//test01();
//	//test02();
//	//test03();
//	//test04();
//	test05();
//	return 0;
//}

#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}

//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	int(*p[5])(int x, int y) = { 0, add, sub, mul, div };//转移表
//	while (input)
//	{
//		printf("*************************\n");
//		printf(" 1:add 2:sub \n");
//		printf(" 3:mul 4:div \n");
//		printf("*************************\n");
//		printf("请选择：");
//		scanf("%d", &input);
//		if ((input <= 4 && input >= 1))
//		{
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = (*p[input])(x, y);
//		}
//		else
//		{
//			printf("输入有误\n");
//		}
//		printf("ret = %d\n", ret);
//	}
//}

//void Func(int arr[ROW][COL], int row, int col)
//{
//	;
//}
//
//void Func(int(*parr)[COL], int row, int col)
//{
//	;
//}
//
//int main()
//{
//	int arr[3][3] = { 0 };
//	Func(arr, 3, 3);
//	return 0;
//}