#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//memset

//int main()
//{
//	char arr[] = "abcdefg";
//	memset(arr, 'x', 5);
//	printf("%s", arr);
//	return 0;
//}
//
//int is_leap(int y)
//{
//
//	if ((y % 4 == 0) && (y % 100 != 0))
//	{
//		return 1;
//	}
//	else if (y % 400 == 0)
//	{
//		return 1;
//	}
//	//if (y%400 == 0)
//	//{
//	//	return 1;
//	//}
//	else
//	{
//		return 0;
//	}
//}

//int main()
//{
//	int count = 0;
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if (is_leap(i) == 1)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}


	//if (((y%4 == 0) && (y%100 != 0))||((y%400==0)))
	//{
	//	return 1;
	//}
	//else
	//{
	//	return 0;
	//}

int main()
{
	//��ά����
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));// 48 ��ʾ��������Ĵ�С
	printf("%d\n", sizeof(a[0][0]));// 4 ��ʾ��һ�е�һ��Ԫ�صĴ�С
	printf("%d\n", sizeof(a[0]));// 16 ��ʾ��һ�еĴ�С�����Կ���һ����3��Ԫ�ص�һά���飬ÿ��Ԫ��Ϊÿһ�е���������a[0]��ʾ��һ�е�������
	printf("%d\n", sizeof(a[0] + 1));// 4/8 a[0]+1�У�a[0]�ǵ�һ�е�����������ʱ��ʾ��һ����Ԫ�صĵ�ַ��+1��ʾ��һ�еڶ���Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*(a[0] + 1)));// 4 ��ʾ��һ�еڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(a + 1));// 4/8 a��ʾa[3][4]����Ԫ�ص�ַ����ά�������Ԫ���ǵ�һ�У�����a�ǵ�һ�еĵ�ַ��+1��ʾ�ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(a + 1)));// 16 �ڶ��еĵ�ַ�����ã���ʾ�ڶ��еĴ�С
	printf("%d\n", sizeof(&a[0] + 1));// 4/8 a[0]��ʾ��һ�е���������&��������ʾ��һ�еĵ�ַ��+1��ʾ�ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(&a[0] + 1)));// 16 ��ʾ�ڶ�������Ĵ�С
	printf("%d\n", sizeof(*a));// 16 ��ʾ��һ������Ĵ�С
	printf("%d\n", sizeof(a[3]));// 16 sizeof( )�����еı��ʽ�����м��㣬�˴�������� "������"
	return 0;
}