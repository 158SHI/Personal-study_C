#define _CRT_SECURE_NO_WARNINGS 1

/*

��Ҽ�

Problem Description
ϲ�����μǵ�ͬѧ�϶���֪�����͵����ҵĹ��£�����һ�������������̫�����ˣ���ʵ������������֪����������о�һ����ѧ���⣡
ʲô���⣿���о������������һ���ж��ٸ���
�����������������û�ܽ��������⣬�Ǻ�^-^
��ʱ������������ģ�
��һ����ճԵ���������һ���һ�����ڶ����ֽ�ʣ�µ����ӳԵ�һ���һ�����Ժ�ÿ��Ե�ǰһ��ʣ�µ�һ���һ����
����n��׼���Ե�ʱ��ֻʣ��һ�����ӡ��������㣬��������һ�£�����һ�쿪ʼ�Ե�ʱ������һ���ж��ٸ��أ�

Input
���������ж��飬ÿ��ռһ�У�����һ��������n��1<n<30������ʾֻʣ��һ�����ӵ�ʱ�����ڵ�n�췢���ġ�

Output
����ÿ���������ݣ������һ�쿪ʼ�Ե�ʱ�����ӵ�������ÿ������ʵ��ռһ�С�

Sample Input
2
4

Sample Output
4
22

*/

//��������
//#include<stdio.h>
//int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)
//	{
//		int sum = 1;
//		for (int i = 1; i < n; i++)
//		{
//			sum = (sum + 1) * 2;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

//�ݹ�
//#include<stdio.h>
//
//int F(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return (F(n - 1) + 1) * 2;
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)//�������
//	{
//		printf("%d\n", F(n));
//	}
//	return 0;
//}


/*

������ִ���_��ί����

Problem Description
������ִ����У���ί�������ѡ�ִ�֡�ѡ�ֵ÷ֹ���Ϊȥ��һ����߷ֺ�һ����ͷ֣�Ȼ�����ƽ���÷֣��������ĳѡ�ֵĵ÷֡�

Input
���������ж��飬ÿ��ռһ�У�ÿ�еĵ�һ������n(2<n<=100)����ʾ��ί��������Ȼ����n����ί�Ĵ�֡�

Output
����ÿ���������ݣ����ѡ�ֵĵ÷֣��������2λС����ÿ�����ռһ�С�

Sample Input
3 99 98 97
4 100 99 98 97

Sample Output
98.00
98.50

*/

//#include<stdio.h>
//
//int F_MAX(int arr[100], int n)
//{
//	int j = 0;
//	int max = arr[j];
//	for (int  i = 1; i < n; i++)
//	{
//		if (arr[i] > arr[j])
//		{
//			j = i;//������ֵ
//		}
//	}
//	return arr[j];
//}
//
//int F_MIN(int arr[100], int n)
//{
//	int j = 0;
//	int min = arr[j];
//	for (int i = 1; i < n; i++)
//	{
//		if (arr[i] < arr[j])
//		{
//			j = i;//�����Сֵ
//		}
//	}
//	return arr[j];
//}
//
//double AVE(int max, int min, int arr[100],int n)
//{
//	double sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum = sum + arr[i];
//	}
//	sum = sum - max - min;//��ȥһ����Сֵ��һ�����ֵ
//	return sum / (n - 2);
//}
//
//int main()
//{
//	int n;
//	int arr[100] = { 0 };//���ѡ�ַ���������
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &arr[i]);//�������
//		}
//		double max = F_MAX(arr, n);//�ҳ����ֵ
//		double min = F_MIN(arr, n);//�ҳ���Сֵ
//		double ret = AVE(max, min, arr, n);//��ƽ��ֵ
//		printf("%.2lf\n", ret);
//	}
//	return 0;
//}

/*

ż�����

Problem Description
��һ������Ϊn(n<=100)�����У������ж���Ϊ��2��ʼ�ĵ�������ż��������Ҫ���㰴��˳��ÿm�������һ��ƽ��ֵ����������m��������ʵ��������ƽ��ֵ����������ƽ��ֵ���С�

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