#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//
//int* Test(void)
//{
//	int a = 10;
//	return &a;
//}
//
//int main()
//{
//	int* ret = Test();
//	printf("hehe\n");
//	printf("%d\n", *ret);
//	return 0;
//}

/*
描述
给你一个整数n，按要求输出n∗n的回型矩阵
输入描述：
输入一行，包含一个整数n

1<=n<=19
输出描述：
输出n行，每行包含n个正整数
*/


//int main()
//{
//	int arr[20][20] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//
//	int up = 0;
//	int down = n - 1;
//	int left = 0;
//	int right = n - 1;
//	int val = 1;
//
//	int i = 0, j = 0;
//	while (val<=n*n)
//	{
//		for ( i = left; i <=right ; i++)
//		{
//			arr[up][i] = val++;
//		}
//		up++;
//		for ( i = up; i <= down; i++)
//		{
//			arr[i][right] = val++;
//		}
//		right--;
//		for ( i = right; i >= left ; i--)
//		{
//			arr[down][i] = val++;
//		}
//		down--;
//		for ( i = down; i >= up; i--)
//		{
//			arr[i][left] = val++;
//		}
//		left++;
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*
描述
给你一个整数n，输出n∗n的蛇形矩阵。
输入描述：
输入一行，包含一个整数n
输出描述：
输出n行，每行包含n个正整数，通过空格分隔。

1<=n<=1000
*/

//int arr[1001][1001] = { 0 };
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 1, j = 1;
//	int pos = 1;
//	arr[i][j] = 1;
//	/*
//	用pos表示方向
//	pos==1 右上和右
//	pos==-1 左下和左
//	*/
//
//	for (int val = 2; val <= n * n; val++)
//	{
//		if (i == 1 && j < n && pos == 1)//上边界
//		{
//			arr[i][++j] = val;
//			pos = -1;
//		}
//		else if (j == 1 && i < n && pos == -1)//左边界
//		{
//			arr[++i][j] = val;
//			pos = 1;
//		}
//
//		else if (i == n && pos == -1)//下边界
//		{
//			arr[i][++j] = val;
//			pos = 1;
//		}
//		else if (j == n && pos == 1)//右边界
//		{
//			arr[++i][j] = val;
//			pos = -1;
//		}
//
//		//内部
//		else if (pos == 1)
//		{
//			arr[--i][++j] = val;
//		}
//		else if (pos == -1)
//		{
//			arr[++i][--j] = val;
//		}
//
//		else
//		{
//			;
//		}
//	}
//
//	for (i = 1; i < n; i++)
//	{
//		for (j = 1; j < n; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*
描述
KiKi想知道一个n阶方矩是否为上三角矩阵，请帮他编程判定。上三角矩阵即主对角线以下的元素都为0的矩阵，主对角线为从矩阵的左上角至右下角的连线。

输入描述：
第一行包含一个整数n，表示一个方阵包含n行n列，用空格分隔。 (2≤n≤10)

从2到n+1行，每行输入n个整数（范围-231~231-1），用空格分隔，共输入n*n个数。

输出描述：
一行，如果输入方阵是上三角矩阵输出"YES"并换行，否则输出"NO"并换行。
*/

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int tmp = 0;
//	int i = 0, j = 0;
//	int count = 0;
//	for ( i = 0; i < n; i++)
//	{
//		for ( j = 0; j < n; j++)
//		{
//			scanf("%d", &tmp);
//			if (i>j)
//			{
//				count += tmp;
//			}
//		}
//	}
//	
//	count == 0 ? printf("YES\n") : printf("NO\n");
//	return 0;
//}
