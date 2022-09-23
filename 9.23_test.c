#define _CRT_SECURE_NO_WARNINGS 1

/*

求奇数的乘积

Problem Description
给你n个整数，求他们中所有奇数的乘积。

Input
输入数据包含多个测试实例，每个测试实例占一行，每行的第一个数为n，表示本组数据一共有n个，接着是n个整数，你可以假设每组数据必定至少存在一个奇数。

Output
输出每组数中的所有奇数的乘积，对于测试实例，输出一行。

Sample Input
3 1 2 3
4 2 3 4 5

Sample Output
3
15

*/

//#include<stdio.h>
//int main()
//{
//	int num, i, n = 1, ret;
//	while (scanf("%d",&n) != EOF)
//	{
//		ret = 1;//将ret重新初始化为1
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &num);
//			if (num % 2 != 0)
//			{
//				ret *= num;
//			}
//		}
//		printf("%d\n", ret);
//	}
//	return 0;
//}

/*

平方和与立方和

Problem Description
给定一段连续的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。

Input
输入数据包含多组测试实例，每组测试实例包含一行，由两个整数m和n组成。

Output
对于每组输入数据，输出一行，应包括两个整数x和y，分别表示该段连续的整数中所有偶数的平方和以及所有奇数的立方和。
你可以认为32位整数足以保存结果。

Sample Input
1 3
2 5

Sample Output
4 28
20 152

*/

//#include<stdio.h>
//int main()
//{
//	int m, n, i;
//	int x = 0;
//	int y = 0;
//	while (scanf("%d %d",&m,&n) != EOF)
//	{
//		x = 0;
//		y = 0;
//		for ( i = m; i <= n; i++)//得到m到n
//		{
//			//判断奇偶
//			if (i%2 == 0)
//			{
//				//偶
//				x = x + i * i;
//			}
//			else
//			{
//				//奇
//				y = y + i * i * i;
//			}
//		}
//		printf("%d %d\n", x, y);
//	}
//	return 0;
//}

/*

数值统计

Problem Description
统计给定的n个数中，负数、零和正数的个数。

Input
输入数据有多组，每组占一行，每行的第一个数是整数n（n<100），表示需要统计的数值的个数，然后是n个实数；如果n=0，则表示输入结束，该行不做处理。

Output
对于每组输入数据，输出一行a,b和c，分别表示给定的数据中负数、零和正数的个数。

Sample Input
6 0 1 2 3 -1 0
5 1 2 3 4 0.5
0

Sample Output
1 2 3
0 0 5

*/

#include<stdio.h>
int main()
{
	int n, i;
	double num;
	while (scanf("%d",&n) != EOF)
	{
		if (n == 0)//输入n为0，不做处理
		{
			continue;
		}
		else
		{
			int count0 = 0;
			int count_z = 0;
			int count_f = 0;
			for (i = 0; i < n; i++)
			{
				scanf("%lf", &num);
				if (num == 0)
				{
					//为0
					count0++;
				}
				else if (num > 0)
				{
					//正数
					count_z++;
				}
				else
				{
					//负数
					count_f++;
				}
			}
			printf("%d %d %d\n", count_f, count0, count_z);
		}
	}
	return 0;
}