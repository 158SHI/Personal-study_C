#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//    int c = 1;//用于控制最后的尾巴（数柄）；
//    int n = 0;//层数
//    scanf("%d", &n);
//    int d = 3 * n;//a和d用于控制最开始的空白数；
//    for (int i = 1; i <= n; i++)
//    {
//        for (int a = d - 1; a > 0; a--)//
//        {
//            printf(" ");
//        }
//        for (int k = 1; k <= i; k++)//k代表一行打印多少个“*     ”
//        {
//            printf("*     ");//把第一层当作“*     ”来打印
//        }
//        printf("\n");
//        for (int a = d - 2; a > 0; a--)//同上
//        {
//            printf(" ");
//        }
//        for (int k = 1; k <= i; k++)
//        {
//            printf("* *   ");
//        }
//        printf("\n");
//        for (int a = d - 3; a > 0; a--)//同上
//        {
//            printf(" ");
//        }
//        for (int k = 1; k <= i; k++)
//        {
//            printf("* * * ");
//        }
//        printf("\n");
//        d = d - 3;
//    }
//    while (c <= n)
//    {
//        for (int i = 0; i < 3*n-1; i++)
//        {
//            printf(" ");
//        }
//        printf("*\n");
//        c++;
//    }
//    return 0;
//}

/*
描述
牛牛准备继续进阶，计算更难的数列
输入一个整数n,计算 1+1/（1-3）+1/（1-3+5）+...+1/(1-3+5-...((-1)^(n-1))*(2n-1))的值
输入描述：
输入一个整数
输出描述：
输出一个浮点数，保留3位小数
*/

//double operation(int n)
//{
//	double sum = 0.0;
//	int flag = 1;
//	for (int i = 1; i <= 2 * n - 1; i += 2)
//	{
//		sum += flag * i;
//		flag = -flag;
//	}
//	sum = 1.0 / sum;
//	return sum;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	double sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		double ret = operation(i);//计算第i个对应的数
//		sum += ret;//累加
//	}
//	printf("%.3f\n", sum);
//	return 0;
//}

/*
描述
帮助牛牛计算 1+（1+2）+（1+2+3）+...+(1+2+3+...+n)
输入描述：
输入一个整数
输出描述：
输出一个整数
*/

//int operation(int n)
//{
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += i;
//	}
//	return sum;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int ret = operation(i);
//		sum += ret;
//	}
//	printf("%d\n", sum);
//}

/*
描述
求一个整数的所有数位之和
输入描述：
输入一行，包含一个整数。
输出描述：
一个整数. int范围内
*/

//递归
//int Sum(int n)
//{
//	if (n<9)
//	{
//		return n;
//	}
//	else
//	{
//		return n % 10 + Sum(n / 10);
//	}
//}

//循环
//int Sum(int n)
//{
//	int sum = 0;
//	while (n>9)
//	{
//		sum += n % 10;
//		n /= 10;
//	}
//	sum += n;
//	return sum;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Sum(n);
//	printf("%d\n", ret);
//	return 0;
//}

/*
有一个数字魔法，给你一个正整数n，如果n为偶数，就将他变为n/2, 如果n为奇数，就将他变为乘3加1
不断重复这样的运算，经过有限步之后，一定可以得到1
牛牛为了验证这个魔法，决定用一个整数来计算几步能变成1

输入描述：
输入一个正整数n,范围在100以内
输出描述：
输出一个整数
*/

//int operation(int n)
//{
//	//是偶数 -> n/2
//	//是奇数 -> n*3+1
//	int count = 0;
//	while (n != 1)
//	{
//		if (n % 2 == 0)
//		{
//			n /= 2;
//		}
//		else
//		{
//			n = n * 3 + 1;
//		}
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);// 0<n<=100
//	int ret = operation(n);
//	printf("%d\n", ret);
//	return 0;
//}

/*
描述
今年是2019年，KiKi想知道1~2019中有多少个包含数字9的数。包含数字的数是指有某一位是“9”的数，例如“2019”、“199”等。
*/

