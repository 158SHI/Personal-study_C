#define _CRT_SECURE_NO_WARNINGS 1

//���10������������
//�������
//���1��100������3�ĸ���
//�Գ������1��100�������
//���2000��3000��������
//�Դ�С������˳�����3����
//շת������������������Լ��
//���ֲ��ҷ��������������е�ĳ��Ԫ��


////���10������������
//#include<stdio.h>
//int main(void)
//{
//	int arr[] = { -1,2,-5,7,5,4,-9,7,-10,-2 };
//	int max = arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for ( i = 1; i <sz; i++)
//	{
//		if (arr[i]>max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max=%d", max);
//	return 0;
//}

////������ͣ�����1/1-1/2+1/3-...+1/99-1/100
//#include<stdio.h>
//int main(void)
//{
//	int flag = 1;
//	int i = 0;
//	double sum = 0;
//	for ( i = 1; i <=100; i++)
//	{
//		double m = flag*(1.0 / i);
//		sum += m;
//		flag = -flag;
//	}
//	printf("sum=%lf", sum);
//	return 0;
//}

////���1��100֮������3�ĸ���
//#include<stdio.h>
//int main(void)
//{
//	int i = 0;
//	int count = 0;
//	for ( i = 1; i <=100; i++)
//	{
//		if (i%10==3)
//		{
//			count++;
//		}
//		if (i/10==3)
//		{
//			count++;
//		}
//	}
//	printf("count=%d", count);
//	return 0;
//}

////�Գ������1��100�������
//#include<stdio.h>
//#include<math.h>
//int main(void)
//{
//	int i = 0;
//	int m = 0;
//	int count = 0;
//	printf("2 ");
//	for ( i = 3; i <=100 ; i+=2)
//	{
//		for ( m = 2; m <=sqrt(i); m++)
//		{
//			if (i%m==0)
//			{
//				break;
//			}
//		}
//		if (m>sqrt(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

////���2000��3000��֮�������
//#include<stdio.h>
//int main(void)
//{
//	int y = 0;
//	int count = 0;
//	for ( y = 2000; y <=3000; y++)
//	{
//		if ((y%4==0)&&(y%100!=0)||(y%400==0))
//		{
//			printf("%d ", y);
//			count++;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

////�Դ�С�����˳�����3����
//#include<stdio.h>
//int main(void)
//{
//	int a, b, c;
//	int temp = 0;
//	printf("������3����>:");
//	scanf("%d%d%d", &a, &b, &c);
//	//ʹa��c�ֱ������ֵ����Сֵ
//	if (a<b)
//	{
//		temp = a;
//		a = b;
//		b = temp;
//	}
//	if (a<c)
//	{
//		temp = a;
//		a = c;
//		c = temp;
//	}
//	if (b<c)
//	{
//		temp = b;
//		b = c;
//		c = temp;
//	}
//	printf("%d>%d>%d", a, b, c);
//	return 0;
//}

////շת������������������Լ��
//#include<stdio.h>
//int main(void)
//{
//	int m, n;
//	int r = 0;
//	printf("������������>:");
//	scanf("%d%d", &m, &n);
//	while (m%n != 0)
//	{
//		r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("�������������Լ��Ϊ%d", n);
//	return 0;
//}

//���ֲ��ҷ��������������е�ĳ��Ԫ��
#include<stdio.h>
int main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int k = 0;
	printf("������Ҫ���ҵ���>:");
	scanf("%d", &k);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (arr[mid]<k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else
		{
			printf("�ҵ��ˣ���Ԫ���±�Ϊ%d", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("�޷��ҵ���Ԫ��");
	}
	return 0;
}