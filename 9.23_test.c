#define _CRT_SECURE_NO_WARNINGS 1

/*

�������ĳ˻�

Problem Description
����n�������������������������ĳ˻���

Input
�������ݰ����������ʵ����ÿ������ʵ��ռһ�У�ÿ�еĵ�һ����Ϊn����ʾ��������һ����n����������n������������Լ���ÿ�����ݱض����ٴ���һ��������

Output
���ÿ�����е����������ĳ˻������ڲ���ʵ�������һ�С�

Sample Input
3 1 2 3
4 2 3 4 5

Sample Output
3
15

*/

//#include<stdio.h>
//int main()
//{
//	int num, i, n = 1, ret;
//	while (scanf("%d",&n) != EOF)
//	{
//		ret = 1;//��ret���³�ʼ��Ϊ1
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &num);
//			if (num % 2 != 0)
//			{
//				ret *= num;
//			}
//		}
//		printf("%d\n", ret);
//	}
//	return 0;
//}

/*

ƽ������������

Problem Description
����һ���������������������������ż����ƽ�����Լ����������������͡�

Input
�������ݰ����������ʵ����ÿ�����ʵ������һ�У�����������m��n��ɡ�

Output
����ÿ���������ݣ����һ�У�Ӧ������������x��y���ֱ��ʾ�ö�����������������ż����ƽ�����Լ����������������͡�
�������Ϊ32λ�������Ա�������

Sample Input
1 3
2 5

Sample Output
4 28
20 152

*/

//#include<stdio.h>
//int main()
//{
//	int m, n, i;
//	int x = 0;
//	int y = 0;
//	while (scanf("%d %d",&m,&n) != EOF)
//	{
//		x = 0;
//		y = 0;
//		for ( i = m; i <= n; i++)//�õ�m��n
//		{
//			//�ж���ż
//			if (i%2 == 0)
//			{
//				//ż
//				x = x + i * i;
//			}
//			else
//			{
//				//��
//				y = y + i * i * i;
//			}
//		}
//		printf("%d %d\n", x, y);
//	}
//	return 0;
//}

/*

��ֵͳ��

Problem Description
ͳ�Ƹ�����n�����У���������������ĸ�����

Input
���������ж��飬ÿ��ռһ�У�ÿ�еĵ�һ����������n��n<100������ʾ��Ҫͳ�Ƶ���ֵ�ĸ�����Ȼ����n��ʵ�������n=0�����ʾ������������в�������

Output
����ÿ���������ݣ����һ��a,b��c���ֱ��ʾ�����������и�������������ĸ�����

Sample Input
6 0 1 2 3 -1 0
5 1 2 3 4 0.5
0

Sample Output
1 2 3
0 0 5

*/

#include<stdio.h>
int main()
{
	int n, i;
	double num;
	while (scanf("%d",&n) != EOF)
	{
		if (n == 0)//����nΪ0����������
		{
			continue;
		}
		else
		{
			int count0 = 0;
			int count_z = 0;
			int count_f = 0;
			for (i = 0; i < n; i++)
			{
				scanf("%lf", &num);
				if (num == 0)
				{
					//Ϊ0
					count0++;
				}
				else if (num > 0)
				{
					//����
					count_z++;
				}
				else
				{
					//����
					count_f++;
				}
			}
			printf("%d %d %d\n", count_f, count0, count_z);
		}
	}
	return 0;
}