//int judge(int n)
//{
//	while (n)
//	{
//		int tmp = n % 10;
//		n /= 10;
//		if (tmp == 9)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 2019; i++)
//	{
//		if (judge(i))
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

/*
描述
小乐乐的班主任想统计一下班级里一共有多少人需要被请家长，三个成绩（语文，数学，外语）平均分低于60的将被请家长，小乐乐想编程帮助班主任算一下有多少同学被叫家长。
输入描述：
共n+1行
第一行，输入一个数n，代表小乐乐的班级中有n个同学。
在接下来的n行中每行输入三个整数代表班级中一个同学的三科成绩（语文，数学，外语），用空格分隔。
输出描述：
一行，一个整数，代表班级中需要被请家长的人数。
*/

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int mark[3] = { 0 };
//	int count = 0;
//	for (int i = 0; i < n; i++)//进行n次计算和判断
//	{
//		for (int i = 0; i < 3; i++)//输入成绩
//		{
//			scanf("%d", &mark[i]);
//		}
//		//判断
//		double aver_mark = (mark[0] + mark[1] + mark[2]) / 3.0;
//		if (aver_mark<60.0)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//}

/*
水仙花数
多组输入
*/

//int flower(int n)
//{
//	int sum = 0;
//	int start = n;
//	while (n)
//	{
//		int tmp = n % 10;
//		sum += tmp * tmp * tmp;
//		n /= 10;
//	}
//	if (sum == start)
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
//	int m, n;
//	while (scanf("%d %d", &m, &n) != EOF)
//	{
//		int flag = 0;
//		for (int i = m; i <= n; i++)
//		{
//			if (flower(i))
//			{
//				printf("%d ", i);
//				flag = 1;
//			}
//		}
//		//printf("\n");
//		if (flag == 0)
//		{
//			printf("no\n");
//		}
//	}
//	return 0;
//}

/*
小乐乐在课上学习了二进制八进制与十六进制后，对进制转换产生了浓厚的兴趣。
因为他的幸运数字是6，所以他想知道一个数表示为六进制后的结果。请你帮助他解决这个问题。

输入描述：
输入一个正整数n  (1 ≤ n ≤ 109)

输出描述：
输出一行，为正整数n表示为六进制的结果
*/

//void trans(int n)
//{
//	if (n>1)
//	{
//		trans(n / 2);
//	}
//	printf("%d", n % 2);
//}

//void trans(int n)
//{
//	if (n>5)
//	{
//		trans(n / 6);
//	}
//	printf("%d", n % 6);
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	trans(n);
//	return 0;
//}

/*
描述
国王将金币作为工资，发放给忠诚的骑士。第一天，骑士收到一枚金币；之后两天（第二天和第三天），每天收到两枚金币；
之后三天（第四、五、六天），每天收到三枚金币；
之后四天（第七、八、九、十天），每天收到四枚金币……；
这种工资发放模式会一直这样延续下去：当连续N天每天收到N枚金币后，
骑士会在之后的连续N+1天里，每天收到N+1枚金币。

请计算在前K天里，骑士一共获得了多少金币。
输入描述：
输入只有1行，包含一个正整数K，表示发放金币的天数。
输出描述：
输出只有1行，包含一个正整数，即骑士收到的金币数。
*/

//int main()
//{
//	int k = 0;
//	scanf("%d", &k);
//
//	int sum = 0;
//	int tmp = k;
//	for (int i = 1; i <= tmp; i++)
//	{
//			for (int j = 1; (j <= i)&&(k>0); j++)
//			{
//				sum += i;
//				k--;
//			}
//			if (k == 0)
//			{
//				break;
//			}
//	}
//	printf("%d\n", sum);
//	return 0;
//}

int main()
{
    int data = 0;
    int sum = 0;
    int k = 0;
    scanf("%d", &data);
    for (int i = 1; k < data; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (k >= data)
            {
                break;
            }
            sum += i;
            k++;
        }
    }
    printf("%d\n", sum);
    return 0;
}