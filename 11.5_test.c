#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//递归计算n!
//double Pow(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1.0;
//	}
//	else if (k > 0)
//	{
//		return n * Pow(n, k - 1);
//	}
//	else
//	{
//		return 1.0 / Pow(n, -k);
//	}
//}
//
//int main()
//{
//	int n, k;
//	scanf("%d %d", &n, &k);
//	double ret = Pow(n, k);
//	printf("%.2lf", ret);
//	return 0;
//}

//int my_strlen(char* p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//
//void reverse_string(char* str)
//{
//	int len = my_strlen(str);
//	char tmp = *str;
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str+1) >= 2)//
//	{
//		reverse_string(str + 1);
//	}
//	*(str + len - 1) = tmp;
//}
//
////递归逆序字符串
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	return 0;
//}

//交换数组

//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 3,4,5,6,7 };
//
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int tmp = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	printf("交换后:\narr1:");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\narr2:");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

/*
创建一个整形数组，完成对数组的操作

实现函数init() 初始化数组为全0
实现print()  打印数组的每个元素
实现reverse()  函数完成数组元素的逆置。
要求：自己设计以上函数的参数，返回值。
*/

//void init(int* p,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		p[i] = 0;
//	}
//}
//
//void print(int* p, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", p[i]);
//	}
//}
//
//void reverse(int* p, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left<right)
//	{
//		tmp = p[left];
//		p[left] = p[right];
//		p[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10];
//	init(arr,10);
//	print(arr,10);
//	reverse(arr,10);
//	//printf("\n");
//	//print(arr, 10);
//	return 0;
//}

#include<errno.h>
#include<string.h>
#include<ctype.h>

//int main()
//{
//	printf("%s\n", strerror(1));
//	int ret = isupper('a');
//	printf("%d\n", ret);
//	return 0;
//}

struct Stu//结构体类型Stu
{
	char name[10];//成员变量
} s1,s2,s3;//s1,s2,s3是全局结构体变量

struct//匿名结构体类型
{
	char name[];
}X;

int main()
{
	struct Stu s4;//s4是局部结构体变量
	return 0;
}