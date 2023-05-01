#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include <string.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int PartSort(int* a, int left, int right)
{
	int keyi = left;

	while (left < right)
	{
		while (left < right && a[right] >= a[keyi]) {
			right--;
		}
		while (left < right && a[left] <= a[keyi]) {
			left++;
		}
		Swap(a + left, a + right);
	}
	Swap(a + keyi, a + left);

	keyi = left;
	return keyi;
}

//三路划分 + 非递归
void QuickSort(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);

	if (begin < end) {
		StackPush(&st, end);
		StackPush(&st, begin);
	}
	
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int l = left;
		int r = right;
		int cur = left;
		while (cur <= r)
		{
			if (a[cur] < a[l])
			{
				Swap(a + cur, a + l);
				cur++;
				l++;
			}
			else if (a[cur] > a[l])
			{
				Swap(a + cur, a + r);
				r--;
			}
			else {
				cur++;
			}
		}
		//[left, l - 1] [l, r] [r + 1, right]

		if (left < l - 1)
		{
			StackPush(&st, l - 1);
			StackPush(&st, left);
		}
		if (r + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, r + 1);
		}
	}
}

void test1()
{
	int arr[] = { 6,3,2,5,6,7,9,6,0,6 };
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;
	//[left, mid] [mid + 1, right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else {
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1) {
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = a[begin2++];
	}

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(a, left, right, tmp);
	free(tmp);
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			
			if (end1 >= n || begin2 >= n) {
				break;
			}
			else if (end2 >= n) {
				end2 = n - 1;
			}


			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2]) {
					tmp[j++] = a[begin1++];
				}
				else {
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1) {
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2) {
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
}

void test2(void)
{
	int arr[] = { 6,3,2,5,6,7,9,6,0,6 };
	MergeSortNonR(arr, sizeof(arr) / sizeof(arr[0]));
}

int main()
{
	//test1();
	test2();
	return 0;
}