#define _CRT_SECURE_NO_WARNINGS 1

/*

偶数求和

Problem Description
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序每m个数求出一个平均值，
如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。

Input
输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。

Output
对于每组输入数据，输出一个平均值序列，每组输出占一行。

Sample Input
3 2
4 2

Sample Output
3 6
3 7

*/

#include<stdio.h>
//int main()
//{
//	int m, n, s;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		int k = 2;
//		int times = n / m;//分组
//		int r = n % m;//分组之后余下的数字个数
//		for (int i = 0; i < times; i++)//求每一组的平均值
//		{
//			s = 0;
//			for (int j = 0; j < m; j++, k += 2)
//			{
//				s += k;//求m项的和
//			}
//			printf("%d ", s / m);//输出平均值
//		}//k被保留
//		if (r != 0)//求余下r个数字的平均值
//		{
//			s = 0;
//			for (int i = 0; i < r; i++, k += 2)
//			{
//				s += k;
//			}
//			printf("%d", s / r);
//		}
//		printf("\n");
//	}
//	return 0;
//}

int main()
{
	int n, m, s;
	while (scanf("%d %d",&n,&m) != EOF)
	{
		int k = 2;
		int times = n / m;//分组
		int r = n % m;//分组后剩下r个数
		for (int i = 0; i < times; i++)
		{
			s = 0;
			for (int j = 0; j < m; j++, k += 2)
			{
				s += k;//对每一组求和
			}
			printf("%d ", s / m);//打印平均值
		}
		if (r != 0)
		{
			s = 0;
			for (int j = 0; j < r; j++, k += 2)//对余下的r个数进行求和
			{
				s += k;
			}
			printf("%d", s / r);//输出剩下r个数的平均值
		}
		printf("\n");
	}
	return 0;
}