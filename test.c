#define _CRT_SECURE_NO_WARNINGS 1

//�ݹ�ͷǵݹ���n�Ľ׳�
//�ݹ�
//#include<stdio.h>
//
//int N(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * N(n - 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = N(n);
//	printf("%d", ret);
//	return 0;
//}

//�ǵݹ�
//#include<stdio.h>
//
//int N(int n)
//{
//	int i = 0;
//	int m = 1;
//	for ( i = 1; i <= n; i++)
//	{
//		m = m * i;
//	}
//	return m;
//}
//
//int main(void)
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = N(n);
//	printf("%d", ret);
//	return 0;
//}

//�ݹ�ͷǵݹ�ģ��ʵ��strlen����
//�ݹ�
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);
//	}
//}
//
//int main()
//{
//	char arr[] = "hello";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//�ǵݹ�
//������
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "hello";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//ָ������
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//
//int main()
//{
//	char arr[] = "hello";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//��ʹ�ÿ⺯�����õݹ�ķ�ʽ����һ���ַ����е�Ԫ��
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void Rserve_sort(char* arr, int len)
//{
//	int tmp = 0;
//	int left = 0;
//	int right = len - 1;
//	tmp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = '\0';
//	if (my_strlen(arr+1)>=2)
//	{
//		Rserve_sort(arr + 1,my_strlen(arr+1));
//	}
//	arr[right] = tmp;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	Rserve_sort(arr,len);
//	printf("%s", arr);
//	return 0;
//}

//��ƺ�����ӡ��һ���Ǹ�������ÿһλ
//#include<stdio.h>
//
//void Print(int n)
//{
//	if (n>9)
//	{
//		Print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int n = 0;
//	printf("������>:");
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}

//�����ݹ������һ���Ǹ�������ÿһλ�ĺ�
////1729
////DigitSum(172)+1729%10
////DigitSum(17)+172%10+1729%10
////DigitSum(1)+...
//#include<stdio.h>
//
//int DigitSum(int n)
//{
//	if (n>9)
//	{
//		return DigitSum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//
//int main()
//{
//	unsigned int n = 0;
//	scanf("%d", &n);
//	int ret = DigitSum(n);
//	printf("ret=%d\n", ret);
//}

//�����ݹ���n��k�η�
//#include<stdio.h>
//
//double Pow(int n, int k)
//{
//	if (k<0)
//	{
//		return (1.0 / Pow(n, -k));
//	}
//	else if (k == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * Pow(n, k - 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	double ret = Pow(n, k);
//	printf("ret=%lf\n", ret);
//	return 0;
//}

//�ݹ�ͷǵݹ����n��쳲�������
//�ݹ�
//#include<stdio.h>
//
//int Fib(int n)
//{
//	if (n<=2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("ret=%d\n", ret);
//	return 0;
//}

//�ǵݹ�
//#include<stdio.h>
//
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n>2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("ret=%d\n", ret);
//	return 0;
//}

//��ƺ����������������Լ��
#include<stdio.h>

int MCD(int m, int n)
{
	int k = 0;
	while (m%n != 0)
	{
		k = m % n;
		m = n;
		n = k;
	}
	return n;
}

int main()
{
	int m, n = 0;
	scanf("%d%d", &m, &n);
	int ret = MCD(m, n);
	printf("ret=%d\n", ret);
}