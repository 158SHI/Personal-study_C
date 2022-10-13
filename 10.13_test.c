#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	//printf("hello,bit\n");
//	//printf("%d\n", sizeof(char));//%d打印的是十进制整型
//	//printf("%d\n", sizeof(short));
//	//printf("%d\n", sizeof(int));
//	//printf("%d\n", sizeof(long));
//	//printf("%d\n", sizeof(long long));
//	//printf("%d\n", sizeof(float));
//	//printf("%d\n", sizeof(double));
//	char ch = 'w';
//	printf("%c\n", ch);
//	float a = 7.18f;
//	double pie = 3.14;
//	return 0;
//}

//局部变量和全局变量

//int a = 10;
//
//#include<stdio.h>
//int main()
//{
//	a = 1;
//	//全局变量和局部变量冲突时，局部变量优先
//	printf("%d\n", a);
//	return 0;
//}

//写一个代码求两个整数的和
#include<stdio.h>
int main()
{
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	scanf("%d%d", &num1, &num2);
	sum = num1 + num2;
	printf("sum = %d\n", sum);
	return 0;
}