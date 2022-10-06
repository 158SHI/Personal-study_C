#define _CRT_SECURE_NO_WARNINGS 1

//插入排序
//#include<stdio.h>
//
//void Sert_sorb(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
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
//	int arr[] = { 4,2,7,5,3,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Sert_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//选择排序
//#include<stdio.h>
//
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void selectionSort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		int min = i;//假设最小值为第一个元素
//		for (int j = i+1; j < sz; j++)
//		{
//			if (arr[j]<arr[min])
//			{
//				min = j;//查找和标记未排序部分中的最小值
//			}
//		}
//		swap(&arr[min], &arr[i]);//交换
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,2,7,5,3,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	selectionSort(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//冒泡排序
//#include<stdio.h>
//
//void Borb_Sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)//每次检索都产生一个已经有序的元素
//	{
//		for (int j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,2,7,5,3,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Borb_Sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//摩尔投票算法
//#include<stdio.h>
//
//int Moore(int arr[], int sz)
//{
//	int major;
//	int cnt = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (cnt == 0)
//		{
//			major = arr[i];
//		}//若cnt为0，则给major重新赋值
//		if (arr[i] == major)
//		{
//			cnt++;
//		}
//		else
//		{
//			cnt--;
//		}
//	}
//	if (major == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		int count = 0;
//		for (int i = 0; i < sz; i++)
//		{
//			if (major == arr[i])
//			{
//				count++;
//			}
//		}
//		return count > sz / 2 ? major : 0;
//	}
//}
//
//int main()
//{
//	int arr[] = { 2,3,6,2,2,2,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = Moore(arr, sz);
//	printf("%d", ret);
//	return 0;
//}

//求二进制数补码中1的个数
//#include<stdio.h>
//int main(void)
//{
//	int n;
//	scanf("%d", &n);
//	int k = 1, count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (n & (k<<i))//1不断左移，进行与运算
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}

/*
求A^B的最后三位数所表示的整数 注：A^B表示A的B次方
*/

//循环
//#include<stdio.h>
//
//int POWER(int base, int power)
//{
//	int result = 1;
//	for (int i = 0; i < power; i++)
//	{
//		result = result * base;
//		result %= 1000;
//	}
//	return result % 1000;//(a * b * c) % p =( a%p * b%p * c%p ) % p
//} 
//
//int main()
//{
//	int base, power;
//	scanf("%d %d", &base, &power);
//	int ret = POWER(base, power);
//	printf("%d\n", ret);
//	return 0;
//}


//快速幂算法
//#include<stdio.h>
//
//int POWER(int base, int power)
//{
//	long long result = 1;
//	while (power > 0)
//	{
//		if ((power & 1) == 0)// power % 2 == 0
//		{
//			//指数为偶数
//			power = power >> 1;// pow/2
//			base = base * base % 1000;
//		}
//		else
//		{
//			//指数为奇数
//			//power = power - 1;
//			result = result * base % 1000;//记录并准备好底数
//			power = power / 2;
//			base = base * base % 1000;
//		}
//	}
//	return result;
//}
//
//int main()
//{
//	int base;
//  long long power;
//	scanf("%d %d", &base, &power);
//	int ret = POWER(base, power);
//	printf("%d\n", ret);
//	return 0;
//}


/*

给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。保证base和exponent不同时为0.

*/

//1.循环.略

//2.快速幂算法
#include<stdio.h>

double POWER(double base, int exp)
{
	int result = 1;
	if (base == 0)
	{
		return 0;
	}
	else if (exp == 0)
	{
		return 1;
	}
	else
	{
		while (exp > 0)
		{
			if ((exp & 1) == 0)
			{
				//exp是偶数
				exp = exp >> 1;
				base = base * base;
			}
			else
			{
				//exp是奇数
				exp = exp - 1;
				result = result * base;
				exp = exp >> 1;
				base = base * base;
			}
		}
	}
	return result;
}

int main()
{
	double base;
	int exp;
	while (scanf("%lf %d", &base, &exp) != EOF)
	{
		double ret = POWER(base, exp);
		printf("%lf\n", ret);
	}
	return 0;
}