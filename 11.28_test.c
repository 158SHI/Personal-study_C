#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//struct data
//{
//	unsigned int a : 7;//λ��a,ռ7���ֽ�
//	int b : 3;//λ��b,ռ3���ֽ�
//	char c : 4;
//	int : 0;//ռ0���ֽڵ�����λ��
//};
//
//int main()
//{
//	struct data d = { 0 };
//	return 0;
//}

//struct data
//{
//	char a : 4;
//	char b : 3;
//	char c : 7;
//	char d : 5;
//};

//struct data
//{
//	char a;
//	char b;
//	char c;
//	char d;
//};
//
//int main()
//{
//	struct data d = { 0 };
//	d.a = 10;
//	d.b = 12;
//	d.c = 3;
//	d.d = 4;
//	printf("%d\n", sizeof(d));
//	return 0;
//}

//enum COLOR
//{
//	RED,
//	GREEN = 2,
//	BLUE
//};
//
//int main()
//{
//	printf("%d\n", RED);
//	printf("%d\n", BLUE);
//	return 0;
//}

//union U
//{
//	char c;
//	int d;
//};
//
//int main()
//{
//	union U u = { 0 };
//	u.c = 3;
//	u.d = 7;
//	printf("%d\n", sizeof(u));//4
//	return 0;
//}

//union U
//{
//    char s[9];//9
//    int n;//4
//    double d;//8
//};
//
//int main()
//{
//    union U u = { 0 };
//    printf("%d\n", sizeof(u));
//    return 0;
//}

//union Data
//{
//	int i;
//	float f;
//	char  str[20];
//};
//
//int main()
//{
//	union Data data;
//
//	data.i = 10;
//	data.f = 220.5;
//	strcpy(data.str, "C Programming");//����ʹ���������Ա�ᷢ���ڴ�ռ�����
//
//	printf("data.i : %d\n", data.i);
//	printf("data.f : %f\n", data.f);
//	printf("data.str : %s\n", data.str);
//
//	return 0;
//}

//�жϻ����Ĵ洢ģʽ

//union U
//{
//	char c;
//	int d;
//};
//
//int main()
//{
//	union U u = { 0 };
//	u.d = 1;
//	if (u.c == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}

//#define PI 3.14
//
//int main()
//{
//    int a = 0, b = 0;
//    int r = 0;
//    int x = 0;
//    scanf("%d %d", &a, &b);
//    scanf("%d", &r);
//    scanf("%d", &x);
//
//    double sc = PI * r * r;
//
//
//    printf("%d\n", a * b);
//
//    int f = (sc - (int)sc) * 100;//�õ�С�����ֵ�����
//    if (f == 0)//sc������
//    {
//        printf("%d\n", (int)sc);
//    }
//    else if (f % 10 == 0)//sc��һλС��
//    {
//        printf("%.1lf\n", sc);
//    }
//    else//sc����λС��
//    {
//        printf("%.2lf\n", sc);
//    }
//
//    printf("%d\n", x * x);
//    return 0;
//}

//��ӡX��ͼ��
/*
��X�Ϳ��������֣���б�κͷ�б��
*/

//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				/*
//				������б�Σ�i == j��λ����'*'
//				���ڷ�б�Σ���i+j==n-1ʱ��λ����'*'
//				*/
//				if (i == j || i + j == n - 1)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//����������

//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
//				{
//					printf("* ");
//				}
//				else
//				{
//					printf("  ");//�����ո�
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//����������

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (j==0 || i==n-1 || i==j)
//			{
//				printf("* ");
//			}
//			else
//			{
//				printf("  ");//�����ո�
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*
�ܽ᣺
����ͼ�εĴ�ӡ���ҵ�'*'��λ������Ĺ��ɣ����÷�֧�����п���
*/

//Ԥ�������
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	FILE* pf = fopen("log.txt", "w");
//	for ( i = 0; i < 10; i++)
//	{
//		arr[i] = i + 1;
//		printf("%d ", arr[i]);
//		fprintf(pf, "file:%s line:%d date:%s time:%s data:%d\n",
//			__FILE__, __LINE__, __DATE__, __TIME__, arr[i]);
//	}
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}


//Ԥ����ָ��

//#define MAX 100
//#define STR "HELLO,WORLD!"
//#define DO_FOREVER for(;;)
//#define I int