#define _CRT_SECURE_NO_WARNINGS 1

//��ƺ������ض�������1�ĸ���
//#include<stdio.h>
//
//int Check(int num)
//{
//	int i, count = 0;
//	//for ( i = 0; i < 32; i++)
//	//{
//	//	if ((num >> i) & 1 == 1)
//	//	{
//	//		count++;
//	//	}
//	//}
//	while (num)
//	{
//		count++;
//		num = num & (num - 1);
//	}
//	return count;
//}
//
//int main()
//{
//	int a = 7;//0111
//	int ret = Check(a);
//	printf("ret=%d\n", ret);
//	return 0;
//}

//��ȡһ�������������е�ż��λ������λ�����ֱ��ӡ����
//#include<stdio.h>

//void Print(int n)
//{
//	int i = 0;
//	printf("ż��λ:");
//	for ( i = 31; i >= 1; i-=2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n����λ:");
//	for ( i = 30; i >= 0; i-=2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	printf("������n=");
//	scanf("%d", &n);
//	Print(n);
//}

//��ʹ���±꣬��ӡ�����е�ÿ��Ԫ��
//#include<stdio.h>
//
//void Print(int* p, int sz)
//{
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, sz);
//	return 0;
//}

/*
��ӡ��100��200֮�������
�Գ���
#include<stdio.h>

int Judge(int n)
{
	int i = 0;
	for ( i = 2; i <= n/2; i++)
	{
		if (n%i == 0)
		{
			break;
		}
	}
	if (n%i != 0)
	{
		return 1;
	}
}

void Print()
{
	int j = 0;
	int count = 0;
	for (j = 101; j <= 199; j += 2)
	{
		if (Judge(j) == 1)
		{
			printf("%d ", j);
			count++;
		}
	}
	printf("\ncount=%d\n", count);
}

int main()
{
	Print();
	return 0;
}*/

//��ƺ������Գ������100��200֮�������
//#include<stdio.h>
//#include<math.h>
//
//void Print()
//{
//	int i, j = 0;
//	int count = 0;
//	for (i = 101; i < 200; i += 2)//ż��������������
//	{
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)//��������
//			{
//				break;
//			}
//		}
//		if (j > sqrt(i))//ɸ������
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d\n", count);
//}
//
//int main()
//{
//	Print();//��ӡ����
//	return 0;
//}

//��ƺ�������ӡ�˷��ھ�������������������
#include<stdio.h>

void Print()
{
	int n = 0;
	printf("������n=");
	scanf("%d", &n);
	int i, j = 0;
	for ( i = 1; i <=n; i++)
	{
		for ( j = 1; j <= i; j++)
		{
			printf("%d*%d=%-3d ", i, j, i * j);
		}
		printf("\n");
	}
}

int main()
{
	Print();
	return 0;
}