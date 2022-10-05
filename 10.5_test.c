#define _CRT_SECURE_NO_WARNINGS 1

/*

不做加减乘除做加法

写一个函数，求两个整数之和，要求在函数体内不得使用加减乘除四则运算符号

*/

//#include<stdio.h>
//
//int Sum(int a, int b)
//{
//	int carry, sum;
//	while (b)
//	{
//		sum = a ^ b;//按位相加
//		carry = (a & b) << 1;//进位
//		a = sum;
//		b = carry;//做重复运算
//	}
//	return a;
//}
//
////两数相加：先按位相加，再进位
////在二进制中，按位相加是异或运算，进位是两数做与运算再左移一位
//int main()
//{
//	int a = 3, b = 5;
//	int ret = Sum(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

//插入排序
//#include<stdio.h>
//
//void Sert_sorb(int arr[], int sz)
//{
	//for (int i = 1; i < sz; i++)
	//{
	//	int key = arr[i];//标记要插入的数
	//	int j = i - 1;
	//	while (j>=0 && key<arr[j])//逐个将要插入的数与前面的数进行比较
	//	{
	//		arr[j + 1] = arr[j];
	//		j--;
	//	}
	//	arr[j+1] = key;//将数插入
	//}
//}
//
//int main()
//{
//	int arr[] = { 4,2,5,3,7,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Sert_sorb(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

例如：{1, 2, 3, 4, 5, 6, 7} 调整后为：{1, 3, 5, 7, 2, 4, 6}。

*/

//#include<stdio.h>
//
//int Judge(int x)
//{
//	if (x % 2 == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//	//偶数返回0
//	//奇数返回1
//}
//
//void Resort(int arr[], int sz)//插入排序
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int ret = Judge(arr[i]);//判断i的奇偶
//		if (ret == 0)//i为偶
//		{
//			continue;
//		}
//		else//i为奇
//		{
//			int key = arr[i];
//			int j = i - 1;
//			while (j>=0 && Judge(arr[j]) == 0)
//			{
//				arr[j + 1] = arr[j];
//				j--;
//			}
//			arr[j + 1] = key;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 2,5,4,7,3,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Resort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}
由于数字2在数组中出现了五次，超过数组长度的一半，因此输出2
如果不存在则输出0

*/

//1.先排序后判断
//排序后，若这样的数存在，则一定是中间的那个数
//#include<stdio.h>
//
//void Resort(int arr[], int sz)
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int key = arr[i];//标记要插入的数
//		int j = i - 1;
//		while (j >= 0 && key < arr[j])//逐个将要插入的数与前面的数进行比较
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = key;//将数插入
//	}
//}
//
//int main()
//{
//	int arr[] = { 2,2,3,2,2,2,5,7 };//2
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Resort(arr,sz);//排序
//	int left = 0, right = sz - 1;
//	int mid = left + (right - left) / 2;
//	int key = arr[mid];
//	int count = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (arr[i] == key)
//		{
//			count++;//计算key出现的次数
//		}
//	}
//	if (count > sz/2)//判断key是否符合条件
//	{
//		printf("%d\n", key);
//	}
//	else
//	{
//		printf("0\n");
//	}
//	return 0;
//}

//2.摩尔投票算法（Boyer-Moore Algorithm）
#include<stdio.h>

int Moore(int arr[], int sz)
{
	int major;//第一次进入，第一个元素与第一个元素比较，cnt++
	int cnt = 0;
	for (int i = 0; i < sz; i++)
	{
		if (cnt == 0)//若cnt为0，则给major重新赋值
		{
			major = arr[i];
		}
		if (major == arr[i])//两数相等，无法抵消
		{
			cnt++;
		}
		else//两数不等，进行抵消
		{
			cnt--;
		}
	}
	if (cnt == 0)//数组中的数全部一一抵消，说明这样的数不存在
	{
		return 0;
	}
	else//便利检验剩余的数(major)在数组中的出现次数
	{
		int count = 0;
		for (int i = 0; i < sz; i++)
		{
			if (major == arr[i])
			{
				count++;
			}
		}
		return count > sz / 2 ? major : 0;
	}
}

int main()
{
	int arr[] = { 1,2,1,3,1,1,2,1,5 };
	//int arr[] = { 1,1,2,2,3,3,4,4,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = Moore(arr, sz);
	printf("%d\n", ret);
	return 0;
}