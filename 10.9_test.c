#define _CRT_SECURE_NO_WARNINGS 1

//��������
//#include<stdio.h>
//
//void Sort_sort(int arr[], int sz)
//{
//	for (int i = 1; i < sz; i++)
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
//	int arr[] = { 4,2,6,5,8,3,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Sort_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//ѡ������
//#include<stdio.h>
//
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void Select_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		int min = i;
//		for (int j = i+1; j < sz; j++)
//		{
//			if (arr[j]<arr[min])
//			{
//				min = j;//�����Сֵ
//			}
//		}
//		swap(&arr[min], &arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,2,6,5,8,3,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Select_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//ð������
#include<stdio.h>

void Borb_sort(int arr[], int sz)
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

int main()
{
	int arr[] = { 4,2,6,5,8,3,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Borb_sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}