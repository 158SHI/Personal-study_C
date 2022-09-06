#define _CRT_SECURE_NO_WARNINGS 1

//搬砖问题
//一个男人搬3块砖，一个女人搬2块砖，两个小孩搬1块砖，需要n个人搬n块砖,一次搬完
//共有多少种搬法
#include<stdio.h>
int main(void)
{
	int x, y, z = 0;
	int count = 0;
	int n = 0;
	printf("请输入 n=");
	scanf("%d", &n);
	for ( x = 0; x <= n/3; x++)
	{
		for ( y = 0; y <= n/2; y++)
		{
			for ( z = 0; z <= 2*n;z= z+2)
			{
				if (x+y+z==n && 3*x+2*y+z/2==n)
				{
					printf("men=%d women=%d kids=%d\n", x, y, z);
					count++;
				}
			}
		}
	}
	printf("count=%d\n", count);
	return 0;
}
