#define _CRT_SECURE_NO_WARNINGS 1

//��ש����
//һ�����˰�3��ש��һ��Ů�˰�2��ש������С����1��ש����Ҫn���˰�n��ש,һ�ΰ���
//���ж����ְᷨ
//#include<stdio.h>
//int main(void)
//{
//	int x, y, z = 0;
//	int count = 0;
//	int n = 0;
//	printf("������ n=");
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

//��λ������
#include<stdio.h>
int main(void)
{
	int a = 16;
	int a1 = a >> 1;//����һλ�ȼ��ڳ���2
	int b = -1;
	int b1 = b >> 1;//�������ڴ��д洢���ǲ���
	int c = 4;
	int c1 = c << 1;//����һλ�ȼ��ڳ���2
	printf("a1=%d b1=%d c1=%d\n", a1, b1,c1);
	return 0;
}