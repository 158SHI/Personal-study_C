#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

//��������ʱ������������������
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("before:a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("after:a=%d b=%d\n", a, b);
//	return 0;
//}


//дһ���������ز����������� 1 �ĸ�����

//int operation(int n)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (n & (1<<i))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = operation(n);
//	printf("%d\n", ret);
//	return 0;
//}

//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

//void Print(int n)
//{
//	for (int i = 30; i >=0; i-=2)//����λ
//	{
//		printf("%d", (n >> i)&1);
//	}
//	printf("\n");
//	for (int j = 31; j >0; j-=2)//ż��λ
//	{
//		printf("%d", (n >> j)&1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}

/*
���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��

��������:

1999 2299

�������:7
*/

//int differ(int m, int n)
//{
//	int tmp = m ^ n;
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (tmp & (1 << i))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int m, n;
//	scanf("%d %d", & m, &n);
//	int ret = differ(m, n);
//	printf("%d\n", ret);
//	return 0;
//}

/*
����
����ţţѧ���˻��Ĵ������������������һ��ģ����������������������Ŷ��뵹�Ŷ���һ������������1221��343�ǻ�������433���ǻ������������������n�Ļ�������
����������
����һ������n(1 <= n <= 100000)
���������
��1��ʼ����С�����˳��������л�����
*/

_Bool is_ret(int n)
{
	int t = 0;
	int tmp = n;

	while (n > 0)//�����ֵ���
	{
		t = t * 10 + n % 10;
		n = n / 10;
	}

	if (t == tmp)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (is_ret(i))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}