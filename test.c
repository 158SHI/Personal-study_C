#define _CRT_SECURE_NO_WARNINGS 1

//递归和非递归求n的阶乘
//递归
//#include<stdio.h>
//
//int N(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * N(n - 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = N(n);
//	printf("%d", ret);
//	return 0;
//}

//非递归
//#include<stdio.h>
//
//int N(int n)
//{
//	int i = 0;
//	int m = 1;
//	for ( i = 1; i <= n; i++)
//	{
//		m = m * i;
//	}
//	return m;
//}
//
//int main(void)
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = N(n);
//	printf("%d", ret);
//	return 0;
//}

//递归和非递归模拟实现strlen函数
//递归
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);
//	}
//}
//
//int main()
//{
//	char arr[] = "hello";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//非递归
//计数器
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "hello";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//指针运算
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//
//int main()
//{
//	char arr[] = "hello";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//不使用库函数，用递归的方式倒置一个字符串中的元素
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void Rserve_sort(char* arr, int len)
//{
//	int tmp = 0;
//	int left = 0;
//	int right = len - 1;
//	tmp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = '\0';
//	if (my_strlen(arr+1)>=2)
//	{
//		Rserve_sort(arr + 1,my_strlen(arr+1));
//	}
//	arr[right] = tmp;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	Rserve_sort(arr,len);
//	printf("%s", arr);
//	return 0;
//}

//设计函数打印出一个非负整数的每一位
//#include<stdio.h>
//
//void Print(int n)
//{
//	if (n>9)
//	{
//		Print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入>:");
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}

//函数递归求组成一个非负整数的每一位的和
////1729
////DigitSum(172)+1729%10
////DigitSum(17)+172%10+1729%10
////DigitSum(1)+...
//#include<stdio.h>
//
//int DigitSum(int n)
//{
//	if (n>9)
//	{
//		return DigitSum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//
//int main()
//{
//	unsigned int n = 0;
//	scanf("%d", &n);
//	int ret = DigitSum(n);
//	printf("ret=%d\n", ret);
//}

//函数递归求n的k次方
//#include<stdio.h>
//
//double Pow(int n, int k)
//{
//	if (k<0)
//	{
//		return (1.0 / Pow(n, -k));
//	}
//	else if (k == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * Pow(n, k - 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	double ret = Pow(n, k);
//	printf("ret=%lf\n", ret);
//	return 0;
//}

//递归和非递归求第n个斐波那契数
//递归
//#include<stdio.h>
//
//int Fib(int n)
//{
//	if (n<=2)
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
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("ret=%d\n", ret);
//	return 0;
//}

//非递归
//#include<stdio.h>
//
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n>2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("ret=%d\n", ret);
//	return 0;
//}

//设计函数求两个数的最大公约数
#include<stdio.h>

int MCD(int m, int n)
{
	int k = 0;
	while (m%n != 0)
	{
		k = m % n;
		m = n;
		n = k;
	}
	return n;
}

int main()
{
	int m, n = 0;
	scanf("%d%d", &m, &n);
	int ret = MCD(m, n);
	printf("ret=%d\n", ret);
}