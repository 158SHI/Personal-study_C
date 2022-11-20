#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<math.h>
/*
作业内容
写一个函数打印arr数组的内容，不使用数组下标，使用指针。

arr是一个整形一维数组。
*/

//void Print(int* parr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(parr + i));
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,5,8,13,21 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, sz);
//	return 0;
//}

/*
写一个函数，可以逆序一个字符串的内容。
*/

void Reserve(char* parr)
{
	int len = strlen(parr);
	int left = 0;
	int right = len - 1;
	while (left<right)
	{
		char tmp = *(parr + left);
		*(parr + left) = *(parr + right);
		*(parr + right) = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[10000] = { 0 };
	//scanf("%s", arr);//注：用scanf输入空格会视为多组输入！！！
	gets(arr);

	Reserve(arr);
	printf("%s\n", arr);
	return 0;
}

//打印菱形

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0, j = 0;
//
//	for ( i = 0; i < n; i++)//打印上半部分
//	{
//		for ( j = n; j > i; j--)
//		{
//			printf(" ");
//		}
//		for ( j = 0; j < i; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//
//	for (i = n; i >0; i--)//打印下半部分
//	{
//		for (j = i; j < n; j++)
//		{
//			printf(" ");
//		}
//		for (j = i; j > 0; j--)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

/*

求出0～100000之间的所有“水仙花数”并输出。

“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。
*/
#include<stdbool.h>

//int JudgeTheNumber(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n /= 10;
//		count++;
//	}
//	return count;
//}
//
//_Bool JudgeFlower(int n)
//{
//	int count = JudgeTheNumber(n);
//	int tmp = 0;
//	int sum = 0;
//	int flag = n;
//	while (flag)
//	{
//		tmp = flag%10;
//		sum += (int)pow(tmp, count);
//		flag /= 10;
//	}
//
//	if (sum == n)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	for (int i = 0; i < 100000; i++)
//	{
//		_Bool ret = JudgeFlower(i);
//		if (ret)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

/*
作业内容
求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，

例如：2+22+222+2222+22222
*/

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//
//	int sum = 0;
//	int tmp = a;
//	for (int i = 0; i < 5; i++)
//	{
//		sum += tmp;
//		tmp = tmp * 10 + a;
//	}
//
//	printf("%d\n", sum);
//	return 0;
//}