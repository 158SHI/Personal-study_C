#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//����ָ��ĵ���

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	printf("%d\n", Add(1, 3));
//
//	int(*p)(int, int) = Add;
//
//	printf("%d\n", (*p)(1, 3));
//	printf("%d\n", (p)(1, 3));
//	printf("%d\n", (**p)(1, 3));
//	printf("%d\n", (****p)(1, 3));//����ָ���ڵ���ʱ * ����ʵ�ʼ�ֵ
//
//	return 0;
//}


//����ָ������
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	//printf("%d\n", Add(1, 3));
//
//	int(*p)(int, int) = Add;//p������*��ϣ�����p��һ��ָ��
//
//	int(*parr[4])(int, int) = { Add,Sub,Mul,Div };
//	//p������ 4[ ]��ϣ�����p��һ�����飬�������Ԫ������Ϊ int(*    )(int ,int)��������ָ������
//
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d\n", parr[i](8, 4));//12 4 32 2
//	}
// return 0;
//}


//����ָ�������Ӧ�ã�ת�Ʊ�

//������

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void menu()
//{
//	printf("*********************\n");
//	printf("***1.Add     2.Sub***\n");
//	printf("***3.Mul     4.Div***\n");
//	printf("****** 0.exit ******\n");
//}

/*int main()
{
	int input = 0;
	int(*parr[5])(int, int) = { 0,Add,Sub,Mul,Div };//��������ͷ���ֵ������ͬ�ĺ������� ����ָ�����顪��ת�Ʊ�
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		if (input>=1 && input <=4)
		{
			int x, y;
			printf("����������������>:");
			scanf("%d %d", &x, &y);
			int ret = parr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("�˳�\n");
		}
		else
		{
			printf("ѡ�����\n");
		}

	} while (input);
	return 0;
}*/


//�ص�����  ���� �ú���ָ����ú���
//�����switch�������������  ���� �ص�����

/*
void calu(int(*p)(int, int))//�ú���ָ����պ���
{
	printf("����������������>:");
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n", p(x, y));//�ú���ָ����ö�Ӧ����
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			calu(Add);
			break;
		case 2:
			calu(Sub);
			break;
		case 3:
			calu(Mul);
			break;
		case 4:
			calu(Div);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}*/

//�ص�����_2

//void Print(char* str)
//{
//	printf("%s", str);
//}
//
//void test(void(*p)(char*))
//{
//	printf("test:\n");
//	p("hehehehhe");//�����ص�
//}
//
//int main()
//{
//	test(Print);
//	return 0;
//}


//ð������

//void Bobble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)//sz-1������
//	{
//		for (int j = 0; j < sz-1-i; j++)//1������
//		{
//			if (arr[j]>arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,3,5,7,2,4,6,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bobble_sort(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//qsort����

#include<stdlib.h>
//#include<search.h>

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
	//����ֵ��
	//e1>e2,����ֵ����0
	//e1==e2,����ֵ����0
	//e1<e2������ֵС��0
}

int cmp_float(const void* e1, const void* e2)
{
	return ((int)(*(int*)e1 - *(int*)e2));
}

int main()
{
	//����Ԫ�ص�����
	int arr1[] = { 1,3,5,7,9,2,4,6 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	qsort(arr1, sz, sizeof(arr1[0]),cmp_int);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");

	//������Ԫ�ص�����
	float arr2[] = { 8.5,3.4,2.1,1.6,6.7,5.3 };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	qsort(arr2, sz2, sizeof(arr2[0]), cmp_float);
	for (int i = 0; i < sz2; i++)
	{
		printf("%.2f ", arr2[i]);
	}

	
	return 0;
}

//int Add2(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int(*p)(int, int) = Add2;
//	printf("%d", (*p)(3, 5));
//	return 0;
//}