#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
////按[10,20,30,40,50]的格式打印字符串
//int main()
//{
//	int arr[] = { 10,20,30,40,50 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	printf("[");
//	for (int i = 0; i < len; i++)
//	{
//		if (i == len-1)
//		{
//			printf("%d]", arr[i]);
//		}
//		else
//		{
//			printf("%d,", arr[i]);
//		}
//	}
//	printf("\n");
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int a = n / 100;
//		int b = n / 10 % 10;
//		int c = n - 100 * a - 10 * b;
//		int ret = c * 100 + b * 10 + a;
//		if (ret>0)
//		{
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("%d\n", -ret);
//		}
//	}
//	return 0;
//}

#include<stdio.h>

int sum(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int a = 0;
	int b = 0;
	while (scanf("%d%d",&a,&b) != EOF)
	{
		int ret=sum(a,b);
		printf("%d\n", ret);
	}
	return 0;
}