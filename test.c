#define _CRT_SECURE_NO_WARNINGS 1

//搬砖问题
//一个男人搬3块砖，一个女人搬2块砖，两个小孩搬1块砖，需要n个人搬n块砖,一次搬完
//共有多少种搬法
//#include<stdio.h>
//int main(void)
//{
//	int x, y, z = 0;
//	int count = 0;
//	int n = 0;
//	printf("请输入 n=");
//	scanf("%d", &n);
//	for ( x = 0; x <= n/3; x++)
//	{
//		for ( y = 0; y <= n/2; y++)
//		{
//			for ( z = 0; z <= 2*n;z= z+2)
//			{
//				if (x+y+z==n && 3*x+2*y+z/2==n)
//				{
//					printf("men=%d women=%d kids=%d\n", x, y, z);
//					count++;
//				}
//			}
//		}
//	}
//	printf("count=%d\n", count);
//	return 0;
//}

//移位操作符
#include<stdio.h>
int main(void)
{
	int a = 16;
	int a1 = a >> 1;//右移一位等价于除以2
	int b = -1;
	int b1 = b >> 1;//整形在内存中存储的是补码
	int c = 4;
	int c1 = c << 1;//左移一位等价于乘以2
	printf("a1=%d b1=%d c1=%d\n", a1, b1,c1);
	return 0;
}