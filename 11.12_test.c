#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

//不创建临时变量，交换两个整型
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("before:a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("after:a=%d b=%d\n", a, b);
//	return 0;
//}


//写一个函数返回参数二进制中 1 的个数。

//int operation(int n)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (n & (1<<i))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = operation(n);
//	printf("%d\n", ret);
//	return 0;
//}

//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列

//void Print(int n)
//{
//	for (int i = 30; i >=0; i-=2)//奇数位
//	{
//		printf("%d", (n >> i)&1);
//	}
//	printf("\n");
//	for (int j = 31; j >0; j-=2)//偶数位
//	{
//		printf("%d", (n >> j)&1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}

/*
编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？

输入例子:

1999 2299

输出例子:7
*/

//int differ(int m, int n)
//{
//	int tmp = m ^ n;
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (tmp & (1 << i))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int m, n;
//	scanf("%d %d", & m, &n);
//	int ret = differ(m, n);
//	printf("%d\n", ret);
//	return 0;
//}

/*
描述
今天牛牛学到了回文串，他想在数字里面找回文，即回文数，回文数是正着读与倒着读都一样的数，比如1221，343是回文数，433不是回文数。请输出不超过n的回文数。
输入描述：
输入一个整数n(1 <= n <= 100000)
输出描述：
从1开始按从小到大的顺序输出所有回文数
*/

_Bool is_ret(int n)
{
	int t = 0;
	int tmp = n;

	while (n > 0)//将数字倒序
	{
		t = t * 10 + n % 10;
		n = n / 10;
	}

	if (t == tmp)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (is_ret(i))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}