#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//��ŵ������
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
//	printf("������ n=");
//	int n;
//	scanf("%d", &n);
//	printf("�ƶ�����>:\n");
//	Hanoi(n,'A','B','C');
//	return 0;
//}

//ʵ��쳲���������

//�ݹ�
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

//����

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

//��n�Ľ׳�

//�ݹ�
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
////�ǵݹ�
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
��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�

ʵ�֣��������ַ����е��ַ��������У����������ӡ��

Ҫ�󣺲���ʹ��C�������е��ַ�������������
*/

