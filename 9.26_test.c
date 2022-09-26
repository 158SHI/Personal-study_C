#define _CRT_SECURE_NO_WARNINGS 1

/*

�����еĺ�

Problem Description
���еĶ������£�
���еĵ�һ��Ϊn���Ժ����Ϊǰһ���ƽ�����������е�ǰm��ĺ͡�

Input
���������ж��飬ÿ��ռһ�У�����������n��n<10000����m(m<1000)��ɣ�n��m�ĺ�����ǰ������

Output
����ÿ���������ݣ���������еĺͣ�ÿ������ʵ��ռһ�У�Ҫ�󾫶ȱ���2λС����

Sample Input
81 4
2 2

Sample Output
94.73
3.41

*/

//#include<stdio.h>
//#include<math.h>

//int main()
//{
//	int m, i;
//	double n;
//	while (scanf("%lf %d", &n, &m) != EOF)
//	{
//		double ret = n;
//		for (i = 1; i < m; i++)
//		{
//			n = (double)sqrt(n);
//			ret += n;
//		}
//		printf("%.2lf\n", ret);
//	}
//	return 0;
//}

//pow�������
//int main()//����ʱ��ϳ�
//{
//	int m, i;
//	double n;
//	while (scanf("%lf %d", &n, &m) != EOF)
//	{
//		double ret = 0;
//		for (i = 2; i <= pow(2,m); i *= 2)
//		{
//			ret += pow(n, 2.0 / i);
//		}
//		printf("%.2lf\n", ret);
//	}
//	return 0;
//}

/*

����ʽ���

Problem Description
����ʽ���������£�
1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
������������ö���ʽ��ǰn��ĺ͡�

Input
����������2����ɣ�������һ��������m��m<100������ʾ����ʵ���ĸ������ڶ��а���m��������������ÿһ������(������Ϊn,n<1000������ö���ʽ��ǰn��ĺ͡�

Output
����ÿ������ʵ��n��Ҫ���������ʽǰn��ĺ͡�ÿ������ʵ�������ռһ�У��������2λС����

Sample Input
2
1 2

Sample Output
1.00
0.50

*/

#include<stdio.h>
int main()
{
	int n, i, j;
	int a[100] = { 0 };
	double s, t;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);//�������ֵ����a[100]
		}
		for (i = 0; i < n; i++)//ִ��n��
		{
			t = 1.0;
			s = 0;
			for (j = 1; j <= a[i]; j++)
			{
				s += (t * (1.0 / j));
				t = -t;
			}//���
			printf("%.2lf\n", s);//��ӡ
		}
	}
	return 0;
}

//��ǰn��1-1/2+1/3֮��
//#include<stdio.h>
//int main()
//{
//	int n, i;
//	double ret = 0;
//	int sign = 1;
//	scanf("%d", &n);
//	for ( i = 1; i <= n; i++)
//	{
//		ret = ret + sign * (1.0 / i);
//		sign = -sign;
//	}//����ǰn���
//	printf("%lf", ret);
//	return 0;
//}

