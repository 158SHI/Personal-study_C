#define _CRT_SECURE_NO_WARNINGS 1

//ˮ�ɻ���
#include<stdio.h>

//int Judge(int n)
//{
//	int g = n % 10;
//	int s = n / 10 % 10;
//	int b = n / 100;
//	if (g*g*g+s*s*s+b*b*b == n)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	for (int i = 100; i < 1000; i++)
//	{
//		if (Judge(i))
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

/*
��̼���a+aa+aaa+aaaa+a��a(n��a��ֵ֮��a,n�ɼ�������

����  2+22+222+2222+22222����ʱa=2,n=5��

�������� 2 3

������� 246
*/

//int operation(int a, int n)
//{
//	int sum = a;
//	int tmp = a;
//	for (int i = 1; i < n; i++)
//	{
//		a = 10 * a + tmp;
//		sum += a;
//	}
//	return sum;
//}
//
//int main()
//{
//	int a, n;
//	scanf("%d %d", &a, &n);
//	int ret = operation(a, n);
//	printf("%d\n", ret);
//	return 0;
//}

/*
��һ�������У�2/1��3/2��5/3��8/5��13/8��21/13...���������е�ǰ20��֮�͡�

�������  32.66�����������λС����
*/

//int main()
//{
//	double a = 2.0;
//	double b = 1.0;
//	double sum = 0.0;
//	double tmp = 0.0;
//	for (int i = 0; i < 20; i++)
//	{
//		sum += a / b;
//		tmp = a;
//		a = a + b;
//		b = tmp;
//	}
//	printf("%.2f\n", sum);
//	return 0;
//}

/*
������������Ȼ���ĳ˻���1����������Ƹ������Ǻ�г���������磬2*3-1=5��5�Ǻ�г�������Ӽ�������n����[2��n)���������к�г����֮�͡�

ע�⣺

��1��������Ϊint�͡�

��2������n��ֵΪ5ʱ��[2��5)����ĺ�г������2��3-1=5��3��4-1=11��4��5-1=19����г����֮����5+11+19=35��

����������5

���������35

����������50

���������21066
*/
//#include<math.h>
//
//int prime(int x, int y)
//{
//	int tmp = x * y - 1;
//	int i = 0;
//	for (i = 2; i <=sqrt(tmp); i++)
//	{
//		if (tmp%i == 0)
//		{
//			return 0;
//		}
//	}
//	if (i>sqrt(tmp))
//	{
//		return tmp;
//	}
//}
//
//int operation(int n)
//{
//	int sum = 0;
//	int arr[100] = { 0 };
//	for (int i = 2; i <= n; i++)
//	{
//		arr[i - 2] = i;
//	}
//	int sz = n - 1;
//	for (int i = 0; i <= sz-2; i++)
//	{
//		int ret = prime(arr[i], arr[i + 1]);
//		if (ret)
//		{
//			sum += ret;
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = operation(n);
//	printf("%d\n", ret);
//	return 0;
//}

/*
��������������m,n���������Լ������С��������

����������12 8

������� �����Լ��=4,��С������=24
*/

//int Ma(int m, int n)
//{
//	while (m % n != 0)
//	{
//		int tmp = m % n;
//		m = n;
//		n = tmp;
//	}
//	return n;
//}
//
//int Mi(int m, int n)
//{
//	if (m<n)
//	{
//		int tmp = m;
//		m = n;
//		n = tmp;
//	}
//	for (int i = m; ; i++)
//	{
//		if (i%m == 0 && i%n == 0)
//		{
//			return i;
//		}
//	}
//}
//
//int main()
//{
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int A = Ma(m, n);
//	int I = Mi(m, n);
//	printf("���Լ��=%d,��С������=%d\n", A, I);
//	return 0;
//}

//�������жϲ����Ż�
int judge_row(int arr[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		int flag = 1;
		for (int j = 0; j < col-1; j++)
		{
			if (arr[i][j] != arr[i][j + 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			return 1;
		}
	}
	return 0;
}

int judge_col(int arr[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		int flag = 1;
		for (int j = 0; j < col - 1; j++)
		{
			if (arr[j][i] != arr[j+1][i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	//int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	//int arr[3][3] = { 0 };
	//int arr[3][3] = { 1,1,1,2,2,2,3,3,3 };
	//int arr[3][3] = { 1,2,3,1,2,3,1,2,3 };
	int arr[3][3] = { 1,2,3,1,1,1,4,5,6 };


	int ret = judge_row(arr, 3, 3);
	int ret2 = judge_col(arr, 3, 3);
	printf("ret=%d\n", ret);
	printf("ret2=%d\n", ret2);
	return 0;
}