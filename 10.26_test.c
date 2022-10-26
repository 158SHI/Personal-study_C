#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//函数指针的调用

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	printf("%d\n", Add(1, 3));
//
//	int(*p)(int, int) = Add;
//
//	printf("%d\n", (*p)(1, 3));
//	printf("%d\n", (p)(1, 3));
//	printf("%d\n", (**p)(1, 3));
//	printf("%d\n", (****p)(1, 3));//函数指针在调用时 * 并无实际价值
//
//	return 0;
//}


//函数指针数组
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	//printf("%d\n", Add(1, 3));
//
//	int(*p)(int, int) = Add;//p首先与*结合，表明p是一个指针
//
//	int(*parr[4])(int, int) = { Add,Sub,Mul,Div };
//	//p首先与 4[ ]结合，表明p是一个数组，该数组的元素类型为 int(*    )(int ,int)，即函数指针类型
//
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d\n", parr[i](8, 4));//12 4 32 2
//	}
// return 0;
//}


//函数指针数组的应用：转移表

//计算器

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void menu()
//{
//	printf("*********************\n");
//	printf("***1.Add     2.Sub***\n");
//	printf("***3.Mul     4.Div***\n");
//	printf("****** 0.exit ******\n");
//}

/*int main()
{
	int input = 0;
	int(*parr[5])(int, int) = { 0,Add,Sub,Mul,Div };//将参数表和返回值类型相同的函数放入 函数指针数组——转移表
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		if (input>=1 && input <=4)
		{
			int x, y;
			printf("请输入两个操作数>:");
			scanf("%d %d", &x, &y);
			int ret = parr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出\n");
		}
		else
		{
			printf("选择错误\n");
		}

	} while (input);
	return 0;
}*/


//回调函数  —— 用函数指针调用函数
//解决用switch出现冗余的问题  —— 回调函数

/*
void calu(int(*p)(int, int))//用函数指针接收函数
{
	printf("请输入两个操作数>:");
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n", p(x, y));//用函数指针调用对应函数
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			calu(Add);
			break;
		case 2:
			calu(Sub);
			break;
		case 3:
			calu(Mul);
			break;
		case 4:
			calu(Div);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}*/

//回调函数_2

//void Print(char* str)
//{
//	printf("%s", str);
//}
//
//void test(void(*p)(char*))
//{
//	printf("test:\n");
//	p("hehehehhe");//函数回调
//}
//
//int main()
//{
//	test(Print);
//	return 0;
//}


//冒泡排序

//void Bobble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)//sz-1趟排序
//	{
//		for (int j = 0; j < sz-1-i; j++)//1趟排序
//		{
//			if (arr[j]>arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,3,5,7,2,4,6,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bobble_sort(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//qsort函数

#include<stdlib.h>
//#include<search.h>

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
	//返回值：
	//e1>e2,返回值大于0
	//e1==e2,返回值等于0
	//e1<e2，返回值小于0
}

int cmp_float(const void* e1, const void* e2)
{
	return ((int)(*(int*)e1 - *(int*)e2));
}

int main()
{
	//整型元素的排序
	int arr1[] = { 1,3,5,7,9,2,4,6 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	qsort(arr1, sz, sizeof(arr1[0]),cmp_int);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");

	//浮点型元素的排序
	float arr2[] = { 8.5,3.4,2.1,1.6,6.7,5.3 };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	qsort(arr2, sz2, sizeof(arr2[0]), cmp_float);
	for (int i = 0; i < sz2; i++)
	{
		printf("%.2f ", arr2[i]);
	}

	
	return 0;
}

//int Add2(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int(*p)(int, int) = Add2;
//	printf("%d", (*p)(3, 5));
//	return 0;
//}