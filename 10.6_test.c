#define _CRT_SECURE_NO_WARNINGS 1

//��������
//#include<stdio.h>
//
//void Sert_sorb(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
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
//	int arr[] = { 4,2,7,5,3,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Sert_sort(arr, sz);
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
//void selectionSort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		int min = i;//������СֵΪ��һ��Ԫ��
//		for (int j = i+1; j < sz; j++)
//		{
//			if (arr[j]<arr[min])
//			{
//				min = j;//���Һͱ��δ���򲿷��е���Сֵ
//			}
//		}
//		swap(&arr[min], &arr[i]);//����
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,2,7,5,3,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	selectionSort(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//ð������
//#include<stdio.h>
//
//void Borb_Sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)//ÿ�μ���������һ���Ѿ������Ԫ��
//	{
//		for (int j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,2,7,5,3,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Borb_Sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//Ħ��ͶƱ�㷨
//#include<stdio.h>
//
//int Moore(int arr[], int sz)
//{
//	int major;
//	int cnt = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (cnt == 0)
//		{
//			major = arr[i];
//		}//��cntΪ0�����major���¸�ֵ
//		if (arr[i] == major)
//		{
//			cnt++;
//		}
//		else
//		{
//			cnt--;
//		}
//	}
//	if (major == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		int count = 0;
//		for (int i = 0; i < sz; i++)
//		{
//			if (major == arr[i])
//			{
//				count++;
//			}
//		}
//		return count > sz / 2 ? major : 0;
//	}
//}
//
//int main()
//{
//	int arr[] = { 2,3,6,2,2,2,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = Moore(arr, sz);
//	printf("%d", ret);
//	return 0;
//}

//���������������1�ĸ���
//#include<stdio.h>
//int main(void)
//{
//	int n;
//	scanf("%d", &n);
//	int k = 1, count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (n & (k<<i))//1�������ƣ�����������
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}

/*
��A^B�������λ������ʾ������ ע��A^B��ʾA��B�η�
*/

//ѭ��
//#include<stdio.h>
//
//int POWER(int base, int power)
//{
//	int result = 1;
//	for (int i = 0; i < power; i++)
//	{
//		result = result * base;
//		result %= 1000;
//	}
//	return result % 1000;//(a * b * c) % p =( a%p * b%p * c%p ) % p
//} 
//
//int main()
//{
//	int base, power;
//	scanf("%d %d", &base, &power);
//	int ret = POWER(base, power);
//	printf("%d\n", ret);
//	return 0;
//}


//�������㷨
//#include<stdio.h>
//
//int POWER(int base, int power)
//{
//	long long result = 1;
//	while (power > 0)
//	{
//		if ((power & 1) == 0)// power % 2 == 0
//		{
//			//ָ��Ϊż��
//			power = power >> 1;// pow/2
//			base = base * base % 1000;
//		}
//		else
//		{
//			//ָ��Ϊ����
//			//power = power - 1;
//			result = result * base % 1000;//��¼��׼���õ���
//			power = power / 2;
//			base = base * base % 1000;
//		}
//	}
//	return result;
//}
//
//int main()
//{
//	int base;
//  long long power;
//	scanf("%d %d", &base, &power);
//	int ret = POWER(base, power);
//	printf("%d\n", ret);
//	return 0;
//}


/*

����һ��double���͵ĸ�����base��int���͵�����exponent��
��base��exponent�η�����֤base��exponent��ͬʱΪ0.

*/

//1.ѭ��.��

//2.�������㷨
#include<stdio.h>

double POWER(double base, int exp)
{
	int result = 1;
	if (base == 0)
	{
		return 0;
	}
	else if (exp == 0)
	{
		return 1;
	}
	else
	{
		while (exp > 0)
		{
			if ((exp & 1) == 0)
			{
				//exp��ż��
				exp = exp >> 1;
				base = base * base;
			}
			else
			{
				//exp������
				exp = exp - 1;
				result = result * base;
				exp = exp >> 1;
				base = base * base;
			}
		}
	}
	return result;
}

int main()
{
	double base;
	int exp;
	while (scanf("%lf %d", &base, &exp) != EOF)
	{
		double ret = POWER(base, exp);
		printf("%lf\n", ret);
	}
	return 0;
}