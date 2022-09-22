#define _CRT_SECURE_NO_WARNINGS 1



/*

第几天？
Problem Description
给定一个日期，输出这个日期是该年的第几天。

Input
输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。

Output
对于每组输入数据，输出一行，表示该日期是该年的第几天。

Sample Input
1985/1/20
2006/3/12

Sample Output
20
71

*/

#include<stdio.h>

//法1
//int Leap(int y)
//{
//	if ((y%4 == 0 && y%100 != 0) || (y%400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int DAYS(int y, int m, int d)
//{
//	int ret = Leap(y);//判断是否是闰年，是闰年返回1;是平年返回0
//	if (ret == 1)
//	{
//		//是闰年
//		int arr1[15] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//		int x = m - 1;
//		int i, MD = 0;
//		for ( i = 0; i < m-1; i++)
//		{
//			MD = MD + arr1[i];
//		}
//		return MD + d;
//	}
//	else
//	{
//		//是平年
//		int arr2[15] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//		int x = m - 1;
//		int i, MD = 0;
//		for (i = 0; i < m - 1; i++)
//		{
//			MD = MD + arr2[i];
//		}
//		return MD + d;
//	}
//}

//switch语句实现
int DAYS(int y, int m, int d)
{
	int sum = 0;
	switch (m-1)
	{
	//case 12:
	//	sum += 31;
	case 11:
		sum += 30;
	case 10:
		sum += 31;
	case 9:
		sum += 30;
	case 8:
		sum += 31;
	case 7:
		sum += 31;
	case 6:
		sum += 30;
	case 5:
		sum += 31;
	case 4:
		sum += 30;
	case 3:
		sum += 31;
	case 2:
	{
		if ((y%4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			sum += 29;//闰年
		}
		else
		{
			sum += 28;//平年
		}
	}
	case 1:
		sum += 31;
	case 0:
		sum += 0;
	}
	return sum + d;
}

int main()
{
	int Y, M, D;
	while (scanf("%d/%d/%d",&Y,&M,&D) != EOF)
	{
		int ret = DAYS(Y, M, D);
		printf("%d\n",ret);
	}
	return 0;
}