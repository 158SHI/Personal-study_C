#define _CRT_SECURE_NO_WARNINGS 1

//һά���鴫��

#include<stdio.h>

//void test(int arr1)//��������ʽ����
//{
//	;
//}
//
//void test(int arr1[10])
//{
//	;
//}
//
//void test(int* arr1)//��ָ�����
//{
//	;
//}
//
//void test2(int* arr2)//���������
//{
//	;
//}
//
//void test2(int* arr2[5])
//{
//	;
//}
//
//void test2(int** arr[5])//��ָ�����
//{
//	;
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4 };
//	test(arr1);
//	int* arr2[5];
//	test2(arr2);
//	return 0;
//}

//void test(int arr[3][5])//���������
//{
//	;
//}
//
//void test(int arr[][5])//ֻ��ʡ���У�����ʡ����
//{
//	;
//}
//
//void test(int(*p)[5])//������ָ�����
//{
//	;
//}
//
////void test2(int(*p)[])
////{
////	;
////}
//
//int main()
//{
//	int arr[3][5];
//	test(arr);
//	//int arr2[] = { 1,2,3 };
//	//test2(&arr2);
//	return 0;
//}

//����ָ��
int Add(int x, int y)
{
	return x + y;
}

void Print(char* str)
{
	printf("%s\n", str);
}

int main()
{
	int a = 10;
	int b = 20;
	printf("%d\n", Add(a, b));

	int(*p)(int, int) = &Add;//(*p)��ʾp��һ��ָ�룬��int��int������(*p)ָ�����һ�������������Ĳ���������int,(*p)ǰ��int���������ķ�������
	int ret2 = (*p)(5, 9);
	printf("%d\n", ret2);

	void(*p2)(char*) = &Print;
	(*p2)("Hello,world!");//�����õ��ú���

	return 0;
}