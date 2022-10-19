#define _CRT_SECURE_NO_WARNINGS 1

/*
题目 1048: [编程入门]自定义函数之字符串拷贝
时间限制: 1Sec 内存限制: 128MB 提交: 15143 解决: 8756
题目描述
有一字符串，包含n个字符。写一函数，将此字符串中从第m个字符开始的全部字符复制成为另一个字符串。
输入格式
数字n 一行字符串 数字m
输出格式
从m开始的子串
样例输入
6
abcdef
3
样例输出
cdef
*/

//#include<stdio.h>
//int main()
//{
//	//n个字符，从第m个开始复制
//	int n, m;
//	char str[1000];
//	scanf("%d", &n);
//	scanf("%s", &str);
//	scanf("%d", &m);
//	for (int i = m-1; i < n; i++)
//	{
//		printf("%c", str[i]);
//	}
//	return 0;
//}


/*
题目 1009: [编程入门] 数字的处理与判断
时间限制 : 1Sec 内存限制 : 128MB 提交 : 67767 解决 : 31423
题目描述
给出一个不多于5位的整数，要求 1、求出它是几位数 2、分别输出每一位数字 3、按逆序输出各位数字，例如原数为321, 应输出123
输入格式
一个不大于5位的数字
输出格式
三行 第一行 位数 第二行 用空格分开的每个数字，注意最后一个数字后没有空格 第三行 按逆序输出这个数
样例输入
12345
样例输出
5
1 2 3 4 5
54321
*/

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[10];
//	scanf("%s", &arr);
//	int len = strlen(arr);
//	printf("%d\n", len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	printf("\n");
//	for (int i = len-1; i >= 0; i--)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

/*
最大公约数和最小公倍数
*/

//#include<stdio.h>
//
//int Ma(int a, int b)
//{
//	if (a<b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	while (a%b != 0)
//	{
//		int tmp = a % b;
//		a = b;
//		b = tmp;
//	}
//	return b;
//}
//
//int Mi(int a, int b)
//{
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//
//	int i = a;
//	while (i%a!=0 || i%b!=0)
//	{
//		i++;
//	}
//	return i;
//}
//
//int main()
//{
//	int m, n;
//	while (scanf("%d%d", &m, &n) != EOF)
//	{
//		printf("%d %d\n", Ma(m, n), Mi(m, n));
//	}
//	return 0;
//}

/*
题目 1012: [编程入门]字符串分类统计
时间限制: 1Sec 内存限制: 128MB 提交: 48642 解决: 25401
题目描述
输入一行字符，分别统计出其中英文字母、数字、空格和其他字符的个数。

输入格式
一行字符,长度不超过200

输出格式
统计值

样例输入
aklsjflj123 sadf918u324 asdf91u32oasdf/.';123
样例输出
23 16 2 4
*/

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//		char str[200];
//		gets(str);
//		int letc = 0, numc = 0, spac = 0, othc = 0;
//		for (int i = 0; i < strlen(str); i++)
//		{
//			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
//			{
//				letc++;
//			}
//			else if (str[i] >= '0' && str[i] <= '9')
//			{
//				numc++;
//			}
//			else if (str[i] == ' ')
//			{
//				spac++;
//			}
//			else
//			{
//				othc++;
//			}
//		}
//		printf("%d %d %d %d\n", letc, numc, spac, othc);
//
//	return 0;
//}

/*
题目 1013: [编程入门]Sn的公式求和
时间限制: 1Sec 内存限制: 128MB 提交: 40603 解决: 27429
题目描述
求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字，为2。 例如，n=5时=2+22+222+2222+22222，n由键盘输入。

输入格式
n

输出格式
Sn的值

样例输入
5
样例输出
24690
*/

//#include<stdio.h>
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int a = 0;
//		int sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			a = a * 10 + 2;
//			sum += a;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

/*
题目 1025: [编程入门]数组插入处理
时间限制: 1Sec 内存限制: 128MB 提交: 36314 解决: 21840
题目描述
已有一个已正序排好的9个元素的数组，今输入一个数要求按原来排序的规律将它插入数组中。
输入格式
第一行，原始数列。 第二行，需要插入的数字。
输出格式
排序后的数列
样例输入
1 7 8 17 23 24 59 62 101
50
样例输出
1 7 8 17 23 24 50 59 62 101
*/

//#include<stdio.h>
//
//void insert_sort(int arr[], int n)
//{
//	int j = 8;
//	int key = n;
//	while (j>=0 && arr[j]>key)
//	{
//		arr[j + 1] = arr[j];
//		j--;
//	}
//	arr[j + 1] = key;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int n;
//	for (int i = 0; i < 9; i++)
//	{
//		scanf("%d", &arr[i]);
//	}//输入原始数据
//	scanf("%d", &n);//输入插入数据
//	insert_sort(arr,n);//进行插入
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//插入排序
//#include<stdio.h>
//
//void insert_sort(int arr[], int sz)
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int key = arr[i];
//		int j = i - 1;
//		while (j>=0 && arr[j]>key)
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = key;
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,2,5,3,7,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	insert_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*
数字逆序输出
输入10个整数，逆序输出，用空格隔开
*/
//
//#include<stdio.h>
//int main()
//{
//	int arr[10];
//	int i, j;
//	for ( i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for ( j = 9; j >=0 ; j--)
//	{
//		printf("%d ", arr[j]);
//	}
//	return 0;
//}

////宏定义
//
//#define MAX(x,y) (x>y?x:y)//宏的符号、宏的参数、宏体
//#define SUM(x,y) (x+y) //宏的简单定义
///*
//宏只适用于处理简单的逻辑
//*/
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = MAX(a, b);
//	int sum = SUM(a, b);
//	printf("max=%d\nsum=%d\n", max, sum);
//	return 0;
//}


//指针
#include<stdio.h>
int main()
{
	int a = 10;
	printf("%p\n", &a);//取出的是所占内存单元字节中 第一个字节的地址
	int* pc = &a;
	printf("%zd\n", sizeof(pc));//指针的大小
	return 0;
}