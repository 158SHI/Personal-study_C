#define _CRT_SECURE_NO_WARNINGS 1

//
////加密
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

//输入格式

输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
n=0表示输入数据的结束，不做处理。

//输出格式

对于每个测试实例，输出在第n年的时候母牛的数量。
每个输出占一行。

//样例输入

2
4
5
0

//样例输出

2
4
6

*/


//答案错误
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

//递归
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

	题目描述
输入一个华氏温度，要求输出摄氏温度。公式为 c=5(F-32)/9，取位2小数。

	输入格式
一个华氏温度，浮点数

	输出格式
摄氏温度，浮点两位小数

	样例输入
-40

	样例输出
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
水仙花数
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
		题目描述
一个数如果恰好等于不包含它本身所有因子之和，这个数就称为"完数"。 例如，6的因子为1、2、3，而6=1+2+3，因此6是"完数"。 编程序找出N之内的所有完数，并按下面格式输出其因子

		输入格式
			N

		输出格式
? its factors are ? ? ?

	样例输入
	1000	

	样例输出
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
题目 1018: [编程入门]有规律的数列求和
时间限制: 1Sec 内存限制: 128MB 提交: 35150 解决: 24537
题目描述
有一分数序列： 2/1 3/2 5/3 8/5 13/8 21/13...... 求出这个数列的前N项之和，保留两位小数。
输入格式
N
输出格式
数列前N项和
样例输入
10
样例输出
16.48
*/


//输出前n个斐波那契数

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


//不够优
// 
//#include<stdio.h>
//int main()
//{
//	int n;
//	float sum = 0;//
//	scanf("%d", &n);
//	float arr1[100];
//	float arr2[100];
//	//第一个数组
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
//		//printf("%f ", c);//测试
//	}
//	//printf("\n");//测试
//	//第二个数组
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
//		//printf("%f ", c);//测试
//	}
//
//	//printf("%f", arr1[1] / arr2[1]);//测试
//	for (int i = 0; i < n; i++)
//	{
//		sum += arr1[i]/arr2[i];
//	}
//	printf("%.2f\n", sum);
//	return 0;
//}

////优解
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
//			//交换分子分母
//			t = m;
//			m = n;
//			n = t;
//
//			n += m;//分子等于分母加分子
//			N--;
//		}
//		printf("%.2f\n", sum);
//	}
//	return 0;
//}

/*
选择排序
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
//				min = j;//标记最小值
//			}
//		}
//		swap(&arr[min], &arr[i]);
//	}
//}
//
//int main()
//{
//	//输入数据
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
自定义函数求两个数的最大公约数和最小公倍数
*/

#include<stdio.h>

int gcd(int m, int n)
{
	if (m<n)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}//确保m中放的是较大的数
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
		printf("%d %d\n", gcd(m, n), mcm(m, n));//最大公约数
	}
	return 0;
}