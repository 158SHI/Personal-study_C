#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include<stdio.h>

//改造冒泡排序模拟实现qsort函数

//int cmp_int(void* e1, void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//
//
//Swap(char* buf1, char* buf2, int width)
//{
//	for (int i = 0; i < width; i++)
//		
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//void Bubble_sort(void* base, int sz, int width, int(*cmp)(void* e1, void* e2))
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//				//Swap((char*)base, (char*)base, width);
//
//			}
//		}
//	}
//}
//
//
//struct Stu
//{
//	int age;
//	char name[10];
//	char sex[5];
//};
//
//cmp_Stu_name(void* e1,void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//
//int main()
//{
//	//进行整型数组排序
//	int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
//
//	//用冒泡排序进行姓名排序
//	struct Stu sarr[4] = { {18,"无疫烦","男"}, {20,"亚索","25"}, {28,"张三","男"}, {30,"李四","男"} };
//	Bubble_sort(sarr, 4, sizeof(sarr[0]), cmp_Stu_name);
//	return 0;
//}

/*
指针和数组笔试题解析
*/

int main()
{
	//一维数组
	/*int a[] = {1,2,3,4};
	printf("%d\n", sizeof(a));// 16 sizeof(a)计算的是整个数组的大小
	printf("%d\n", sizeof(a + 0));// 4/8 a表示首元素地址，a+0仍是首元素地址
	printf("%d\n", sizeof(*a));// 4 a表示首元素地址，*a表示首元素
	printf("%d\n", sizeof(a + 1));// 4/8 a表示首元素地址，a+1表示第二个元素的地址
	printf("%d\n", sizeof(a[1]));// 4 a[1]表示第二个元素
	printf("%d\n", sizeof(&a));// 4/8 &a取出的是a的地址，大小为4/8
	printf("%d\n", sizeof(*&a));// 16 &a取出的是a的地址，解引用后表示整个数组
	printf("%d\n", sizeof(&a + 1));// 4/8 &a取出的是整个数组的地址，+1仍表示一个地址
	printf("%d\n", sizeof(&a[0])); // 4/8 取出第一个元素的地址
	printf("%d\n", sizeof(&a[0] + 1)); // 4/8 第一个元素的地址＋1，表示第二个元素的地址*/
	/*
	数组名表示首元素地址
			两个例外：
					1.sizeof(数组名)，计算整个数组的大小，单位是字节
					2.&数组名，取出的是整个数组
	*/


	//字符数组
	/*
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));// 6 整个数组的大小
	printf("%d\n", sizeof(arr + 0));// 4/8 首元素地址加0，表示首元素地址
	printf("%d\n", sizeof(*arr));// 1 首元素地址解引用，表示第一个元素
	printf("%d\n", sizeof(arr[1]));// 1 第二个元素的大小
	printf("%d\n", sizeof(&arr));// 4/8 整个数组的地址
	printf("%d\n", sizeof(&arr + 1));// 4/8 数组的地址
	printf("%d\n", sizeof(&arr[0] + 1));// 4/8 第二个元素的地址


	printf("%d\n", strlen(arr));//随机值 该数组中不含'\0'，向后继续检测直到找到 \0
	printf("%d\n", strlen(arr + 0));// 随机值
	//printf("%d\n", strlen(*arr));// 错误
	//printf("%d\n", strlen(arr[1]));//错误
	printf("%d\n", strlen(&arr));// 随机值
	printf("%d\n", strlen(&arr + 1));//随机值减6
	printf("%d\n", strlen(&arr[0] + 1));//随机值减1
	*/

	/*
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//7 注意包含 \0
	printf("%d\n", sizeof(arr + 0));// 4/8 表示首元素的地址
	printf("%d\n", sizeof(*arr));// 1 解引用首元素地址，表示首元素的大小，大小是1
	printf("%d\n", sizeof(arr[1]));//1 计算第二个元素的大小
	printf("%d\n", sizeof(&arr));// 4/8 表示整个数组的地址的大小
	printf("%d\n", sizeof(&arr + 1));// 4/8
	printf("%d\n", sizeof(&arr[0] + 1));// 4/8 表示第二个元素的地址的大小

	printf("%d\n", strlen(arr));//6 从首元素地址开始计算字符串长度
	printf("%d\n", strlen(arr + 0));//6 从首元素地址开始计算字符串长度
	printf("%d\n", strlen(*arr));//错误,非法访问内存
	printf("%d\n", strlen(arr[1]));//错误，非法访问内存
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//随机值，从第一个数组后面开始计算
	printf("%d\n", strlen(&arr[0] + 1));//5 从第二个元素的地址开始计算
	*/

	char* p = "abcdef";
	printf("%d\n", sizeof(p));// 4/8 p中存的是首元素（a）的地址
	printf("%d\n", sizeof(p + 1));// 4/8 得到的是字符b的地址
	printf("%d\n", sizeof(*p));// 1 表示字符串的第一个字符
	printf("%d\n", sizeof(p[0]));// 1 p[0] == *(p+0)
	printf("%d\n", sizeof(&p));// 4/8 取出p的地址
	printf("%d\n", sizeof(&p + 1));// 4/8
	printf("%d\n", sizeof(&p[0] + 1));// 4/8 表示b的地址


	printf("%d\n", strlen(p));// 6 从a的地址开始向后数字符 
	printf("%d\n", strlen(p + 1));// 5 从b的地址开始向后数字符
	//printf("%d\n", strlen(*p));// error
	//printf("%d\n", strlen(p[0]));//error
	printf("%d\n", strlen(&p));// 随机值
	printf("%d\n", strlen(&p + 1));// 随机值
	printf("%d\n", strlen(&p[0] + 1));// 5 表示b的地址
}