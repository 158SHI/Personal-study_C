#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void PrintArr(int* parr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", parr[i]);
	}
	printf("\n");
}

void InsertSort(int* parr, int sz)
{
	for (int end = 0; end < sz - 1; end++)
	{
		int key = parr[end + 1];
		while (end >= 0)
		{
			if (key < parr[end])
			{
				parr[end + 1] = parr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		parr[end + 1] = key;
	}
}

void InsertSortTest(void)
{
	int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	PrintArr(arr, sz);
}

void ShellSort(int* parr, int sz)
{
	int grp = sz;
	while (grp > 1)
	{
		grp /= 2;
		for (int end = 0; end < sz - grp; end++)
		{
			int key = parr[end + grp];
			while (end >= 0)
			{
				if (key < parr[end])
				{
					parr[end + grp] = parr[end];
					end -= grp;
				}
				else
				{
					break;
				}
			}
			parr[end + grp] = key;
		}
	}
}

void ShellSortTest(void)
{
	int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	PrintArr(arr, sz);
}

int main()
{
	//InsertSortTest();
	ShellSortTest();
	return 0;
}