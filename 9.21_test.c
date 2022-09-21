#define _CRT_SECURE_NO_WARNINGS 1


//输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。
//输入：输入数据有多组，每组占一行，有三个字符组成，之间无空格。
//输出：对于每组输入数据，输出一行，字符中间用一个空格分开。

//#include<stdio.h>
//#include<string.h>
//
//swap(char* x, char* y)
//{
//	char tmp;
//	tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//
//	char a, b, c, t;
//	while (scanf("%c%c%c",&a,&b,&c) != EOF)//EOF的值为-1，若输入不等于-1，则循环继续
//	{
//		
//		if (a > c)
//		{
//			swap(&a, &c);//交换
//		}
//		if (a > b)
//		{
//			swap(&a, &b);
//		}
//		if (b > c)
//		{
//			swap(&b, &c);
//		}
//		scanf("%c", &t);//接收回车键，避免回车被录入
//		printf("%c %c %c", a, b, c);
//		printf("\n");
//	}
//	return 0;
//}

//输入两点坐标（X1,Y1）,（X2,Y2）,计算并输出两点间的距离。
//输入数据有多组，每组占一行，由4个实数组成，分别表示x1,y1,x2,y2,数据之间用空格隔开。
//对于每组输入数据，输出一行，结果保留两位小数。
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int x1, y1, x2, y2;
//	while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF)
//	{
//		float ret = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));//计算距离
//		printf("%.2lf\n", ret);
//	}
//	return 0;
//}

//求实数的绝对值
//输入数据有多组，每组占一行，每行包含一个实数。
//对于每组输入数据，输出它的绝对值，要求每组数据输出一行，结果保留两位小数。
//#include<stdio.h>
//
//double F(double n)
//{
//	if (n >= 0)
//	{
//		return n;
//	}
//	else
//	{
//		return -n;
//	}
//}
//
//int main()
//{
//	double n;
//	while (scanf("%lf",&n) != EOF)
//	{
//		printf("%.2lf\n", F(n));
//	}
//	return 0;
//}

//计算球的体积
//#define PI 3.1415927
//#include<stdio.h>
//
//double Squ(double r)
//{
//	return (4.0/3) * PI * r * r * r;
//}
//
//int main()
//{
//	double r;
//	while (scanf("%lf",&r) != EOF)
//	{
//		double ret = Squ(r);
//		printf("%.3lf\n", ret);
//	}
//}


/*

输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下：
90~100为A;
80~89为B;
70~79为C;
60~69为D;
0~59为E;
输入数据有多组，每组占一行，由一个整数组成。
对于每组输入数据，输出一行。如果输入数据不在0~100范围内，请输出一行：“Score is error!”。

*/

#include<stdio.h>
int main()
{
	int input;
	while (scanf("%d",&input) != EOF)
	{
		if (input>0 && input <= 100)
		{
			if (input>=90 && input<= 100)
			{
				printf("A\n");
			}
			else if(input>=80 && input<=89)
			{
				printf("B\n");
			}
			else if (input >= 70 && input <= 79)
			{
				printf("C\n");
			}
			else if (input >= 60 && input <= 69)
			{
				printf("D\n");
			}
			else
			{
				printf("E\n");
			}
		}
		else
		{
			printf("Score is error!\n");
		}
	}
}