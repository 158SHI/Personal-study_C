#define _CRT_SECURE_NO_WARNINGS 1

////printf函数的返回值
//#include<stdio.h>
//int main()
//{
//	int ret = printf("Hello world!");//赋值的同时，执行printf函数
//	printf("\n%d", ret);//printf的返回值是所打印的字符的个数
//	/*
//	1.On success, the total number of characters written is returned.
//	2.If a writing error occurs, the error indicator (ferror) is set and a negative number is returned.
//	3.If a multibyte character encoding error occurs while writing wide characters, errno is set to EILSEQ and a negative number is returned.
//	*/
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char str[20];
//	scanf("%s", str);
//	printf("%s", str);
//	return 0;
//
//}

//#include <stdio.h>
//
//int main()
//{
//    float c, math, Eng;
//    char str[20];
//    scanf("%s %f %f %f", str, &c, &math, &Eng);
//    printf("The each subject score of No. %s is %.2f, %.2f, %.2f.\n", str, c, math, Eng);
//    return 0;
//}

//字符圣诞树
//#include <stdio.h>
//
//int main()
//{
//    char c;
//    scanf("%c", &c);
//    printf("    %c\n", c);
//    printf("   %c %c\n", c, c);
//    printf("  %c %c %c\n", c, c, c);
//    printf(" %c %c %c %c\n", c, c, c, c);
//    printf("%c %c %c %c %c\n", c, c, c, c, c);
//    return 0;
//}

//ASCII码
//#include <stdio.h>
//
//int main()
//{
//    printf("%c%c%c%c%c%c%c%c%c%c%c%c", 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33);
//    return 0;
//}

/*
描述
输入一个人的出生日期（包括年月日），将该生日中的年、月、日分别输出。

数据范围：年份满足 1990 \le y \le 2015 \1990≤y≤2015 ，月份满足 1 \le m \le 12 \1≤m≤12  ，日满足 1 \le d \le 30 \1≤d≤30
输入描述：
输入只有一行，出生日期，包括年月日，年月日之间的数字没有分隔符。
输出描述：
三行，第一行为出生年份，第二行为出生月份，第三行为出生日期。输出时如果月份或天数为1位数，需要在1位数前面补0。
示例1
输入：
20130225
复制
输出：
year=2013
month=02
date=25
*/

//#include <stdio.h>
//int main()
//{
//    int y, m, d;
//    scanf("%4d%2d%2d", &y, &m, &d);//截取
//    printf("year=%d\nmonth=%02d\ndate=%02d\n", y, m, d);//
//    return 0;
//}
//
///*
//通过scanf函数的 %m 格式控制可以指定输入域宽，输入数据域宽（列数），按此宽度截取所需数据；
//通过printf函数的 %0 格式控制符，输出数值时指定左面不使用的空位置自动填0。
//*/

#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            printf("%d\n", 1);
        }
        else
        {
            printf("%d\n", 2 << n);
        }
    }
    return 0;
}