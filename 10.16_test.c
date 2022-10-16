#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//enum Color
//{
//	Red,
//	Green,
//	Blue
//};
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	enum Color c1= Red;
//	printf("%d\n", c1);
//	printf("%d\n", Green);
//	
//	switch (n)
//	{
//	case 0:
//		printf("Red");
//		break;
//	case 1:
//		printf("Green");
//		break;
//	case 2:
//		printf("Blue");
//		break;
//	}
//	return 0;
//}

//枚举常量

#include<stdio.h>

enum COLOR
{
	red = 1,//枚举常量
	green,
	blue
};//定义枚举类型

//int main()
//{
//	enum COLOR color;//定义枚举变量
//	for ( color = 1; color <=3 ; color++)//在枚举元素有序连续的情况下，可以遍历枚举元素
//	{
//		printf("枚举元素:%d\n", color);
//	}
//
//	printf("chose your color (1.red 2.green 3.blue)\n >:");//枚举类型在选择语句中
//	scanf("%d", &color);//输入的格式要是整型
//	switch (color)
//	{
//	case red:
//		printf("your color is red\n");
//		break;
//	case green:
//		printf("your color is green\n");
//		break;
//	case blue:
//		printf("your color is blue\n");
//		break;
//	default:
//		printf("you haven't chosen your color\n");
//		break;
//	}
//	return 0;
//}

int main()//将整数转换为枚举
{
	enum COLOR color;
	int a = 2;
	enum COLOR color2;
	color2 = (enum color) a;//类型转换
	printf("%d", color2);
	return 0;
}