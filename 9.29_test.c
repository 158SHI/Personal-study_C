#define _CRT_SECURE_NO_WARNINGS 1

/*

蟠桃记

Problem Description
喜欢西游记的同学肯定都知道悟空偷吃蟠桃的故事，你们一定都觉得这猴子太闹腾了，其实你们是有所不知：悟空是在研究一个数学问题！
什么问题？他研究的问题是蟠桃一共有多少个！
不过，到最后，他还是没能解决这个难题，呵呵^-^
当时的情况是这样的：
第一天悟空吃掉桃子总数一半多一个，第二天又将剩下的桃子吃掉一半多一个，以后每天吃掉前一天剩下的一半多一个，
到第n天准备吃的时候只剩下一个桃子。聪明的你，请帮悟空算一下，他第一天开始吃的时候桃子一共有多少个呢？

Input
输入数据有多组，每组占一行，包含一个正整数n（1<n<30），表示只剩下一个桃子的时候是在第n天发生的。

Output
对于每组输入数据，输出第一天开始吃的时候桃子的总数，每个测试实例占一行。

Sample Input
2
4

Sample Output
4
22

*/

//逆向运算
//#include<stdio.h>
//int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)
//	{
//		int sum = 1;
//		for (int i = 1; i < n; i++)
//		{
//			sum = (sum + 1) * 2;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

//递归
//#include<stdio.h>
//
//int F(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return (F(n - 1) + 1) * 2;
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)//输入天次
//	{
//		printf("%d\n", F(n));
//	}
//	return 0;
//}


/*

青年歌手大奖赛_评委会打分

Problem Description
青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。

Input
输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。

Output
对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。

Sample Input
3 99 98 97
4 100 99 98 97

Sample Output
98.00
98.50

*/

//#include<stdio.h>
//
//int F_MAX(int arr[100], int n)
//{
//	int j = 0;
//	int max = arr[j];
//	for (int  i = 1; i < n; i++)
//	{
//		if (arr[i] > arr[j])
//		{
//			j = i;//标记最大值
//		}
//	}
//	return arr[j];
//}
//
//int F_MIN(int arr[100], int n)
//{
//	int j = 0;
//	int min = arr[j];
//	for (int i = 1; i < n; i++)
//	{
//		if (arr[i] < arr[j])
//		{
//			j = i;//标记最小值
//		}
//	}
//	return arr[j];
//}
//
//double AVE(int max, int min, int arr[100],int n)
//{
//	double sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum = sum + arr[i];
//	}
//	sum = sum - max - min;//减去一个最小值和一个最大值
//	return sum / (n - 2);
//}
//
//int main()
//{
//	int n;
//	int arr[100] = { 0 };//存放选手分数的数组
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &arr[i]);//输入分数
//		}
//		double max = F_MAX(arr, n);//找出最大值
//		double min = F_MIN(arr, n);//找出最小值
//		double ret = AVE(max, min, arr, n);//求平均值
//		printf("%.2lf\n", ret);
//	}
//	return 0;
//}

/*

偶数求和

Problem Description
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。

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