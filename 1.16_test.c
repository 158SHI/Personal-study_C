#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Swap(int* buf1, int* buf2)
{
	int tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
}

void AdjustDown(int* a, int k, int root)
{
	//建大堆
	int parent = root;
	int child = parent * 2 + 1; // 默认是左子节点
	while (child < k)
	{
		if (/*有右孩子*/child + 1 < k && a[child + 1] > a[child])
		{
			child += 1;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void test1(void)
{
	int arr[] = { -1, 5, 4, 7, 2, 1, 3 };//k == 2
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	//前k个数建堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, k, i);
	}
	for (int i = k; i < sz; i++)
	{
		if (arr[i] < arr[0])
		{
			arr[0] = arr[i];
			AdjustDown(arr, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
}

#include<stdbool.h>

int sumNums(int n)
{
	//if (n == 1)
	//{
	//	return 1;
	//}
	//else
	//{
	//	return n + sumNums(n - 1);
	//}
	int sum = 0;
	bool flag = (n > 0) && (sum = sumNums(n - 1) + n);
	return sum;
}

void test2(void)
{
	int n = 5;
	int ret = sumNums(5);
}

int main()
{
	//test1();
	test2();
	return 0;
}