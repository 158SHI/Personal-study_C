#define _CRT_SECURE_NO_WARNINGS 1

//��ש����
//һ�����˰�3��ש��һ��Ů�˰�2��ש������С����1��ש����Ҫn���˰�n��ש,һ�ΰ���
//���ж����ְᷨ
#include<stdio.h>
int main(void)
{
	int x, y, z = 0;
	int count = 0;
	int n = 0;
	printf("������ n=");
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
