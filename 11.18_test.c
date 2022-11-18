#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//面1
//void GetMemory(char* p)//p是str的一份临时拷贝！！！
//{
//	p = (char*)malloc(100);
//}//结束时，p销毁，开辟的空间未被free，且无法找到，造成内存泄漏
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");//str还是NULL，崩溃
//	printf(str);
//}
//
////1.程序崩溃
////2.内存泄漏
//
//int main()
//{
//	Test();
//	return 0;
//}

//修改1
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(20);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//修改2
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(20);
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//面2
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}//虽然返回了字符数组的地址，但该地址的空间被销毁
//
////char* GetMemory(void)
////{
////	char* p = "hello,world";//p指向一个常量字符串，常量字符串存储在静态区，所以不会被销毁
////	return p;
////}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//面3
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);//str =(char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");//正常输出hello,但是存在内存泄漏
//	printf(str);
//}

//面4
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");//非法访问内存，str指向的空间已被释放
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

/*
描述
输入n个整数的序列，要求对这个序列进行去重操作。所谓去重，是指对这个序列中每个重复出现的整数，只保留该数第一次出现的位置，删除其余位置。
输入描述：
输入包含两行，第一行包含一个正整数n（1 ≤ n ≤ 1000），表示第二行序列中数字的个数；第二行包含n个整数（范围1~5000），用空格分隔。

输出描述：
输出为一行，按照输入的顺序输出去重之后的数字，用空格分隔。
*/

//法1
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int arr[1000] = { 0 };
//	int i = 0;
//	for ( i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for ( i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = i+1; j < n-1; )
//		{
//			if (arr[j] == arr[i])
//			{
//				//执行去重操作
//				int key = j;
//				while (key<n-1)
//				{
//					arr[key] = arr[key + 1];
//					key++;
//				}
//				n--;
//			}
//			if (arr[j] != arr[i])
//			{
//				j++;
//			}
//		}
//	}
//
//	for ( i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//法2
//
//#include<stdbool.h>
//
//_Bool Judge(int* parr,int tmp,int count)
//{
//	_Bool flag = true;
//	for (int i = 0; i < count; i++)
//	{
//		if (parr[i] == tmp)
//		{
//			return false;
//		}
//	}
//	return flag;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int arr[1000] = { 0 };
//	int count = 0;
//	int tmp = 0;
//	int i = 0;
//	for ( i = 0; i < n; i++)
//	{
//		/*
//		输入一个数，若数组中不存在该数，则放入数组；
//		若存在该数，则不放入数组
//		*/
//		scanf("%d", &tmp);
//		_Bool ret = Judge(arr,tmp,count);
//		if (ret == true)//放入数组
//		{
//			arr[count++] = tmp;
//		}
//		else//不放入数组
//		{
//			continue;
//		}
//	}
//
//	for ( i = 0; i < count; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

#include <stdio.h>

int main()
{
    int n = 0;
    int m = 0;
    int max = 0;
    int tmp = 0;
    int a = 0;
    int b = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) 
        {
            scanf("%d", &tmp);
            if (tmp > max) 
            {
                max = tmp;
                a = i;
                b = j;
            }
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}