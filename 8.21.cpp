#define _CRT_SECURE_NO_WARNINGS 1

//输出10个数中最大的数
//分数求和
//输出1到100间数字3的个数
//试除法输出1到100间的素数
//输出2000到3000年间的闰年
//以从小到大打的顺序输出3个数
//辗转相除法求两个数的最大公约数
//二分查找法查找有序数组中的某个元素


////输出10个数中最大的数
//#include<stdio.h>
//int main(void)
//{
//	int arr[] = { -1,2,-5,7,5,4,-9,7,-10,-2 };
//	int max = arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for ( i = 1; i <sz; i++)
//	{
//		if (arr[i]>max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max=%d", max);
//	return 0;
//}

////分数求和，计算1/1-1/2+1/3-...+1/99-1/100
//#include<stdio.h>
//int main(void)
//{
//	int flag = 1;
//	int i = 0;
//	double sum = 0;
//	for ( i = 1; i <=100; i++)
//	{
//		double m = flag*(1.0 / i);
//		sum += m;
//		flag = -flag;
//	}
//	printf("sum=%lf", sum);
//	return 0;
//}

////输出1到100之间数字3的个数
//#include<stdio.h>
//int main(void)
//{
//	int i = 0;
//	int count = 0;
//	for ( i = 1; i <=100; i++)
//	{
//		if (i%10==3)
//		{
//			count++;
//		}
//		if (i/10==3)
//		{
//			count++;
//		}
//	}
//	printf("count=%d", count);
//	return 0;
//}

////试除法输出1到100间的素数
//#include<stdio.h>
//#include<math.h>
//int main(void)
//{
//	int i = 0;
//	int m = 0;
//	int count = 0;
//	printf("2 ");
//	for ( i = 3; i <=100 ; i+=2)
//	{
//		for ( m = 2; m <=sqrt(i); m++)
//		{
//			if (i%m==0)
//			{
//				break;
//			}
//		}
//		if (m>sqrt(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

////输出2000到3000年之间的闰年
//#include<stdio.h>
//int main(void)
//{
//	int y = 0;
//	int count = 0;
//	for ( y = 2000; y <=3000; y++)
//	{
//		if ((y%4==0)&&(y%100!=0)||(y%400==0))
//		{
//			printf("%d ", y);
//			count++;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

////以从小到大的顺序输出3个数
//#include<stdio.h>
//int main(void)
//{
//	int a, b, c;
//	int temp = 0;
//	printf("请输入3个数>:");
//	scanf("%d%d%d", &a, &b, &c);
//	//使a、c分别存放最大值和最小值
//	if (a<b)
//	{
//		temp = a;
//		a = b;
//		b = temp;
//	}
//	if (a<c)
//	{
//		temp = a;
//		a = c;
//		c = temp;
//	}
//	if (b<c)
//	{
//		temp = b;
//		b = c;
//		c = temp;
//	}
//	printf("%d>%d>%d", a, b, c);
//	return 0;
//}

////辗转相除法求两个数的最大公约数
//#include<stdio.h>
//int main(void)
//{
//	int m, n;
//	int r = 0;
//	printf("请输入两个数>:");
//	scanf("%d%d", &m, &n);
//	while (m%n != 0)
//	{
//		r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("这两个数的最大公约数为%d", n);
//	return 0;
//}

//二分查找法查找有序数组中的某个元素
#include<stdio.h>
int main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int k = 0;
	printf("请输入要查找的数>:");
	scanf("%d", &k);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (arr[mid]<k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到了，该元素下标为%d", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("无法找到该元素");
	}
	return 0;
}