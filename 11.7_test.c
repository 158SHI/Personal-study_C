#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//struct Stu
//{
//	int age;
//	char c1;
//	char c2;
//};
//
//int main()
//{
//	struct Stu s1 = { 0 };
//	printf("%d\n", sizeof(s1));
//	return 0;
//}

void bobble_sort(int* p, int sz)
{
	for (int i = 0; i < sz-1; i++)
	{
		for (int j = 0; j < sz-1-i; j++)
		{
			if (p[j]>p[j+1])
			{
				int tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 1,3,5,7,2,4,6,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bobble_sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}