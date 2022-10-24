#define _CRT_SECURE_NO_WARNINGS 1

//一维数组传参

#include<stdio.h>

//void test(int arr1)//用数组形式接收
//{
//	;
//}
//
//void test(int arr1[10])
//{
//	;
//}
//
//void test(int* arr1)//用指针接收
//{
//	;
//}
//
//void test2(int* arr2)//用数组接收
//{
//	;
//}
//
//void test2(int* arr2[5])
//{
//	;
//}
//
//void test2(int** arr[5])//用指针接收
//{
//	;
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4 };
//	test(arr1);
//	int* arr2[5];
//	test2(arr2);
//	return 0;
//}

//void test(int arr[3][5])//用数组接收
//{
//	;
//}
//
//void test(int arr[][5])//只能省略行，不能省略列
//{
//	;
//}
//
//void test(int(*p)[5])//用数组指针接收
//{
//	;
//}
//
////void test2(int(*p)[])
////{
////	;
////}
//
//int main()
//{
//	int arr[3][5];
//	test(arr);
//	//int arr2[] = { 1,2,3 };
//	//test2(&arr2);
//	return 0;
//}

//函数指针
int Add(int x, int y)
{
	return x + y;
}

void Print(char* str)
{
	printf("%s\n", str);
}

int main()
{
	int a = 10;
	int b = 20;
	printf("%d\n", Add(a, b));

	int(*p)(int, int) = &Add;//(*p)表示p是一个指针，（int，int）表明(*p)指向的是一个函数，函数的参数类型是int,(*p)前的int表明函数的返回类型
	int ret2 = (*p)(5, 9);
	printf("%d\n", ret2);

	void(*p2)(char*) = &Print;
	(*p2)("Hello,world!");//解引用调用函数

	return 0;
}