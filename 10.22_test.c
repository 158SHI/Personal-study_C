#define _CRT_SECURE_NO_WARNINGS 1



//简易计算器
/*#include <stdio.h>

int main()
{
    //输入字符串
    //判断运算符的合法性
    //进行运算，除 运算判断操作数2的合法性
    double a, b;
    char m;
    while (scanf("%lf%c%lf", &a, &m, &b) != EOF)
    {
        if (m == '+' || m == '-' || m == '*' || m == '/')//运算符合法
        {
            switch (m)
            {
            case '+':
            {
                printf("%.4f+%.4f=%.4f\n", a, b, a + b);
                break;
            }
            case '-':
            {
                printf("%.4f-%.4f=%.4f\n", a, b, a - b);
                break;
            }
            case '*':
            {
                printf("%.4f*%.4f=%.4f\n", a, b, a * b);
                break;
            }
            case '/':
            {
                if (b == 0.0)
                {
                    printf("Wrong!Division by zero!\n");
                }
                else
                {
                    printf("%.4f/%.4f=%.4f\n", a, b, a / b);
                }
                break;
            }
            }
        }
        else//运算符不合法
        {
            printf("Invalid operation!\n");
        }
    }
    return 0;
}*/


/*
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的带空格直角三角形图案。

输入描述：
多组输入，一个整数（2~20），表示直角三角形直角边的长度，即“*”的数量，也表示输出行数。

输出描述：
针对每行输入，输出用“*”组成的对应长度的直角三角形，每个“*”后面有一个空格。

示例1
输入：
5

输出：
        *
      * *
    * * *
  * * * *
* * * * *
*/

//#include <stdio.h>
//int main()
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i -1; j++)//打印空格
//            {
//                printf("  ");
//            }
//            for (int k = 0; k <= i; k++)//打印*
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

/*
金字塔

描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的金字塔图案。
输入描述：
多组输入，一个整数（2~20），表示金字塔边的长度，即“*”的数量，，也表示输出行数。
输出描述：
针对每行输入，输出用“*”组成的金字塔，每个“*”后面有一个空格。


输入：
4

输出：
   *
  * *
 * * *
* * * *
*/

//#include <stdio.h>
//int main()
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i - 1; j++)
//            {
//                printf(" ");
//            }
//            for (int k = 0; k <= i; k++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}


/*

* * * * *
  * * * *
    * * *
      * *
        *
*/
//#include <stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    for (int i = n; i > 0; i--)
//    {
//        //打印空格
//        for (int j = 0; j < n - i; j++)
//        {
//            printf("  ");
//        }
//        //打印*
//        for (int k = 0; k < i; k++)
//        {
//            printf("* ");
//        }
//        printf("\n");
//    }
//    return 0;
//}


/*
* * * * *
 * * * *
  * * *
   * *
    *
*/
//#include <stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    for (int i = n; i > 0; i--)
//    {
//        //打印空格
//        for (int j = 0; j < n - i; j++)
//        {
//            printf(" ");
//        }
//        //打印*
//        for (int k = 0; k < i; k++)
//        {
//            printf("* ");
//        }
//        printf("\n");
//    }
//    return 0;
//}


/*
     *
    * *
   * * *
  * * * *
 * * * * *
* * * * * *
 * * * * *
  * * * *
   * * *
    * *
     *
*/

//#include <stdio.h>
//int main()
//{
//    //打印n*n上金字塔
//    //打印一行n+1个*
//    //打印n*n下金字塔
//    int n;
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; i++)//打印上金字塔
//    {
//        for (int j = 0; j < n - i; j++)
//        {
//            printf(" ");
//        }
//        for (int k = 0; k <= i; k++)
//        {
//            printf("* ");
//        }
//        printf("\n");
//    }
//
//    for (int m = 0; m < n+1; m++)//打印一行
//    {
//        printf("* ");
//    }
//
//    printf("\n");
//
//    for (int i = n; i > 0; i--)//打印下金字塔
//    {
//        //打印空格
//        for (int j = 0; j <= n - i; j++)
//        {
//            printf(" ");
//        }
//        //打印*
//        for (int k = 0; k < i; k++)
//        {
//            printf("* ");
//        }
//        printf("\n");
//    }
//    return 0;
//}


/*

* * * * * *
* * * * *
* * * *
* * *
* *
*
* *
* * *
* * * *
* * * * *
* * * * * *

*/
#include <stdio.h>
int main()
{
    //打印倒梯
    //打印部分正梯
    int n;
    scanf("%d", &n);
    //打印倒梯(n+1)阶
    for (int i = n; i >= 0; i--)
    {
        int j;
        for ( j = i; j >= 0; j--)
        {
            printf("* ");
        }
        if (j<i)
        {
            printf("\n");
        }
    }
    //打印部分正梯
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}