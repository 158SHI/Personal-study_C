#define _CRT_SECURE_NO_WARNINGS 1

/*

�滻�ո�
��Ŀ��ʵ��һ�����������ַ����е�ÿ���ո��滻��%20.
���磺���롰We are happy���������We%20are%20happy.

*/

//#include<stdio.h>
//#include<string.h>
//
//void Change1(char arr[])
//{
//	int n = strlen(arr);
//	int i = 0;
//	while (arr[i] != '\0')
//	{
//		if (arr[i] == ' ')
//		{
//			n += 2;//�������ո񣬳��ȼ�2
//			for (int j = n-1; j > i; j--)
//			{
//				arr[j] = arr[j - 2];//�Ӻ���ǰ�滻�������ƶ���
//			}
//			arr[i++] = '%';
//			arr[i++] = '2';
//			arr[i] = '0';
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//}
//
//void Change2(char arr[])
//{
//	int i = 0;
//	int len = 0, space = 0;
//	while (arr[i] != '\0')//�����ַ����ȺͿո񳤶�
//	{
//		len++;
//		if (arr[i] == ' ')
//		{
//			space++;
//		}
//		i++;
//	}
//	int p1 = len-1;//��ԭʼ���ȸ���p1
//	int p2 = len + 2 * space-1;//�Ѹı��ĳ��ȸ���p2
//	while (p1 >= 0)
//	{
//		if (arr[p1] == ' ')
//		{
//			arr[p2--] = '0';
//			arr[p2--] = '2';
//			arr[p2] = '%';
//		}
//		else
//		{
//			arr[p2--] = arr[p1];
//		}
//		p1--;
//	}
//	printf("%s\n", arr);
//}
//
//int main()
//{
//	char arr[50] = " We are very happy ";
//	printf("Before:%s\nAfter:\n", arr);
//	Change1(arr);
//	Change2(arr);
//	return 0;
//}

//���������������ӷ�
//#include<stdio.h>
//
//int Sum(int a, int b)
//{
//	int carry, sum;
//	while (b)
//	{
//		sum = a ^ b;//��λ���
//		carry = (a & b) << 1;//��λ
//		a = sum;
//		b = carry;//���ظ�����
//	}
//	return a;
//}
//
////������ӣ��Ȱ�λ��ӣ��ٽ�λ
////�ڶ������У���λ�����������㣬��λ��������������������һλ
//int main()
//{
//	int a = 3, b = 5;
//	int ret = Sum(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

////������̨��
//#include<stdio.h>
//
//int Jump(int n)
//{
//	if (n == 0 || n == 1)
//	{
//		return n;
//	}
//	else
//	{
//		return Jump(n - 1) + Jump(n - 2);
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)
//	{
//		int ret = Jump(n);
//		printf("%d\n", ret);
//	}
//	return 0;
//}

/*

~~����������̨��
һֱ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ж�����������

*/

/*
����˼·��
 ÿ��̨�׿��Կ���һ��ľ�壬����������ȥ��n��̨�׾���n��ľ�壬���һ��ľ�������ܵ����λ�ӣ� ������ڣ�
 ���� (n-1) ��ľ���������ѡ���Ƿ���ڣ���ÿ��ľ���д��ںͲ���������ѡ��(n-1) ��ľ�� ���� [2^(n-1)] ������������ֱ�ӵõ������

��ʵ������Ҫ�������Ϊ��0,1,2,4,8,16,����
*/
//#include<stdio.h>
//
//int Jump(int n)
//{
//	if (n==0 || n==1)
//	{
//		return n;
//	}
//	else
//	{
//		int num = 1;
//		for (int i = 1; i < n; i++)
//		{
//			num = num * 2;
//		}
//		return num;
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)
//	{
//		int ret = Jump(n);
//		printf("%d\n", ret);
//	}
//	return 0;
//}

//��n*n�˷���
#include<stdio.h>

void TEST(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", i, j, i * j);
		}
		printf("\n");
	}
}

int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		TEST(n);
	}
	return 0;
}