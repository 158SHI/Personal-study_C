#define _CRT_SECURE_NO_WARNINGS 1

/*
��Ŀ 1048: [�������]�Զ��庯��֮�ַ�������
ʱ������: 1Sec �ڴ�����: 128MB �ύ: 15143 ���: 8756
��Ŀ����
��һ�ַ���������n���ַ���дһ�����������ַ����дӵ�m���ַ���ʼ��ȫ���ַ����Ƴ�Ϊ��һ���ַ�����
�����ʽ
����n һ���ַ��� ����m
�����ʽ
��m��ʼ���Ӵ�
��������
6
abcdef
3
�������
cdef
*/

//#include<stdio.h>
//int main()
//{
//	//n���ַ����ӵ�m����ʼ����
//	int n, m;
//	char str[1000];
//	scanf("%d", &n);
//	scanf("%s", &str);
//	scanf("%d", &m);
//	for (int i = m-1; i < n; i++)
//	{
//		printf("%c", str[i]);
//	}
//	return 0;
//}


/*
��Ŀ 1009: [�������] ���ֵĴ������ж�
ʱ������ : 1Sec �ڴ����� : 128MB �ύ : 67767 ��� : 31423
��Ŀ����
����һ��������5λ��������Ҫ�� 1��������Ǽ�λ�� 2���ֱ����ÿһλ���� 3�������������λ���֣�����ԭ��Ϊ321, Ӧ���123
�����ʽ
һ��������5λ������
�����ʽ
���� ��һ�� λ�� �ڶ��� �ÿո�ֿ���ÿ�����֣�ע�����һ�����ֺ�û�пո� ������ ��������������
��������
12345
�������
5
1 2 3 4 5
54321
*/

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[10];
//	scanf("%s", &arr);
//	int len = strlen(arr);
//	printf("%d\n", len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	printf("\n");
//	for (int i = len-1; i >= 0; i--)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

/*
���Լ������С������
*/

//#include<stdio.h>
//
//int Ma(int a, int b)
//{
//	if (a<b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	while (a%b != 0)
//	{
//		int tmp = a % b;
//		a = b;
//		b = tmp;
//	}
//	return b;
//}
//
//int Mi(int a, int b)
//{
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//
//	int i = a;
//	while (i%a!=0 || i%b!=0)
//	{
//		i++;
//	}
//	return i;
//}
//
//int main()
//{
//	int m, n;
//	while (scanf("%d%d", &m, &n) != EOF)
//	{
//		printf("%d %d\n", Ma(m, n), Mi(m, n));
//	}
//	return 0;
//}

/*
��Ŀ 1012: [�������]�ַ�������ͳ��
ʱ������: 1Sec �ڴ�����: 128MB �ύ: 48642 ���: 25401
��Ŀ����
����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ�����֡��ո�������ַ��ĸ�����

�����ʽ
һ���ַ�,���Ȳ�����200

�����ʽ
ͳ��ֵ

��������
aklsjflj123 sadf918u324 asdf91u32oasdf/.';123
�������
23 16 2 4
*/

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//		char str[200];
//		gets(str);
//		int letc = 0, numc = 0, spac = 0, othc = 0;
//		for (int i = 0; i < strlen(str); i++)
//		{
//			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
//			{
//				letc++;
//			}
//			else if (str[i] >= '0' && str[i] <= '9')
//			{
//				numc++;
//			}
//			else if (str[i] == ' ')
//			{
//				spac++;
//			}
//			else
//			{
//				othc++;
//			}
//		}
//		printf("%d %d %d %d\n", letc, numc, spac, othc);
//
//	return 0;
//}

/*
��Ŀ 1013: [�������]Sn�Ĺ�ʽ���
ʱ������: 1Sec �ڴ�����: 128MB �ύ: 40603 ���: 27429
��Ŀ����
��Sn=a+aa+aaa+��+aa��aaa����n��a��ֵ֮������a��һ�����֣�Ϊ2�� ���磬n=5ʱ=2+22+222+2222+22222��n�ɼ������롣

�����ʽ
n

�����ʽ
Sn��ֵ

��������
5
�������
24690
*/

//#include<stdio.h>
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int a = 0;
//		int sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			a = a * 10 + 2;
//			sum += a;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

/*
��Ŀ 1025: [�������]������봦��
ʱ������: 1Sec �ڴ�����: 128MB �ύ: 36314 ���: 21840
��Ŀ����
����һ���������źõ�9��Ԫ�ص����飬������һ����Ҫ��ԭ������Ĺ��ɽ������������С�
�����ʽ
��һ�У�ԭʼ���С� �ڶ��У���Ҫ��������֡�
�����ʽ
����������
��������
1 7 8 17 23 24 59 62 101
50
�������
1 7 8 17 23 24 50 59 62 101
*/

//#include<stdio.h>
//
//void insert_sort(int arr[], int n)
//{
//	int j = 8;
//	int key = n;
//	while (j>=0 && arr[j]>key)
//	{
//		arr[j + 1] = arr[j];
//		j--;
//	}
//	arr[j + 1] = key;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int n;
//	for (int i = 0; i < 9; i++)
//	{
//		scanf("%d", &arr[i]);
//	}//����ԭʼ����
//	scanf("%d", &n);//�����������
//	insert_sort(arr,n);//���в���
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//��������
//#include<stdio.h>
//
//void insert_sort(int arr[], int sz)
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int key = arr[i];
//		int j = i - 1;
//		while (j>=0 && arr[j]>key)
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = key;
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,2,5,3,7,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	insert_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*
�����������
����10������������������ÿո����
*/
//
//#include<stdio.h>
//int main()
//{
//	int arr[10];
//	int i, j;
//	for ( i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for ( j = 9; j >=0 ; j--)
//	{
//		printf("%d ", arr[j]);
//	}
//	return 0;
//}

////�궨��
//
//#define MAX(x,y) (x>y?x:y)//��ķ��š���Ĳ���������
//#define SUM(x,y) (x+y) //��ļ򵥶���
///*
//��ֻ�����ڴ���򵥵��߼�
//*/
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = MAX(a, b);
//	int sum = SUM(a, b);
//	printf("max=%d\nsum=%d\n", max, sum);
//	return 0;
//}


//ָ��
#include<stdio.h>
int main()
{
	int a = 10;
	printf("%p\n", &a);//ȡ��������ռ�ڴ浥Ԫ�ֽ��� ��һ���ֽڵĵ�ַ
	int* pc = &a;
	printf("%zd\n", sizeof(pc));//ָ��Ĵ�С
	return 0;
}