#define _CRT_SECURE_NO_WARNINGS 1

//冒泡排序
//#include<stdio.h>
//
//Bobble(int arr[10], int sz)
//{
//	int i, j, tmp = 0;
//	for ( i = 0; i < sz-1; i++)//i的引入：不断舍去末端已确定的数
//	{
//		for ( j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//
//}
//
//int main(void)
//{
//	int arr[10] = { 2,4,8,5,2,0,-1,4,7,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bobble(arr, sz);//冒泡排序
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}

//数组操作
//#include<stdio.h>
//
//void Init(int arr[10], int sz)
//{
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		arr[i] = i;
//	}
//}
//
//void Print(int arr[10], int sz)
//{
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Reverse(int arr[10], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left<right)
//	{
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main(void)
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Init(arr, sz);//初始化
//	Print(arr, sz);//打印
//	Reverse(arr, sz);//反置
//	Print(arr, sz);//打印
//	return 0;
//}

//交换两个元素个数相同的数组中的元素
//#include<stdio.h>
//int main(void)
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,0 };
//	int i, tmp = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for ( i = 0; i < sz; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	return 0;
//}

//有符号数->无符号数
//#include<stdio.h>
//int i;//全局变量不初始化默认为0
//int main(void)
//{
//	i--;
//	if (i<sizeof(i))
//	{
//		printf("<\n");
//	}
//	else
//	{
//		printf(">\n");
//	}
//	return 0;
//}

//操作符的优先级
//#include<stdio.h>
//int main(void)
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;
//	b = ++c, c++, ++a, a++;// = 的优先级比 ，高
//	b += a++ + c;
//	printf("a=%d b=%d c=%d\n", a, b, c);
//	return 0;
//}

//求两个数二进制中不同位的个数
#include<stdio.h>

int Check(int a, int b)
{
	int c = a ^ b;//标记数字不同的位数
	int i, count = 0;
	for ( i = 0; i < 32; i++)//计算上述位数的个数
	{
		if ((c>>i) & 1 == 1)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int a = 3;
	int b = 5;
	int ret = Check(a, b);
	printf("ret=%d\n", ret);
	return 0;
}