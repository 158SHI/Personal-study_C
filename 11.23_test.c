#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

//小乐乐喜欢数字，尤其喜欢0和1。
//他现在得到了一个数，想把每位的数变成0或1。
//如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。请你回答他最后得到的数是多少。

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int tmp = 0;
//    int ret = 0;
//    int i = 0;
//
//    while (n)
//    {
//        tmp = n % 10;
//        if (tmp % 2 == 0)
//        {
//            tmp = 0;
//        }
//        else
//        {
//            tmp = 1;
//        }
//        ret += tmp * (int)pow(10, i++);//
//        n /= 10;
//    }
//
//    printf("%d\n", ret);
//    return 0;
//}

/*
描述
老师给了小乐乐一个正整数序列，要求小乐乐把这个序列去重后按从小到大排序。但是老师给出的序列太长了，小乐乐没办法耐心的去重并排序，请你帮助他。

输入描述：
第一行包含一个正整数n，表示老师给出的序列有n个数。接下来有n行，每行一个正整数k，为序列中每一个元素的值。(1 ≤ n ≤ 105，1 ≤ k ≤ n)

输出描述：
输出一行，为去重排序后的序列，每个数后面有一个空格。
*/

//int cmp_int(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//
//_Bool JudgeAndInsert(int* arr, int input,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left<right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid]<input)
//		{
//
//		}
//	}
//}
//
//int main()
//{
//	//1.去重
//	//2.排序
//	int n = 0;
//	scanf("%d", &n);
//	int arr[100] = { 0 };
//
//	int i = 0;
//	int j = 0;
//	int size = 0;
//	for (i = 0; i < n; i++)
//	{
//
//		int input = 0;
//		scanf("%d", &input);
//		_Bool ret = JudgeAndInsert(arr, input,size);
//		if (ret)
//		{
//			arr[size++] = input;
//		}
//	}
//
//	//排序
//	qsort(arr, size, sizeof(int), cmp_int);
//
//	for ( i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//该方法只适用于正数
//int main()
//{
//    int n = 0;
//    int arr[100000] = { 0 };
//    scanf("%d", &n);
//    int i = 0;
//    int tmp = 0;
//    for (i = 1; i <= n; i++)
//    {
//        scanf("%d", &tmp);
//        arr[tmp] = tmp;//输入的数越大，数组下标越大；输入的数有重复时，覆盖掉重复的数
//    }
//
//    for (i = 0; i < n; i++)
//    {
//        if (arr[i] != 0)
//        {
//            printf("%d ", arr[i]);
//        }
//    }
//
//    return 0;
//}

/*
输入描述：
输入只包含大写字母的字符串s。(1 ≤ length ≤ 8000)
输出描述：
输出一个整数，为字符串s中子序列“CHN”的数量。
*/

//待改进
//int main()
//{
//	char arr[8001] = { 0 };
//	gets(arr);
//	int i = 0, j = 0;
//	int len = strlen(arr);
//	int count = 0;
//	for ( i = 0; i < len; i++)
//	{
//		if (arr[i]=='C')
//		{
//			int key_c = i;
//			for ( j = key_c+1; j < len-1; j++)
//			{
//				if (arr[j]=='H')
//				{
//					int key_h = j;
//					for (int k = key_h+1; k < len; k++)
//					{
//						if (arr[k]=='N')
//						{
//							count++;
//						}
//					}
//				}
//			}
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//int main()
//{
//	int n = 5;
//	int i = 0, j = 0;
//
//	for (i = 0; i < n; i++)//打印上半部分
//	{
//		for (j = n; j > i+1; j--)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//
//	for (i = n; i > 1; i--)//打印下半部分
//	{
//		for (j = i-1; j < n; j++)
//		{
//			printf(" ");
//		}
//		for (j = i; j > 1; j--)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//

int main()
{
	int line = 0;
	scanf("%d", &line);
	//打印上半部分
	int i = 0;
	int j = 0;
	for (i = 0; i < line; i++)//打印line行
	{
		//打印空格
		for (j = 0; j < line-1-i; j++)
		{
			printf(" ");
		}
		for ( j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for ( i = 0; i < line-1; i++)//打印line-1行
	{
		for ( j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for ( j = 0; j < 2*(line-1-i)-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 1;
//	int sum = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//
//	printf("%d\n", sum);
//	return 0;
//}