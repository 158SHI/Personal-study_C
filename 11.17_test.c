#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int main()
//{
//	int arr[] = { 4,4,4,4,4,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int del = 4;
//	int j = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (arr[i] != del)
//		{
//			arr[j++] = arr[i];
//		}
//	}
//	for (int i = 0; i < j; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//};
//
//int cmp(void* e1, void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//int main()
//{
//	struct Stu stu[5] = { {"����",17,"nan"},{"����",19,"nan"},{"����",10,"nv"},{0},{0} };
//	qsort(stu, 5, sizeof(stu[0]), cmp);
//	return 0;
//}

#include<errno.h>

//malloc
//int main()
//{
//	int k = 10;
//	int* p = (int*)malloc(k * sizeof(int));
//	if (p == NULL)//����ʧ��
//	{
//		//��ӡ����ԭ��
//		printf("%s\n", strerror(errno));
//	}
//	else//�ɹ�
//	{
//		for (int i = 0; i < k; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//calloc
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));//����10����СΪint��Ԫ�ز���ʼ��Ϊ0
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for ( i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
	}

	int* ptr = realloc(p, 80);//����

	if (ptr != NULL)//�����ɹ�
	{
		p = ptr;

		//���в���
		for (int i = 10; i < 20; i++)
		{
			*(p + i) = i;
		}
		for (int i = 0; i < 20; i++)
		{
			printf("%d ", *(p + i));
		}
		//���в���
	}

	else
	{
		//����ʧ��
		//exit
	}

	free(p);
	p = NULL;

	return 0;
}