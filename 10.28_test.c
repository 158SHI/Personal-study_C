#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include<stdio.h>

//����ð������ģ��ʵ��qsort����

//int cmp_int(void* e1, void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//
//
//Swap(char* buf1, char* buf2, int width)
//{
//	for (int i = 0; i < width; i++)
//		
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//void Bubble_sort(void* base, int sz, int width, int(*cmp)(void* e1, void* e2))
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//				//Swap((char*)base, (char*)base, width);
//
//			}
//		}
//	}
//}
//
//
//struct Stu
//{
//	int age;
//	char name[10];
//	char sex[5];
//};
//
//cmp_Stu_name(void* e1,void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//
//int main()
//{
//	//����������������
//	int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
//
//	//��ð�����������������
//	struct Stu sarr[4] = { {18,"���߷�","��"}, {20,"����","25"}, {28,"����","��"}, {30,"����","��"} };
//	Bubble_sort(sarr, 4, sizeof(sarr[0]), cmp_Stu_name);
//	return 0;
//}

/*
ָ���������������
*/

int main()
{
	//һά����
	/*int a[] = {1,2,3,4};
	printf("%d\n", sizeof(a));// 16 sizeof(a)���������������Ĵ�С
	printf("%d\n", sizeof(a + 0));// 4/8 a��ʾ��Ԫ�ص�ַ��a+0������Ԫ�ص�ַ
	printf("%d\n", sizeof(*a));// 4 a��ʾ��Ԫ�ص�ַ��*a��ʾ��Ԫ��
	printf("%d\n", sizeof(a + 1));// 4/8 a��ʾ��Ԫ�ص�ַ��a+1��ʾ�ڶ���Ԫ�صĵ�ַ
	printf("%d\n", sizeof(a[1]));// 4 a[1]��ʾ�ڶ���Ԫ��
	printf("%d\n", sizeof(&a));// 4/8 &aȡ������a�ĵ�ַ����СΪ4/8
	printf("%d\n", sizeof(*&a));// 16 &aȡ������a�ĵ�ַ�������ú��ʾ��������
	printf("%d\n", sizeof(&a + 1));// 4/8 &aȡ��������������ĵ�ַ��+1�Ա�ʾһ����ַ
	printf("%d\n", sizeof(&a[0])); // 4/8 ȡ����һ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1)); // 4/8 ��һ��Ԫ�صĵ�ַ��1����ʾ�ڶ���Ԫ�صĵ�ַ*/
	/*
	��������ʾ��Ԫ�ص�ַ
			�������⣺
					1.sizeof(������)��������������Ĵ�С����λ���ֽ�
					2.&��������ȡ��������������
	*/


	//�ַ�����
	/*
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));// 6 ��������Ĵ�С
	printf("%d\n", sizeof(arr + 0));// 4/8 ��Ԫ�ص�ַ��0����ʾ��Ԫ�ص�ַ
	printf("%d\n", sizeof(*arr));// 1 ��Ԫ�ص�ַ�����ã���ʾ��һ��Ԫ��
	printf("%d\n", sizeof(arr[1]));// 1 �ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&arr));// 4/8 ��������ĵ�ַ
	printf("%d\n", sizeof(&arr + 1));// 4/8 ����ĵ�ַ
	printf("%d\n", sizeof(&arr[0] + 1));// 4/8 �ڶ���Ԫ�صĵ�ַ


	printf("%d\n", strlen(arr));//���ֵ �������в���'\0'�����������ֱ���ҵ� \0
	printf("%d\n", strlen(arr + 0));// ���ֵ
	//printf("%d\n", strlen(*arr));// ����
	//printf("%d\n", strlen(arr[1]));//����
	printf("%d\n", strlen(&arr));// ���ֵ
	printf("%d\n", strlen(&arr + 1));//���ֵ��6
	printf("%d\n", strlen(&arr[0] + 1));//���ֵ��1
	*/

	/*
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//7 ע����� \0
	printf("%d\n", sizeof(arr + 0));// 4/8 ��ʾ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*arr));// 1 ��������Ԫ�ص�ַ����ʾ��Ԫ�صĴ�С����С��1
	printf("%d\n", sizeof(arr[1]));//1 ����ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&arr));// 4/8 ��ʾ��������ĵ�ַ�Ĵ�С
	printf("%d\n", sizeof(&arr + 1));// 4/8
	printf("%d\n", sizeof(&arr[0] + 1));// 4/8 ��ʾ�ڶ���Ԫ�صĵ�ַ�Ĵ�С

	printf("%d\n", strlen(arr));//6 ����Ԫ�ص�ַ��ʼ�����ַ�������
	printf("%d\n", strlen(arr + 0));//6 ����Ԫ�ص�ַ��ʼ�����ַ�������
	printf("%d\n", strlen(*arr));//����,�Ƿ������ڴ�
	printf("%d\n", strlen(arr[1]));//���󣬷Ƿ������ڴ�
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//���ֵ���ӵ�һ��������濪ʼ����
	printf("%d\n", strlen(&arr[0] + 1));//5 �ӵڶ���Ԫ�صĵ�ַ��ʼ����
	*/

	char* p = "abcdef";
	printf("%d\n", sizeof(p));// 4/8 p�д������Ԫ�أ�a���ĵ�ַ
	printf("%d\n", sizeof(p + 1));// 4/8 �õ������ַ�b�ĵ�ַ
	printf("%d\n", sizeof(*p));// 1 ��ʾ�ַ����ĵ�һ���ַ�
	printf("%d\n", sizeof(p[0]));// 1 p[0] == *(p+0)
	printf("%d\n", sizeof(&p));// 4/8 ȡ��p�ĵ�ַ
	printf("%d\n", sizeof(&p + 1));// 4/8
	printf("%d\n", sizeof(&p[0] + 1));// 4/8 ��ʾb�ĵ�ַ


	printf("%d\n", strlen(p));// 6 ��a�ĵ�ַ��ʼ������ַ� 
	printf("%d\n", strlen(p + 1));// 5 ��b�ĵ�ַ��ʼ������ַ�
	//printf("%d\n", strlen(*p));// error
	//printf("%d\n", strlen(p[0]));//error
	printf("%d\n", strlen(&p));// ���ֵ
	printf("%d\n", strlen(&p + 1));// ���ֵ
	printf("%d\n", strlen(&p[0] + 1));// 5 ��ʾb�ĵ�ַ
}