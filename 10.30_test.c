#define _CRT_SECURE_NO_WARNINGS 1

//9*9乘法口诀表

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		int tmp = rand() % 3;
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//自定义函数交换两个整数

//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//	int a = 6;
//	int b = 8;
//	printf("交换前:a=%d,b=%d\n", a, b);
//	swap(&a, &b);
//	printf("交换后:a=%d,b=%d\n", a, b);
//	return 0;
//}

//判断闰年

//int is_leap(int y)
//{
//	if (((y%4==0)&&(y%100!=0))||(y%400==0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int y;
//	while (printf("请输入一个年份:>"),scanf("%d", &y) != EOF)
//	{
//		int ret = is_leap(y);
//		if (ret == 1)
//		{
//			printf("是闰年\n");
//		}
//		else
//		{
//			printf("不是闰年\n");
//		}
//	}
//	return 0;
//}

//打印素数

//int is_prime(int x)
//{
//	for (int i = 2; i <= sqrt(x); i++)
//	{
//		if (x%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	for (int i = 101; i <= 199; i+=2)
//	{
//		int ret = is_prime(i);
//		if (ret == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//void Plus(int x, int y,int arr[2])
//{
//	x += 1;
//	y += 1;
//	arr[0] = x;
//	arr[1] = y;
//}
//
//int main()
//{
//	int a = 3, b = 4;
//	int arr[2];
//	Plus(a, b, arr);
//	printf("%d %d\n", arr[0], arr[1]);
//	return 0;
//}

//生成100个1到100之间的随机数
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int count = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		printf("%-2d ", rand() % 100 + 1);
//		count++;
//		if (count==10)
//		{
//			printf("\n");
//			count = 0;
//		}
//	}
//	return 0;
//}


/*
指针笔试题
*/

//笔试题一
//int main()
//{
//    int a[5] = { 1, 2, 3, 4, 5 };
//    int* ptr = (int*)(&a + 1);
//    printf("%d,%d", *(a + 1), *(ptr - 1));// 2,5
//    return 0;
//}
////程序的结果是什么？


//笔试题二
//由于还没学习结构体，这里告知结构体的大小是20个字节
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}* p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);// 0x00100014 p表示结构体的地址，+1表示结构体加1的地址
//	printf("%p\n", (unsigned long)p + 0x1);//0x00100001 
//	printf("%p\n", (unsigned int*)p + 0x1);//0x00100004 将p转化为无符号整型指针，+1即加上四个字节
//	return 0;
//}
/*
考察的是指针+1的效果
指针+1的效果取决于指针类型
*/


//笔试题三
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);//
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//0x04  0x02
//	return 0;
//	/*
//	ptr[-1] == *(ptr-1)
//	*/
//}

//笔试题四
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//逗号表达式，结果为最后的部分
//	int* p;
//	p = a[0];//a[0]是第一行的数组名，在这里表示第一行第一个元素的地址
//	printf("%d", p[0]);// 0 p[0]=*(p+0)
//	return 0;
//}


//笔试题五（注意）
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//0xFF FF FF FC,-4
//	// 10000000 00000000 00000000 00000100
//	// 11111111 11111111 11111111 11111011
//	// 11111111 11111111 11111111 11111100
//	// 1111 1111 1111 1111 1111 1111 1111 1100
//	//   F    F    F    F   F    F    F     C
//	// 0xFF FF FF FC
//	//-4以地址形式打印时直接打印补码
//	return 0;
//}

//笔试题六
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));// 10,5
//	return 0;
//}


//笔试题七
int main()
{
	char* a[] = { "work","at","alibaba" };// p(w) p(a) p(a2)
	char** pa = a;// char* * pa pa是a[]首元素的地址
	pa++;//表示第二个元素的地址
	printf("%s\n", *pa);// *pa表示第二个元素即 "at"的首元素的地址
	return 0;//at
}