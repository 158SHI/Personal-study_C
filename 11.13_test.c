#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

/*
试计算在区间1 到n 的所有整数中，数字x（0 ≤ x ≤ 9）共出现了多少次？
例如，在1到11 中，即在1、2、3、4、5、6、7、8、9、10、11 中，数字1 出现了4 次。
输入描述：
输入共1行，包含2个整数n、x，之间用一个空格隔开。
输出描述：
输出共1行，包含一个整数，表示x出现的次数。
*/

//int number_times(int i,int x)
//{
//	int count = 0;
//	while (i>0)
//	{
//		if (i%10 == x)
//		{
//			count++;
//		}
//		i /= 10;
//	}
//	return count;
//}
//
//int Times(int n, int x)
//{
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int ret = number_times(i,x);//计算各个数字中出现x的次数
//		count += ret;
//	}
//	return count;
//}
//
//int main()
//{
//	int n, x;
//	scanf("%d %d", &n, &x);
//	int ret = Times(n, x);
//	printf("%d\n", ret);
//	return 0;
//}

/*
描述
输入10个整数，要求按输入时的逆序把这10个数打印出来。逆序输出，就是按照输入相反的顺序打印这10个数。
输入描述：
一行，输入10个整数（范围-231~231-1），用空格分隔。
输出描述：
一行，逆序输出输入的10个整数，用空格分隔。
*/

//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 9; i >=0 ; i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*
描述
输入数字N，然后输入N个数，计算这N个数的和。
输入描述：
第一行输入一个整数N(0≤N≤50)，第二行输入用空格分隔的N个整数。
输出描述：
输出为一行，为第二行输入的“N个整数之和”的计算结果。
*/

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int count = 0;
//	int tmp = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &tmp);
//		count += tmp;
//	}
//	printf("%d", count);
//	return 0;
//}

/*
描述
输入n个成绩，换行输出n个成绩中最高分数和最低分数的差。
输入描述：
两行，第一行为n，表示n个成绩，不会大于10000。

第二行为n个成绩（整数表示，范围0~100），以空格隔开。
输出描述：
一行，输出n个成绩中最高分数和最低分数的差。
*/

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int min = 101;
//	int max = -1;
//	int mark = 0;
//	for (int i = 0; i < n; i++)//寻找最大值和最小值
//	{
//		scanf("%d", &mark);
//		if (mark>max)
//		{
//			max = mark;
//		}
//		if (mark<min)
//		{
//			min = mark;
//		}
//	}
//	int Sub = max - min;
//	printf("%d\n", Sub);
//	return 0;
//}

/*
描述
输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。

数据范围： 1 \le n, m \le 1000 \1≤n,m≤1000  ， 序列中的值满足 0 \le val \le 30000 \0≤val≤30000
输入描述：
输入包含三行，

第一行包含两个正整数n, m，用空格分隔。n表示第二行第一个升序序列中数字的个数，m表示第三行第二个升序序列中数字的个数。

第二行包含n个整数，用空格分隔。

第三行包含m个整数，用空格分隔。
输出描述：
输出为一行，输出长度为n+m的升序序列，即长度为n的升序序列和长度为m的升序序列中的元素重新进行升序序列排列合并。
*/


void insert_sort(int arr[2000],int n,int sz)
{
	int i = 0;
	
}

int main()
{
	int arr[2000] = { 0 };
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)//输入数组n
	{
		scanf("%d", &arr[i]);
	}
	int tmp = 0;
	for (int j = 0; j < m; j++)//逐个插入
	{
		scanf("%d", &tmp);
		insert_sort(arr, tmp, 2000);
	}

	for (int i = 0; i < 2000; i++)//输出
	{
		if (arr[i])
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}