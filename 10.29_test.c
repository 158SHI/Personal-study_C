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
	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));// 48 表示整个数组的大小
	printf("%d\n", sizeof(a[0][0]));// 4 表示第一行第一列元素的大小
	printf("%d\n", sizeof(a[0]));// 16 表示第一行的大小。可以看做一个含3个元素的一维数组，每个元素为每一行的数组名。a[0]表示第一行的数组名
	printf("%d\n", sizeof(a[0] + 1));// 4/8 a[0]+1中，a[0]是第一行的数组名，此时表示第一行首元素的地址，+1表示第一行第二个元素的地址
	printf("%d\n", sizeof(*(a[0] + 1)));// 4 表示第一行第二个元素的大小
	printf("%d\n", sizeof(a + 1));// 4/8 a表示a[3][4]的首元素地址，二维数组的首元素是第一行，所以a是第一行的地址，+1表示第二行的地址
	printf("%d\n", sizeof(*(a + 1)));// 16 第二行的地址解引用，表示第二行的大小
	printf("%d\n", sizeof(&a[0] + 1));// 4/8 a[0]表示第一行的数组名，&数组名表示第一行的地址，+1表示第二行的地址
	printf("%d\n", sizeof(*(&a[0] + 1)));// 16 表示第二行数组的大小
	printf("%d\n", sizeof(*a));// 16 表示第一行数组的大小
	printf("%d\n", sizeof(a[3]));// 16 sizeof( )括号中的表达式不进行计算，此处不会访问 "第四行"
	return 0;
}