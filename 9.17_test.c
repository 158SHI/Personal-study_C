#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//void insertion_sort(int arr[], int len) 
//{
//    int i, j, key;
//    for (i = 1; i < len; i++) //����һ��Ԫ����Ϊ��������
//    {
//        key = arr[i];
//        j = i - 1;
//        while ((j >= 0) && (arr[j] > key)) 
//        {
//            arr[j+1] = arr[j];
//            j--;
//        }//�����������е�Ԫ�ؽ��бȽ�ȷ������λ��
//        arr[j + 1] = key;
//    }
//}
//
//int main()
//{
//	int arr[] = { 4,2,5,3,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//    insertion_sort(arr, len);//��������
//
//    int i = 0;
//    for ( i = 0; i < len; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//	return 0;
//}

//��������
//#include<stdio.h>
//
//void insertion_sort(int arr[], int sz)
//{
//	int i, j, key;
//	for ( i = 1; i < sz; i++)
//	{
//		j = i - 1;
//		key = arr[i];
//		while (j >= 0 && arr[j]>key)
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
//	int arr[] = { 4,2,5,3,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	insertion_sort(arr, sz);
//	int i = 0;
//	for ( i = 0; i < sz; i++)
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
//void chose_sort(int arr[], int sz)
//{
//	int i, j;
//	for ( i = 0; i < sz-1; i++)
//	{
//		for ( j = i+1; j < sz; j++)
//		{
//			if (arr[j] < arr[i])
//			{
//				swap(&arr[i], &arr[j]);
//				break;
//			}
//		}
//	}
//
//}
//
//int main()
//{
//	int arr[] = { 4,2,5,3,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	chose_sort(arr, sz);
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//ð������
#include<stdio.h>

void bob_sort(int arr[], int sz)
{
	int i, j, tmp;
	for ( i = 0; i < sz-1; i++)
	{
		for ( j = 0; j < sz-1-i; j++)
		{
			if (arr[j]>arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 4,2,5,3,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bob_sort(arr, sz);
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}