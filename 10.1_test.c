#define _CRT_SECURE_NO_WARNINGS 1

/*

ȡʯ����Ϸ���������ģ�

Description
������ʯ�ӣ��������⣬���Բ�ͬ����Ϸ��ʼ������������ȡʯ�ӡ���Ϸ�涨��ÿ�������ֲ�ͬ��ȡ����һ�ǿ����������һ����ȡ��������ʯ�ӣ�
���ǿ�����������ͬʱȡ����ͬ������ʯ�ӡ�����ʯ��ȫ��ȡ����Ϊʤ�ߡ����ڸ�����ʼ������ʯ�ӵ���Ŀ������ֵ�����ȡ������˫������ȡ��õĲ��ԣ����������ʤ�߻��ǰ��ߡ�

Input
������������У���ʾ������ʯ�ӵĳ�ʼ���������ÿһ�а��������Ǹ�����a��b����ʾ����ʯ�ӵ���Ŀ��a��b��������1,000,000,000��

Output
�����ӦҲ�������У�ÿ�а���һ������1��0������������ʤ�ߣ���Ϊ1����֮����Ϊ0��

Sample Input
2 1
8 4
4 7

Sample Output
0
1
0

*/

//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int m, n;
//	while (scanf("%d %d",&m,&n) != EOF)
//	{
//		int tmp;
//		if (m > n)//����mΪ��С����
//		{
//			tmp = m;
//			m = n;
//			n = tmp;
//		}
//        int k = floor(((sqrt(5) + 1) / 2) * (n - m));
//		if (m == k)//������������ֱ���
//		{
//			printf("0\n");
//		}
//		else
//		{
//			printf("1\n");
//		}
//
//	}
//	return 0;
//}

/*

���ܵ�Լ��

Description
��ֻ������������ʶ�ˣ������ĵúܿ��ģ����Ǿ��ú��б�Ҫ��һ�档
���Ǻܸ��˵ط�������ס��ͬһ��γ�����ϣ���������Լ�����Գ�������ֱ������Ϊֹ��
�������ǳ���֮ǰ������һ������Ҫ�����飬��û��������Է���������Ҳû��Լ������ľ���λ�á�
���������Ƕ��Ǻ��ֹ۵ģ����Ǿ���ֻҪһֱ����ĳ����������ȥ�����������Է��ġ�
���ǳ�������ֻ������ͬһʱ������ͬһ���ϣ���Ȼ����Զ������������ġ�
Ϊ�˰�������ֻ�ֹ۵����ܣ��㱻Ҫ��дһ���������ж�����ֻ�����Ƿ��ܹ����棬����ʲôʱ�����档
���ǰ�����ֻ���ֱܷ��������A������B�����ҹ涨γ�����϶���0�ȴ�Ϊԭ�㣬�ɶ�����Ϊ�����򣬵�λ����1�ף�
�������Ǿ͵õ���һ����β��ӵ����ᡣ������A�ĳ�����������x������B�ĳ�����������y��
����Aһ������m�ף�����Bһ������n�ף���ֻ������һ�������ѵ�ʱ����ͬ��γ�����ܳ�L�ס�
����Ҫ������������˼����Ժ�Ż����档

Input
����ֻ����һ��5������x��y��m��n��L������x��y < 2000000000��0 < m��n < 2000000000��0 < L < 2100000000��

Output
�����������Ҫ����Ծ�����������Զ���������������һ��"Impossible"

Sample Input
1 2 3 4 5

Sample Output
4

*/

/*
-----------------------------------------------�������----------------------------------+
#include<stdio.h>
#include<math.h>

int main()
{
	int x, y, m, n, t, L;
	while (scanf("%d %d %d %d %d", &x, &y, &m, &n, &L) != EOF)
	{
		int L0 = fabs(x - y);
		if (m == n)
		{
			printf("Impossible\n");
		}
		else if (m > n)
		{
			t = L0 / (m - n);
			printf("%d\n", t);
		}
		else
		{
			t = L0 / (n - m);
			printf("%d\n", t);
		}
	}
	return 0;
}
--------------------------------------------------------------------�������------------------+
*/


#include<stdio.h>
int main()
{
	int x, y, m, n, L;
	while (scanf("%d %d %d %d %d", &x, &y, &m, &n, &L) != EOF)
	{
		int t = 0;
		if (m % L == n % L)
		{
			t = 0;
		}
		else
		{
			while (x != y)
			{
				x += m;
				if (x > L)//���x>L��˵��A������Ȧ��x%L������A������
				{
					x %= L;
				}
				y += n;
				if (y > L)
				{
					y %= L;
				}
				t++;//��һ��,t++
			}
		}
		if (t != 0)
		{
			printf("%d\n", t);
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}