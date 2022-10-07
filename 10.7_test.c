#define _CRT_SECURE_NO_WARNINGS 1

/*

替换空格
题目：实现一个函数，把字符串中的每个空格替换成%20.
例如：输入“We are happy”，则输出We%20are%20happy.

*/

//#include<stdio.h>
//#include<string.h>
//
//void Change1(char arr[])
//{
//	int n = strlen(arr);
//	int i = 0;
//	while (arr[i] != '\0')
//	{
//		if (arr[i] == ' ')
//		{
//			n += 2;//检索到空格，长度加2
//			for (int j = n-1; j > i; j--)
//			{
//				arr[j] = arr[j - 2];//从后往前替换（整体移动）
//			}
//			arr[i++] = '%';
//			arr[i++] = '2';
//			arr[i] = '0';
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//}
//
//void Change2(char arr[])
//{
//	int i = 0;
//	int len = 0, space = 0;
//	while (arr[i] != '\0')//计算字符长度和空格长度
//	{
//		len++;
//		if (arr[i] == ' ')
//		{
//			space++;
//		}
//		i++;
//	}
//	int p1 = len-1;//把原始长度赋给p1
//	int p2 = len + 2 * space-1;//把改变后的长度赋给p2
//	while (p1 >= 0)
//	{
//		if (arr[p1] == ' ')
//		{
//			arr[p2--] = '0';
//			arr[p2--] = '2';
//			arr[p2] = '%';
//		}
//		else
//		{
//			arr[p2--] = arr[p1];
//		}
//		p1--;
//	}
//	printf("%s\n", arr);
//}
//
//int main()
//{
//	char arr[50] = " We are very happy ";
//	printf("Before:%s\nAfter:\n", arr);
//	Change1(arr);
//	Change2(arr);
//	return 0;
//}

//不做四则运算做加法
//#include<stdio.h>
//
//int Sum(int a, int b)
//{
//	int carry, sum;
//	while (b)
//	{
//		sum = a ^ b;//按位相加
//		carry = (a & b) << 1;//进位
//		a = sum;
//		b = carry;//做重复运算
//	}
//	return a;
//}
//
////两数相加：先按位相加，再进位
////在二进制中，按位相加是异或运算，进位是两数做与运算再左移一位
//int main()
//{
//	int a = 3, b = 5;
//	int ret = Sum(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

////青蛙跳台阶
//#include<stdio.h>
//
//int Jump(int n)
//{
//	if (n == 0 || n == 1)
//	{
//		return n;
//	}
//	else
//	{
//		return Jump(n - 1) + Jump(n - 2);
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)
//	{
//		int ret = Jump(n);
//		printf("%d\n", ret);
//	}
//	return 0;
//}

/*

~~暴力青蛙跳台阶
一直青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶有多少种跳法。

*/

/*
解题思路：
 每个台阶可以看作一块木板，让青蛙跳上去，n个台阶就有n块木板，最后一块木板是青蛙到达的位子， 必须存在，
 其他 (n-1) 块木板可以任意选择是否存在，则每个木板有存在和不存在两种选择，(n-1) 块木板 就有 [2^(n-1)] 种跳法，可以直接得到结果。

其实我们所要求的序列为：0,1,2,4,8,16,……
*/
//#include<stdio.h>
//
//int Jump(int n)
//{
//	if (n==0 || n==1)
//	{
//		return n;
//	}
//	else
//	{
//		int num = 1;
//		for (int i = 1; i < n; i++)
//		{
//			num = num * 2;
//		}
//		return num;
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)
//	{
//		int ret = Jump(n);
//		printf("%d\n", ret);
//	}
//	return 0;
//}

//求n*n乘法表
#include<stdio.h>

void TEST(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", i, j, i * j);
		}
		printf("\n");
	}
}

int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		TEST(n);
	}
	return 0;
}