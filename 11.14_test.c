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
//				min = j;	//min��arr[j]ֻ������ֵ�����
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
//	for (int i = 0; i < n; i++)//��������n
//	{
//		scanf("%d", &arr[i]);
//	}
//	int tmp = 0;
//	for (int j = n; j < m+n; j++)//�����������n
//	{
//		scanf("%d", &arr[j]);
//	}
//	bubble_sort(arr, m+n);//����
//	for (int i = 0; i < m+n; i++)//���
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*
����һ���������У��ж��Ƿ����������У�����ָ�����е�������С����������ߴӴ�С����(��ͬԪ��Ҳ��Ϊ����)��

���ݷ�Χ�� 3 \le n \le 50 \3��n��50  �����е�ֵ������ 1 \le val \le 100 \1��val��100
����������
��һ������һ������N(3��N��50)��
�ڶ�������N���������ÿո�ָ�N��������
���������
���Ϊһ�У���������������sorted���������unsorted��
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
��һ�������������У���С�������򣬽�һ��������������뵽�����У���֤����������������Ȼ������
����������
��һ������һ������N(0��N��50)��

�ڶ�������N���������е������������ÿո�ָ���N��������

������������Ҫ���в����һ��������
���������
���Ϊһ�У�N+1���������е�������
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
����
��һ���������У��������ظ�������������ɾ��ָ����ĳһ�����������ɾ��ָ������֮������У�������δ��ɾ�����ֵ�ǰ��λ��û�з����ı䡣

���ݷ�Χ�����г��Ⱥ������е�ֵ������ 1��n��50
����������
��һ������һ������(0��N��50)��

�ڶ�������N�������������ÿո�ָ���N��������

������������Ҫ����ɾ����һ��������

���������
���Ϊһ�У�ɾ��ָ������֮������С�
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