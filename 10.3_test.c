#define _CRT_SECURE_NO_WARNINGS 1

//��1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�
//#include<stdio.h>
//int main()
//{
//	int x, y, z;
//	int count = 0;
//	for ( x = 1; x < 5; x++)
//	{
//		for ( y = 1; y < 5; y++)
//		{
//			for ( z = 1; z < 5; z++)
//			{
//				if (x!=y && y!=z && x!=z)
//				{
//					int num = x * 100 + y * 10 + z;
//					printf("%d ", num);
//					count++;
//				}
//			}
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}//��ٷ�


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

//���n��쳲�������
#include<stdio.h>

//�ݹ�
//int Fib(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//�ǵݹ�

//#include<stdio.h>
//int main()
//{
//	int a = 1, b = 0, c = 0, n;
//	scanf("%d", &n);
//	for (int i = 0 ; i < n ; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	printf("%d\n", c);
//	return 0;
//}

//������̨��
//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 1, c = 0;
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	printf("%d", c);
//	return 0;
//}


/*

��ת�������С����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
���磬���� [3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ1��

*/

//���ַ�
#include<stdio.h>
int main()
{
	int arr[] = { 4,5,6,2,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0, right = sz - 1;
	while (left<right)
	{
		int mid = left + (right - left) / 2; //�������
		if (arr[mid]>arr[right])//����벿��
		{
			left = mid + 1;
		}
		else if (arr[mid]<arr[right])//���Ұ벿��
		{
			right = mid;//����mid-1����Ϊmid���п�������Сֵ
		}
		else//arr[mid]==arr[right]
		{
			right--;//����left++,��Ϊ���ܴ����Сֵ
		}
	}
	printf("%d\n", arr[left]);
	return 0;
}