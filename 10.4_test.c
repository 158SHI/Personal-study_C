#define _CRT_SECURE_NO_WARNINGS 1

/*

���ַ�

1.Ѱ�����������е�Ԫ��
2.�����ά�������
3.��������ֲ���Сֵ����
4.��ת�������

*/

//1.Ѱ�����������е�Ԫ��
//#include<stdio.h>
//int main()
//{
//	int arr[] = { -1,2,4,5,7,8,9,11 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0, n;
//	int right = sz - 1;
//	scanf("%d", &n);
//	while (left<=right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid]>n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid]<n)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ���Ԫ���±�Ϊ%d\n", mid);
//			break;
//		}
//	}
//	if (left>right)
//	{
//		printf("�޷��ҵ���Ԫ��\n");
//	}
//	return 0;
//}

//2.��ά�������
//#include<stdio.h>
//int main()
//{
//	int arr[4][4] =
//   { 2 ,3 ,4 ,5,
//	 6 ,7 ,8 ,9,
//	 10,11,12,13,
//	 14,15,16,17 };
//	int row = 0;
//	int col = 3, n;
//	scanf("%d", &n);
//	while (n != arr[row][col] && row>=0 && row<4 && col>=0 && col<4)
//	{
//		if (arr[row][col]>n)
//		{
//			col--;
//		}
//		else
//		{
//			row++;
//		}
//	}
//	if (n == arr[row][col])
//	{
//		printf("�ҵ��ˣ���Ԫ���±�Ϊ%d %d\n", row, col);
//	}
//	else
//	{
//		printf("�޷��ҵ���Ԫ��\n");
//	}
//	return 0;
//}

//���������оֲ���Сֵ����
//���ַ���һ�����������е�����һ���ֲ���Сֵ
//����������������Ԫ�ض������
//#include<stdio.h>
//
//int Check(int sz, int arr[])
//{
//	int left = 0;
//	int right = sz - 1;
//	if (arr[left] < arr[left + 1])
//	{
//		return left;
//	}
//	else if (arr[right] < arr[right - 1])
//	{
//		return right;//�ж�����
//	}
//	else//���ö����ж��м�
//	{
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if ((arr[mid] < arr[mid - 1]) && (arr[mid] < arr[mid + 1]))
//			{
//				return mid;
//			}
//			else if (arr[mid] < arr[mid - 1] && arr[mid]>arr[mid+1])
//			{
//				left = mid + 1;
//			}
//			else//(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) || (arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
//			{
//				right = mid - 1;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,9,7,5,2,3,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = Check(sz, arr);
//	printf("���������һ���ֲ���Сֵ����Ԫ���±�Ϊ%d\n", ret);
//	return 0;
//}

//��ת����Ĳ���
//�ҳ�һ����ת�����е���СԪ��

#include<stdio.h>
int main()
{
	int arr[] = { 5,6,1,2,3,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]>arr[right])//����벿��
		{
			left = mid + 1;
		}
		else if (arr[mid]<arr[right])//���Ұ벿��
		{
			right = mid;//����mid-1,��Ϊmid�ܿ�������Сֵ
		}
		else
		{
			printf("��������СԪ���±�Ϊ%d\n", right);
			break;
		}
	}
	return 0;
}