#define _CRT_SECURE_NO_WARNINGS 1

//
////����
//#include<stdio.h>
//int main()
//{
//    char c1, c2, c3, c4, c5;
//    scanf("%c%c%c%c%c", &c1, &c2, &c3, &c4, &c5);
//    c1 = 'G';
//    c2 = 'l';
//    c3 = 'm';
//    c4 = 'r';
//    c5 = 'e';
//    printf("%c%c%c%c%c", c1, c2, c3, c4, c5);
//    return 0;
//}

/*

//�����ʽ

���������ɶ������ʵ����ɣ�ÿ������ʵ��ռһ�У�����һ������n(0<n<55)��n�ĺ�������Ŀ��������
n=0��ʾ�������ݵĽ�������������

//�����ʽ

����ÿ������ʵ��������ڵ�n���ʱ��ĸţ��������
ÿ�����ռһ�С�

//��������

2
4
5
0

//�������

2
4
6

*/


//�𰸴���
//#include<stdio.h>
//
//int Fib(int n)
//{
//	int a = 1, b = 1, c = 1;
//	if (n > 2)
//	{
//		while (n-2)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//			n--;
//		}
//	}
//	return c;
//}
//
//int cow(int n, int fib)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return fib + 1;
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		if (n == 0)
//		{
//			continue;
//		}
//		else
//		{
//			int fib = Fib(n);
//			int ret = cow(n, fib);
//			printf("%d\n", ret);
//		}
//	}
//	return 0;
//}

//�ݹ�
//#include<stdio.h>
//
//int cow(int n)
//{
//	if (n<=3)
//	{
//		return n;
//	}
//	else
//	{
//		return cow(n - 1) + cow(n - 3);
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)
//	{
//		if (n>0 && n<55)
//		{
//			printf("%d\n", cow(n));
//		}
//	}
//	return 0;
//}

/*

	��Ŀ����
����һ�������¶ȣ�Ҫ����������¶ȡ���ʽΪ c=5(F-32)/9��ȡλ2С����

	�����ʽ
һ�������¶ȣ�������

	�����ʽ
�����¶ȣ�������λС��

	��������
-40

	�������
c=-40.00

*/

//#include<stdio.h>
//int main()
//{
//	float F;
//	while (scanf("%f",&F) != EOF)
//	{
//		float c = 5.0 * (F - 32) / 9.0;
//		printf("%.2f\n", c);
//	}
//	return 0;
//}

/*
ˮ�ɻ���
*/

//#include<stdio.h>
//
//int Judge(int n)
//{
//	if (n<10)
//	{
//		return n * n * n;
//	}
//	else
//	{
//		return Judge(n / 10) + (n % 10) * (n % 10) * (n % 10);
//	}	
//}
//
//void flower()
//{
//	for (int i = 100; i <= 999; i++)
//	{
//		if (i == Judge(i))
//		{
//			printf("%d ", i);
//		}
//	}
//}
//
//int main()
//{
//	flower();
//	return 0;
//}

/*
		��Ŀ����
һ�������ǡ�õ��ڲ�������������������֮�ͣ�������ͳ�Ϊ"����"�� ���磬6������Ϊ1��2��3����6=1+2+3�����6��"����"�� ������ҳ�N֮�ڵ��������������������ʽ���������

		�����ʽ
			N

		�����ʽ
? its factors are ? ? ?

	��������
	1000	

	�������
6 its factors are 1 2 3
28 its factors are 1 2 4 7 14
496 its factors are 1 2 4 8 16 31 62 124 248
*/

//#include<stdio.h>
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int m = 1; m <= n; m++)
//		{
//			int s = 0;
//			int count = 0;
//			for (int i = 1; i < m - 1; i++)
//			{
//				if (m % i == 0)
//				{
//					s += i;
//					count++;
//				}
//			}
//			if (s == m)
//			{
//				printf("%d its factors are ", m);
//				for (int i = 1; i < m; i++)
//				{
//					if (m%i == 0)
//					{
//						printf("%d ", i);
//					}
//				}
//				printf("\n");
//			}
//		}
//	}
//	return 0;
//}


/*
��Ŀ 1018: [�������]�й��ɵ��������
ʱ������: 1Sec �ڴ�����: 128MB �ύ: 35150 ���: 24537
��Ŀ����
��һ�������У� 2/1 3/2 5/3 8/5 13/8 21/13...... ���������е�ǰN��֮�ͣ�������λС����
�����ʽ
N
�����ʽ
����ǰN���
��������
10
�������
16.48
*/


//���ǰn��쳲�������

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		int a = 1;
//		int b = 1;
//		int c = 1;
//		if (i > 2)
//		{
//			for (int j = 2; j < i; j++)
//			{
//				c = a + b;
//				a = b;
//				b = c;
//			}
//		}
//		printf("%d ", c);
//	}
//	return 0;
//}


//������
// 
//#include<stdio.h>
//int main()
//{
//	int n;
//	float sum = 0;//
//	scanf("%d", &n);
//	float arr1[100];
//	float arr2[100];
//	//��һ������
//	for (int i = 0; i < n; i++)
//	{
//		float a = 1;
//		float b = 1;
//		float c = 0;
//		for (int j = 0; j <= i; j++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		arr1[i] = c;//
//		//printf("%f ", c);//����
//	}
//	//printf("\n");//����
//	//�ڶ�������
//	for (int i = 0; i < n; i++)
//	{
//		float a = 1;
//		float b = 0;
//		float c = 0;
//		for (int j = 0; j <= i+1; j++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		arr2[i] = c;//
//		//printf("%f ", c);//����
//	}
//
//	//printf("%f", arr1[1] / arr2[1]);//����
//	for (int i = 0; i < n; i++)
//	{
//		sum += arr1[i]/arr2[i];
//	}
//	printf("%.2f\n", sum);
//	return 0;
//}

////�Ž�
//#include<stdio.h>
//int main()
//{
//
//	int N;
//	while (scanf("%d", &N) != EOF)
//	{
//		float sum = 0.0, t;
//		float m = 1.0;
//		float n = 2.0;
//
//		while (N)
//		{
//			sum = sum + n / m;
//			//�������ӷ�ĸ
//			t = m;
//			m = n;
//			n = t;
//
//			n += m;//���ӵ��ڷ�ĸ�ӷ���
//			N--;
//		}
//		printf("%.2f\n", sum);
//	}
//	return 0;
//}

/*
ѡ������
*/


//#include<stdio.h>
//
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void select_Sort(int arr[],int sz)
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
//	//��������
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	const int sz = 10;
//	select_Sort(arr,sz);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*
�Զ��庯���������������Լ������С������
*/

#include<stdio.h>

int gcd(int m, int n)
{
	if (m<n)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}//ȷ��m�зŵ��ǽϴ����
	int t = m % n;
	while (t != 0)
	{
		m = n;
		n = t;
		t = m % n;
	}
	return n;
}

int mcm(int m, int n)
{
	if (m<n)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}
	int i = m;
	while (i%m != 0 || i%n != 0)
	{
		i++;
	}
	return i;
}

int main()
{
	int m, n;
	while (scanf("%d%d",&m,&n) != EOF)
	{
		printf("%d %d\n", gcd(m, n), mcm(m, n));//���Լ��
	}
	return 0;
}