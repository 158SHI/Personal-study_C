#define _CRT_SECURE_NO_WARNINGS 1

//�ַ�ָ��
//1.���һ���ַ��ĵ�ַ
//2.���һ���ַ�����Ԫ�صĵ�ַ

#include<stdio.h>
//int main()
//{
//	char arr[20] = "Hello,world";
//	char* pc = &arr;
//	printf("%s\n", arr);//��ŵ�����Ԫ�صĵ�ַ
//	printf("%s\n", pc);//����Ԫ�صĵ�ַ�ҵ��������鲢��ӡ
//
//	const char* p = "abcdef";//�����ַ���
//	printf("%c\n", *p);
//	printf("%s\n", p);//�����ַ��ĵ�ַ�浽p��
//}

//#include<stdio.h>
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char* p1 = "abcdef";//�����ַ���
//	char* p2 = "abcdef";
//	if (arr1==arr2)
//	{
//		printf("hehe\n");//����ӡ
//	}
//	if (p1==p2)//p1��p2ָ��ͬһ��λ��
//	{
//		printf("haha\n");//haha
//	}
//	return 0;
//}

//ָ������
//#include<stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2, 3, 4, 5, 6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };//��ָ�������������������Ԫ�ص�ַ,��ά����������
//	int psz = sizeof(parr) / sizeof(parr[0]);
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0; i < psz; i++)//���������������Ԫ�ص�ַ
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));//����ÿ�������е�Ԫ��
//		}
//		printf("\n");
//	}
//	return 0;
//}

////����ָ��
//#include<stdio.h>
//int main()
//{
//	//arr - ��Ԫ�ص�ַ
//	//&arr[0] - ��Ԫ�ص�ַ
//	//&arr - ����ĵ�ַ
//	
//	int arr[10] = {2,3,4,5,6};
//	int(*p)[10] = &arr;// [ ]�����ȼ��ϸߣ�(*p)��ʾp��һ��ָ�룬ָ��һ������Ϊ10������
//	
//	char* arr[5];//��һ�����char*����Ԫ�ص�����
//	char* (*parr) [5] = &arr;//*˵��parr��ָ�룬parr��ָ���������[5]˵��parrָ������鳤����5��char*˵��parrָ�������Ԫ��������char*
//	return 0;
//}

//ָ�������ʹ��

//�������ʽ
void print1(int arr[3][5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//ָ�����ʽ
void print2(int(*p)[5], int row, int col)//��ά���鴫��ʱ�����ǵ�һ�еĵ�ַ
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *((*p + i) + j));
			//printf("%d ", ( * (p + i))[j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print1(arr,3,5);
	printf("--------------------------\n");
	print2(arr, 3, 5);
	return 0;
}