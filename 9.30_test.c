#define _CRT_SECURE_NO_WARNINGS 1

/*

ż�����

Problem Description
��һ������Ϊn(n<=100)�����У������ж���Ϊ��2��ʼ�ĵ�������ż��������Ҫ���㰴��˳��ÿm�������һ��ƽ��ֵ��
��������m��������ʵ��������ƽ��ֵ����������ƽ��ֵ���С�

Input
���������ж��飬ÿ��ռһ�У���������������n��m��n��m�ĺ�������������

Output
����ÿ���������ݣ����һ��ƽ��ֵ���У�ÿ�����ռһ�С�

Sample Input
3 2
4 2

Sample Output
3 6
3 7

*/

#include<stdio.h>
//int main()
//{
//	int m, n, s;
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		int k = 2;
//		int times = n / m;//����
//		int r = n % m;//����֮�����µ����ָ���
//		for (int i = 0; i < times; i++)//��ÿһ���ƽ��ֵ
//		{
//			s = 0;
//			for (int j = 0; j < m; j++, k += 2)
//			{
//				s += k;//��m��ĺ�
//			}
//			printf("%d ", s / m);//���ƽ��ֵ
//		}//k������
//		if (r != 0)//������r�����ֵ�ƽ��ֵ
//		{
//			s = 0;
//			for (int i = 0; i < r; i++, k += 2)
//			{
//				s += k;
//			}
//			printf("%d", s / r);
//		}
//		printf("\n");
//	}
//	return 0;
//}

int main()
{
	int n, m, s;
	while (scanf("%d %d",&n,&m) != EOF)
	{
		int k = 2;
		int times = n / m;//����
		int r = n % m;//�����ʣ��r����
		for (int i = 0; i < times; i++)
		{
			s = 0;
			for (int j = 0; j < m; j++, k += 2)
			{
				s += k;//��ÿһ�����
			}
			printf("%d ", s / m);//��ӡƽ��ֵ
		}
		if (r != 0)
		{
			s = 0;
			for (int j = 0; j < r; j++, k += 2)//�����µ�r�����������
			{
				s += k;
			}
			printf("%d", s / r);//���ʣ��r������ƽ��ֵ
		}
		printf("\n");
	}
	return 0;
}