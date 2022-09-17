#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
//int main(void)
//{
//	int i = 0;
//	for ( i = 0; i < 100; i++)
//	{
//		printf("%d ",i);
//	}
//	return 0;
//}

//1!+2!+3!+...+n!

//int N(int n)
//{
//	int i = 0;
//	int m = 1;
//	for ( i = 1; i <= n; i++)
//	{
//		m = m * i;
//	}
//	return m;
//}
//
//int main()
//{
//	int ret = 0;
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	//ret = N(2);
//	for ( i = 1; i <= n; i++)
//	{
//		ret = N(i) + ret;
//	}
//	printf("ret=%d\n", ret);
//	return 0;
//}

//
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for ( i = 0; i <=15 ; i++)//死循环,i=15是arr[15]与i的地址相同
	{
		printf("hehe\n");
		arr[i] = 0;
	}
	return 0;
}