#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//汉诺塔问题
//#include<stdio.h>
//
//void move(char x, char y)
//{
//	printf("%c->%c\n", x, y);
//}
//
//void Hanoi(int n,char a,char b,char c)
//{
//	if (n == 1)
//	{
//		move(a, c);
//	}
//	else
//	{
//		Hanoi(n - 1, a, c, b);
//		move(a, c);
//		Hanoi(n - 1, a, b, c);
//	}
//}
//
//int main()
//{
//	printf("请输入 n=");
//	int n;
//	scanf("%d", &n);
//	printf("移动步骤>:\n");
//	Hanoi(n,'A','B','C');
//	return 0;
//}

//实现斐波那契数列

//递归
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
//	int n;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//迭代

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
//	int n;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;	
//}

//求n的阶乘

//递归
//int F1(n)
//{
//	if (n==0)
//	{
//		return 0;
//	}
//	else
//	{
//		if (n == 1)
//		{
//			return 1;
//		}
//		else
//		{
//			return n * F1(n - 1);
//		}
//	}
//}
//
////非递归
//int F2(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		int ret = 1;
//		for (int i = 1; i <= n; i++)
//		{
//			ret *= i;
//		}
//		return ret;
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	printf("%d\n", F1(n));
//	printf("%d\n", F2(n));
//	return 0;
//}

/*
编写一个函数 reverse_string(char * string)（递归实现）

实现：将参数字符串中的字符反向排列，不是逆序打印。

要求：不能使用C函数库中的字符串操作函数。
*/

