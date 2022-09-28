#define _CRT_SECURE_NO_WARNINGS 1

/*

Problem Description
对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。

Input
输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。

Output
对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。

Sample Input
0 1
0 0

Sample Output
OK

*/
#include<stdio.h>

int Judge(int num)
{
	int i;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			//不是素数
			return 0;
			break;
		}
	}
	if (i >= num)
	{
		//是素数
		return 1;
	}
}

int main()
{
	int x, y;
	int count = 0;
	while (scanf("%d %d", &x, &y) != EOF)
	{
		if (x == 0 && y == 0)
		{
			continue;
		}
		else
		{
			int counts = y - x + 1;
			count = 0;
			for (int n = x; n <= y; n++)
			{
				int num = n * n + n + 41;
				//判断num是否为素数
				//是素数返回1，不是素数返回0
				int ret = Judge(num);
				if (ret == 1)
				{
					count++;
				}
			}
			if (count == counts)
			{
				printf("OK\n");
			}
			else
			{
				printf("Sorry\n");
			}
		}
	}
	return 0;
}