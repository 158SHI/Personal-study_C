#define _CRT_SECURE_NO_WARNINGS 1



/*

�ڼ��죿
Problem Description
����һ�����ڣ������������Ǹ���ĵڼ��졣

Input
���������ж��飬ÿ��ռһ�У����ݸ�ʽΪYYYY/MM/DD��ɣ�����μ�sample input ,���⣬��������ȷ�����е����������ǺϷ��ġ�

Output
����ÿ���������ݣ����һ�У���ʾ�������Ǹ���ĵڼ��졣

Sample Input
1985/1/20
2006/3/12

Sample Output
20
71

*/

#include<stdio.h>

//��1
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
//	int ret = Leap(y);//�ж��Ƿ������꣬�����귵��1;��ƽ�귵��0
//	if (ret == 1)
//	{
//		//������
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
//		//��ƽ��
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

//switch���ʵ��
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
			sum += 29;//����
		}
		else
		{
			sum += 28;//ƽ��
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