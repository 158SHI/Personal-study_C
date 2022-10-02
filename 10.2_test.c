#define _CRT_SECURE_NO_WARNINGS 1


//找出数组中重复的数字
//#include<stdio.h>
//int Check(int arr[15], int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = i + 1; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				return arr[i];
//				break;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	int arr[10] = { 0 };
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		int sz = sizeof(arr) / sizeof(arr[0]);
//		int ret = Check(arr, sz);
//		printf("%d\n", ret);
//	}
//	return 0;
//}


//找出一个数组中重复的数字并删去
#include<stdio.h>
int main() 
{
	int arr[] = { 1,2,3,4,2,1,3,2,5,5 };
	//int arr[] = { 1,1,2,2,3,3,4,4 };
	//int arr[] = { 1,2,2,2,2 };
	int sz = sizeof(arr) / sizeof(int);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	for (int i = 0; i < sz-1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (arr[i] == arr[j])
			{
				for (int k = j; k < sz-1; k++)
				{
					arr[k] = arr[k + 1];
				}
				j--;
				sz--;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}