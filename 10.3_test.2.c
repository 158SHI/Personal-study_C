#define _CRT_SECURE_NO_WARNINGS 1


/*

��ת�������С����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
���磬���� [3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ1��

*/

//���ַ�
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 4,5,6,2,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0, right = sz - 1;
//	while (left < right)
//	{
//		int mid = left + (right - left) / 2; //�������
//		if (arr[mid] > arr[right])//����벿��
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] < arr[right])//���Ұ벿��
//		{
//			right = mid;//����mid-1����Ϊmid���п�������Сֵ
//		}
//		else//arr[mid]==arr[right]
//		{
//			right--;//����left++,��Ϊ���ܴ����Сֵ
//		}
//	}
//	printf("%d\n", arr[left]);
//	return 0;
//}

/*

��ά����Ĳ���

��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ����Ч�ĺ��������Ҫ����Ԫ�ص��±ꡣ

*/

//���ַ�
//#include<stdio.h>
//int main()
//{
//	int arr[4][4] = { 
//		1 ,2 ,3 ,4,
//		5 ,6 ,7 ,8,
//		9,10,11,12,
//	    13,14,15,16};
//	int row = 0;
//	int col = 3;
//	int n;
//	scanf("%d", &n);
//	while (arr[row][col] != n)
//	{
//		if (arr[row][col]>n)//�����Ͻ�Ԫ�ر�Ŀ��Ԫ�ش������Ԫ�ض���Ŀ��Ԫ�ش�
//		{
//			col--;
//		}
//		else//�����Ͻ�Ԫ�ر�Ŀ��Ԫ��С�������Ԫ�ض���Ŀ��Ԫ��С
//		{
//			row++;
//		}
//	}
//	printf("%d %d", row, col);
//	return 0;
//}


/*

��ά����Ĳ���

��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������

*/

//#include<stdio.h>
//
//int Judge(int arr[4][4], int row, int col, int n)
//{
//	while (row>=0 && row<4 && col>=0 && col<4)//�ж�row,col�ĺϷ��ԡ�����Ѱ�ҹ����б�Ϊ�Ƿ�����˵�������в���Ŀ��Ԫ��
//	{
//		if (arr[row][col] > n)
//		{
//			col--;
//		}
//		else if (arr[row][col] < n)
//		{
//			row++;
//		}
//		else//�ҵ���Ŀ��Ԫ�أ�˵�����и�Ԫ�أ����� 1
//		{
//			return 1;
//			break;
//		}
//	}
//	return 0;//Ϊ�ҵ���Ԫ�أ����� 0
//}
//
//int main()
//{
//	int arr[4][4] = {
//		1 ,2 ,3 ,4,
//		5 ,6 ,7 ,8,
//		9,10,11,12,
//		13,14,15,16 };
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int row = 0;
//		int col = 3;
//		int ret = Judge(arr, row, col, n);//�����ж�
//		if (ret == 1)
//		{
//			printf("true\n");
//		}
//		else
//		{
//			printf("false\n");
//		}
//	}
//	return 0;
//}


//���ַ���һ�����������е�����һ���ֲ���Сֵ_1
//����������������Ԫ�ض������
//#include<stdio.h>
//int main(void)
//{
//	int mid = 0;
//	int arr[] = { 2,1,3,5,3,8,6,9,6,12 };
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	if (arr[left] < arr[left + 1])
//	{
//		printf("�������к���һ���ֲ���Сֵ����ֵ�±�Ϊ%d", left);
//	}
//	else if (arr[right] < arr[right - 1])
//	{
//		printf("�������к���һ���ֲ���Сֵ����ֵ�±�Ϊ%d", right);
//	}
//	else
//	{
//		while (left<=right)
//		{
//			mid = (left + right) / 2;
//			if ((arr[mid]<arr[mid-1]) || (arr[mid]<arr[mid+1]))
//			{
//				printf("�������к���һ���ֲ���Сֵ����ֵ�±�Ϊ%d", mid);
//				break;
//			}
//			else
//			{
//				right = mid - 1;
//			}
//		}
//	}
//	return 0;
//}

//�����������_2
#include<stdio.h>

int Min(int arr[], int sz)
{
	int left = 0;
	int mid = 0;
	int right = sz - 1;
	if (arr[left] < arr[left + 1])
	{
		return left;
	}
	else if (arr[right] < arr[right - 1])
	{
		return right;
	}
	else
	{
		while (left <= right)
		{
			mid = (left + right) / 2;
			if ((arr[mid] < arr[mid - 1]) || (arr[mid] < arr[mid + 1]))
			{
				return mid;
				break;
			}
			else
			{
				right = mid - 1;
			}
		}
	}
}

int main(void)
{
	int arr[] = { 2,1,3,5,3,8,6,9,6,12 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = Min(arr, sz);
	printf("�������к���һ���ֲ���Сֵ����ֵ�±�Ϊ%d", ret);
	return 0;
}