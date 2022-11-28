#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//struct data
//{
//	unsigned int a : 7;//位段a,占7个字节
//	int b : 3;//位段b,占3个字节
//	char c : 4;
//	int : 0;//占0个字节的无名位段
//};
//
//int main()
//{
//	struct data d = { 0 };
//	return 0;
//}

//struct data
//{
//	char a : 4;
//	char b : 3;
//	char c : 7;
//	char d : 5;
//};

//struct data
//{
//	char a;
//	char b;
//	char c;
//	char d;
//};
//
//int main()
//{
//	struct data d = { 0 };
//	d.a = 10;
//	d.b = 12;
//	d.c = 3;
//	d.d = 4;
//	printf("%d\n", sizeof(d));
//	return 0;
//}

//enum COLOR
//{
//	RED,
//	GREEN = 2,
//	BLUE
//};
//
//int main()
//{
//	printf("%d\n", RED);
//	printf("%d\n", BLUE);
//	return 0;
//}

//union U
//{
//	char c;
//	int d;
//};
//
//int main()
//{
//	union U u = { 0 };
//	u.c = 3;
//	u.d = 7;
//	printf("%d\n", sizeof(u));//4
//	return 0;
//}

//union U
//{
//    char s[9];//9
//    int n;//4
//    double d;//8
//};
//
//int main()
//{
//    union U u = { 0 };
//    printf("%d\n", sizeof(u));
//    return 0;
//}

//union Data
//{
//	int i;
//	float f;
//	char  str[20];
//};
//
//int main()
//{
//	union Data data;
//
//	data.i = 10;
//	data.f = 220.5;
//	strcpy(data.str, "C Programming");//连续使用联合体成员会发生内存占用情况
//
//	printf("data.i : %d\n", data.i);
//	printf("data.f : %f\n", data.f);
//	printf("data.str : %s\n", data.str);
//
//	return 0;
//}

//判断机器的存储模式

//union U
//{
//	char c;
//	int d;
//};
//
//int main()
//{
//	union U u = { 0 };
//	u.d = 1;
//	if (u.c == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//#define PI 3.14
//
//int main()
//{
//    int a = 0, b = 0;
//    int r = 0;
//    int x = 0;
//    scanf("%d %d", &a, &b);
//    scanf("%d", &r);
//    scanf("%d", &x);
//
//    double sc = PI * r * r;
//
//
//    printf("%d\n", a * b);
//
//    int f = (sc - (int)sc) * 100;//得到小数部分的数字
//    if (f == 0)//sc是整数
//    {
//        printf("%d\n", (int)sc);
//    }
//    else if (f % 10 == 0)//sc含一位小数
//    {
//        printf("%.1lf\n", sc);
//    }
//    else//sc含两位小数
//    {
//        printf("%.2lf\n", sc);
//    }
//
//    printf("%d\n", x * x);
//    return 0;
//}

//打印X型图案
/*
将X型看做两部分：正斜形和反斜形
*/

//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				/*
//				对于正斜形，i == j的位置是'*'
//				对于反斜形，当i+j==n-1时的位置是'*'
//				*/
//				if (i == j || i + j == n - 1)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//空心正方形

//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
//				{
//					printf("* ");
//				}
//				else
//				{
//					printf("  ");//两个空格
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//空心三角形

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (j==0 || i==n-1 || i==j)
//			{
//				printf("* ");
//			}
//			else
//			{
//				printf("  ");//两个空格
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*
总结：
空心图形的打印，找到'*'的位置坐标的规律，利用分支语句进行控制
*/

//预定义符号
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	FILE* pf = fopen("log.txt", "w");
//	for ( i = 0; i < 10; i++)
//	{
//		arr[i] = i + 1;
//		printf("%d ", arr[i]);
//		fprintf(pf, "file:%s line:%d date:%s time:%s data:%d\n",
//			__FILE__, __LINE__, __DATE__, __TIME__, arr[i]);
//	}
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}


//预处理指令

//#define MAX 100
//#define STR "HELLO,WORLD!"
//#define DO_FOREVER for(;;)
//#define I int