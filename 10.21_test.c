#define _CRT_SECURE_NO_WARNINGS 1

/*
成绩统计

描述
输入n科成绩（浮点数表示），统计其中的最高分，最低分以及平均分。

数据范围：1 \le n \le 100 \1≤n≤100  ， 成绩使用百分制且不可能出现负数
输入描述：
两行，

第1行，正整数n（1≤n≤100）

第2行，n科成绩（范围0.0~100.0），用空格分隔。
输出描述：
输出一行，三个浮点数，分别表示，最高分，最低分以及平均分（小数点后保留2位），用空格分隔。
示例1
输入：
5
99.5 100.0 22.0 60.0 88.5

输出：
100.00 22.00 74.00

*/

//#include <stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    float max = 0, min = 101;//设置一个较大的最小值和一个较小的最大值
//    float sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        float mark;
//        scanf("%f", &mark);
//        sum += mark;
//        if (mark > max)//没输入一次就重新选定一个最大值和最小值
//        {
//            max = mark;
//        }
//        if (mark < min)
//        {
//            min = mark;
//        }
//    }
//    printf("%.2f %.2f %.2f", max, min, sum / n);
//    return 0;
//}

/*
* 
KIKI和酸奶

描述
BoBo买了一箱酸奶，里面有n盒未打开的酸奶，KiKi喜欢喝酸奶，第一时间发现了酸奶。KiKi每h分钟能喝光一盒酸奶，并且KiKi在喝光一盒酸奶之前不会喝另一个，那么经过m分钟后还有多少盒未打开的酸奶？

输入描述：
多组输入，每组输入仅一行，包括n，h和m（均为整数）。输入数据保证m <= n * h。
输出描述：
针对每组输入，输出也仅一行，剩下的未打开的酸奶盒数。
示例1
输入：
8 5 16

输出：
4
*/

//#include <stdio.h>
//int main()
//{
//    int n, h, m;
//    while (scanf("%d %d %d", &n, &h, &m) != EOF)
//    {
//        int opened = m / h;
//        if (m % h > 0)
//        {
//            opened++;//余数大于0，已经被拆封
//        }
//        printf("%d\n", n - opened);
//    }
//    return 0;
//}

/*
* 变种水仙花数
* 
描述
变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，比如1461 可以拆分成（1和461）,（14和61）,（146和1),
如果所有拆分后的乘积之和等于自身，则是一个Lily Number。

例如：

655 = 6 * 55 + 65 * 5

1461 = 1*461 + 14*61 + 146*1

求出 5位数中的所有 Lily Number。

输入描述：
无
输出描述：
一行，5位数中的所有 Lily Number，每两个数之间间隔一个空格。
*/

//#include <stdio.h>
//int main()
//{
//    for (int i = 10000; i <= 99999; i++)//遍历所有5位数
//    {
//        int sum = 0;
//        for (int j = 10; j <= 10000; j *= 10)
//        {
//            sum += (i / j) * (i % j);//累加所有因子
//        }
//        if (sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}

/*
* 争夺前五名
* 
描述
期中考试开始了，大家都想取得好成绩，争夺前五名。从键盘输入 n 个学生成绩，输出每组排在前五高的成绩。

数据范围： 5 \le n \le 50 \5≤n≤50  ，成绩采取百分制并不会出现负数
输入描述：
两行，第一行输入一个整数，表示n个学生（>=5），第二行输入n个学生成绩（整数表示，范围0~100），用空格分隔。
输出描述：
一行，输出成绩最高的前五个，用空格分隔。
示例1
输入：
6
99 45 78 67 72 88
复制
输出：
99 88 78 72 67
*/

//#include <stdio.h>
//void Insert_sort(int arr[50])
//{
//    for (int i = 1; i < 50; i++)
//    {
//        int key = arr[i];
//        int j = i - 1;
//        while (j >= 0 && arr[j] < key)
//        {
//            arr[j + 1] = arr[j];
//            j--;
//        }
//        arr[j + 1] = key;
//    }
//}
//
//int main()
//{
//    int arr[50] = { 0 };
//    int n;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)//输入数据
//    {
//        scanf("%d", &arr[i]);
//    }
//    //排序
//    Insert_sort(arr);
//    for (int i = 0; i < 5; i++)//输出
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

