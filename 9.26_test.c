#define _CRT_SECURE_NO_WARNINGS 1

/*

求数列的和

Problem Description
数列的定义如下：
数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。

Input
输入数据有多组，每组占一行，由两个整数n（n<10000）和m(m<1000)组成，n和m的含义如前所述。

Output
对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。

Sample Input
81 4
2 2

Sample Output
94.73
3.41

*/

//#include<stdio.h>
//#include<math.h>

//int main()
//{
//	int m, i;
//	double n;
//	while (scanf("%lf %d", &n, &m) != EOF)
//	{
//		double ret = n;
//		for (i = 1; i < m; i++)
//		{
//			n = (double)sqrt(n);
//			ret += n;
//		}
//		printf("%.2lf\n", ret);
//	}
//	return 0;
//}

//pow函数求解
//int main()//运行时间较长
//{
//	int m, i;
//	double n;
//	while (scanf("%lf %d", &n, &m) != EOF)
//	{
//		double ret = 0;
//		for (i = 2; i <= pow(2,m); i *= 2)
//		{
//			ret += pow(n, 2.0 / i);
//		}
//		printf("%.2lf\n", ret);
//	}
//	return 0;
//}

/*

多项式求和

Problem Description
多项式的描述如下：
1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
现在请你求出该多项式的前n项的和。

Input
输入数据由2行组成，首先是一个正整数m（m<100），表示测试实例的个数，第二行包含m个正整数，对于每一个整数(不妨设为n,n<1000），求该多项式的前n项的和。

Output
对于每个测试实例n，要求输出多项式前n项的和。每个测试实例的输出占一行，结果保留2位小数。

Sample Input
2
1 2

Sample Output
1.00
0.50

*/

#include<stdio.h>
int main()
{
	int n, i, j;
	int a[100] = { 0 };
	double s, t;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);//将输入的值存入a[100]
		}
		for (i = 0; i < n; i++)//执行n次
		{
			t = 1.0;
			s = 0;
			for (j = 1; j <= a[i]; j++)
			{
				s += (t * (1.0 / j));
				t = -t;
			}//求和
			printf("%.2lf\n", s);//打印
		}
	}
	return 0;
}

//求前n项1-1/2+1/3之和
//#include<stdio.h>
//int main()
//{
//	int n, i;
//	double ret = 0;
//	int sign = 1;
//	scanf("%d", &n);
//	for ( i = 1; i <= n; i++)
//	{
//		ret = ret + sign * (1.0 / i);
//		sign = -sign;
//	}//计算前n项和
//	printf("%lf", ret);
//	return 0;
//}

