#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


void bubble_sort(int arr[], int sz)
{
	for (int i = 0; i < sz-1; i++)
	{
		for (int j = 0; j < sz-1-i; j++)
		{
			if (arr[j]>arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
//
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void select_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		int min = i;
//		for (int j = i+1; j < sz; j++)
//		{
//			if (arr[j]<arr[min])
//			{
//				min = j;	//min和arr[j]只是在数值上相等
//			}
//		}
//		swap(&arr[i], &arr[min]);
//	}
//}
//
void insert_sort(int arr[], int sz)
{
	for (int i = 1; i < sz; i++)
	{
		int j = i - 1;
		int key = arr[i];
		while (arr[j]>key && j>=0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
//
//int main()
//{
//	int arr[] = { 2,4,6,8,1,3,5,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);
//	//select_sort(arr, sz);
//	insert_sort(arr, sz);
//	return 0;
//}


//int main()
//{
//	int arr[2000] = { 0 };
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)//输入数组n
//	{
//		scanf("%d", &arr[i]);
//	}
//	int tmp = 0;
//	for (int j = n; j < m+n; j++)//逐个放入数组n
//	{
//		scanf("%d", &arr[j]);
//	}
//	bubble_sort(arr, m+n);//排序
//	for (int i = 0; i < m+n; i++)//输出
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*
输入一个整数序列，判断是否是有序序列，有序，指序列中的整数从小到大排序或者从大到小排序(相同元素也视为有序)。

数据范围： 3 \le n \le 50 \3≤n≤50  序列中的值都满足 1 \le val \le 100 \1≤val≤100
输入描述：
第一行输入一个整数N(3≤N≤50)。
第二行输入N个整数，用空格分隔N个整数。
输出描述：
输出为一行，如果序列有序输出sorted，否则输出unsorted。
*/
#include<stdbool.h>

//_Bool is_up(int arr[], int sz)
//{
//	_Bool flag = true;
//	for (int i = 0; i < sz-1; i++)
//	{
//		if (arr[i]>arr[i+1])
//		{
//			flag = false;
//			break;
//		}
//	}
//	return flag;
//}
//
//_Bool is_down(int arr[], int sz)
//{
//	_Bool flag = true;
//	for (int i = 0; i < sz - 1; i++)
//	{
//		if (arr[i] < arr[i + 1])
//		{
//			flag = false;
//			break;
//		}
//	}
//	return flag;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[50] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	_Bool ret1 = is_up(arr, n);
//	_Bool ret2 = is_down(arr, n);
//
//	if (ret1 || ret2)
//	{
//		printf("sorted\n");
//	}
//	else
//	{
//		printf("unsorted\n");
//	}
//	return 0;
//}

/*
有一个有序数字序列，从小到大排序，将一个新输入的数插入到序列中，保证插入新数后，序列仍然是升序。
输入描述：
第一行输入一个整数N(0≤N≤50)。

第二行输入N个升序排列的整数，输入用空格分隔的N个整数。

第三行输入想要进行插入的一个整数。
输出描述：
输出为一行，N+1个有序排列的整数。
*/

//void insert(int arr[], int sz, int key)
//{
//	while (arr[sz-2]>key && sz-2>=0)
//	{
//		arr[sz - 1] = arr[sz - 2];
//		sz--;
//	}
//	arr[sz - 1] = key;
//}
//
//int main()
//{
//	int arr[51] = { 0 };
//	int n = 0;
//	int m = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	scanf("%d", &arr[n]);
//	insert(arr, n + 1, arr[n]);
//	for (int i = 0; i < n+1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*
描述
有一个整数序列（可能有重复的整数），现删除指定的某一个整数，输出删除指定数字之后的序列，序列中未被删除数字的前后位置没有发生改变。

数据范围：序列长度和序列中的值都满足 1≤n≤50
输入描述：
第一行输入一个整数(0≤N≤50)。

第二行输入N个整数，输入用空格分隔的N个整数。

第三行输入想要进行删除的一个整数。

输出描述：
输出为一行，删除指定数字之后的序列。
*/

int main()
{
	int count = 0;
	int arr[50] = { 0 };
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int m = 0;
	scanf("%d", &m);

	int i = 0;
	while (i<n)
	{
		int j = i;
		if (arr[i]==m)
		{
			count++;
			while (j+1<=n)
			{
				arr[j] = arr[j + 1];
				j++;
			}
		}
		if (arr[i]!=m)
		{
			i++;
		}
	}

	for (int i = 0; i < n-count; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}