/*
判断字母是元音还是辅音
*/

//#include <stdio.h>
//int main() {
//    char input;
//    while (scanf("%c", &input) != EOF)
//    {
//        char ch = getchar();
//        switch (input)
//        {
//        case 'A':
//        case 'a':
//        case 'E':
//        case 'e':
//        case 'I':
//        case 'i':
//        case 'O':
//        case 'o':
//        case 'U':
//        case 'u':
//            printf("Vowel\n");
//            break;
//        default:
//            printf("Consonant\n");
//            break;
//        }
//    }
//    return 0;
//}


//初识结构体
//#include<stdio.h>
//
//struct Person//结构体类型
//{
//	char name[10];//成员变量
//	int age;
//	char sex[5];
//	char number[20];
//};
//
//void Print(struct Person* p)
//{
//	printf("传址调用\n");
//	printf("name:%s\n", p->name);
//	printf("age:%d\n", p->age);
//	printf("sex:%s\n", p->sex);
//	printf("phone number:%s\n", p->number);
//}
//
//int main()
//{
//	struct Person p = { "无疫烦",18,"男","123451234" };//p是结构体变量
//	struct Person p2;
//	printf("name:%s\n", p.name);
//	printf("age:%d\n", p.age);
//	printf("sex:%s\n", p.sex);
//	printf("phone number:%s\n", p.number);
//	printf("-----------------------------------------\n");
//	Print(&p);
//	return 0;
//}

//#include<stdio.h>
//
//int func(int a)
//{
//    int b;
//    switch (a)
//    {
//    case 1: b = 30;
//    case 2: b = 20;
//    case 3: b = 16;
//    default: b = 0;
//    }
//    return b;
//}
//
//int main()
//{
//    printf("%d", func(1));//0
//    return 0;
//}

//写一个代码打印1-100之间所有3的倍数的数字
//#include<stdio.h>
//int main()
//{
//    for (int i = 1; i < 100; i++)//产生1到100之间的数字
//    {
//        if (i % 3 == 0)//是3的倍数
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}

/*
写代码将三个整数数按从大到小输出。

例如：

输入：2 3 1

输出：3 2 1
*/

//#include<stdio.h>
//
//void swap(int** x, int** y)
//{
//	int tmp = **x;
//	**x = **y;
//	**y = tmp;
//}
//
//void Resort(int* a, int* b, int* c)
//{
//	if (*a<*b)
//	{
//		swap(&a, &b);
//	}
//	if (*a<*c)
//	{
//		swap(&a, &c);
//	}
//	if(*b<*c)
//	{
//		swap(&b, &c);
//	}
//}
//
//int main()
//{
//	int a, b, c;
//	while (scanf("%d %d %d",&a,&b,&c) != EOF)
//	{
//		Resort(&a, &b, &c);
//		printf("%d %d %d\n", a, b, c);
//	}
//	return 0;
//}

//写一个代码：打印100~200之间的素数
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	for (int n = 100; n < 200; n++)//产生100到200之间的数
//	{
//		//判断素数
//		int i = 0;
//		for ( i = 2; i <= sqrt(n); i++)
//		{
//			if (n%i == 0)//不是素数
//			{
//				break;
//			}
//		}
//		if (i>sqrt(n))//筛选素数
//		{
//			printf("%d ", n);
//		}
//	}
//	return 0;
//}

//打印1000年到2000年之间的闰年
//#include<stdio.h>
//int main()
//{
//	for (int i = 1000; i <= 2000; i++)//产生1000到2000的年份
//	{
//		//判断闰年
//		if ((i%4==0 && i%100!=0) || (i%400==0))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

/*
给定两个数，求这两个数的最大公约数

例如：

输入：20 40

输出：20
*/

#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	while (a%b != 0)//辗转相除法
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	printf("%d\n", b);
	return 0;
}