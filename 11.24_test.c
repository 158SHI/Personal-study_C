#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

/*
��Ŀ��

����һ���������飬ʵ��һ��������

�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�

����ż��λ������ĺ�벿�֡�
*/

//void Reserve(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i]%2 != 0)//������
//		{
//			int key = arr[i];
//			int j = i - 1;
//			while (j >= 0 && arr[j] % 2 == 0)
//			{
//				arr[j + 1] = arr[j];
//				j--;
//			}
//			arr[j + 1] = key;
//		}
//	}
//}
//
//int main()
//{
//	int arr[100] = { 0 }; 
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for ( i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//���������ж�

//int main()
//{
//	Reserve(arr, n);
//
//	for ( i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//	int n = 0;
//	scanf("%d", &n);
//	int arr[100] = { 0 };
//	int cnt1 = 0, cnt2 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (arr[i] - arr[i + 1] > 0)
//		{
//			cnt1++;
//		}
//	}
//
//	for (int i = 0; i < n-1; i++)
//	{
//		if (arr[i]-arr[i+1]<0)
//		{
//			cnt2++;
//		}
//	}
//
//	if (cnt1==n-1 || cnt2==n-1)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		printf("0\n");
//	}
//	return 0;
//}

//int main()
//{
//int* p = (int*)malloc(5 * sizeof(int));
//	return 0;
//}