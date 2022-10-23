#define _CRT_SECURE_NO_WARNINGS 1

//输出箭形
/*
	*
  **
***
  **
	*
*/

#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int m = 0; m < n-i; m++)
		{
			printf("  ");
		}
		for (int n = 0; n <= i; n++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < n+1; i++)
	{
		printf("*");
	}
	printf("\n");
	for (int i = n; i > 0; i--)
	{
		for (int m = n-i; m >= 0 ; m--)
		{
			printf("  ");
		}
		for (int  n = i; n >0; n--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}


/*打印正斜形*/
//#include <stdio.h>
//
//int main()
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j=0; j < i; j++)
//            {
//                printf(" ");
//            }
//            printf("*");
//            printf("\n");
//        }
//    }
//    return 0;
//}

/*打印反斜形

   *
  *
 *
*

*/

//#include <stdio.h>
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    for (int i = n; i > 0; i--)
//    {
//        for (int j = i-1; j > 0; j--)
//        {
//            printf(" ");
//        }
//        printf("*\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int mark;
//    int count = 0;
//    int sum = 0;
//    while (scanf("%d", &mark) != EOF)
//    {
//
//        int max = 0;
//        int min = 101;
//        if (mark > max)
//        {
//            max = mark;
//        }
//        if (mark < min)
//        {
//            min = mark;
//        }
//        sum += mark;
//        count++;
//        if (count == 7)
//        {
//            float ret = (sum - max - min) / 5.0;
//            printf("%.2f", ret);
//            count = 0;
//            sum = 0;
//        }
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}