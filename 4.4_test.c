#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //logN
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[i + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

int main()
{
	int arr[] = { 6,2,4,7,9,3,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	PrintArr(arr, sz);
	return 0;
}