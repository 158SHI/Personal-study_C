#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
//
////��������Ϸ
//
//void menu()
//{
//	printf("**** ��������Ϸ ****\n");
//	printf("*****  1.play  *****\n");
//	printf("*****  0.exit  *****\n");
//	printf("********************\n");
//}
//
//void game()
//{
//	int cin;
//	int count = 0;
//	int Rand = (rand()%100+1);//����1��100֮��������1
//	while (1)
//	{
//		printf("�������������>:");
//		scanf("%d", &cin);
//		if (cin > Rand)
//		{
//			printf("�´���\n");
//			count++;
//		}
//		else if (cin < Rand)
//		{
//			printf("��С��\n");
//			count++;
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���!\n");
//			printf("��һ������%d�Σ�̫���ˣ�\n", count+1);
//			count = 0;
//			break;
//		}
//	}
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));//�������������
//	int input = 0;
//	do 
//	{
//		menu();
//		printf("��ѡ��>:");
//		again:
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��>:");
//			goto again;
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//qsort����
#include<string.h>

//��������
int cmp_int(void* e1, void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

struct Stu
{
	int age;
	char name[10];
	char sex[5];
};

//�ṹ�尴��������
int cmp_struct_by_age(void* e1,void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}


//�ṹ�尴��������
int cmp_struck_by_name(void* e1, void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int main()
{
	int arr[] = { 1,3,5,7,2,4,6,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	struct Stu s1 = { 18,"���߷�","��" };
	struct Stu s2 = { 20,"��ɫ����","��" };
	struct Stu s3 = { 28,"��ɫ����","��" };
	struct Stu s4 = { 30,"��ɫ����","����" };

	struct Stu sarr[4] = { s1,s2,s3,s4 };

	//�ṹ����������
	qsort(sarr, 4, sizeof(sarr[0]), cmp_struct_by_age);

	printf("�ṹ����������:\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", sarr[i].age);
	}

	printf("�ṹ����������:\n");
	qsort(sarr, 4, sizeof(sarr[0]), cmp_struck_by_name);
	for (int i = 0; i < 4; i++)
	{
		printf("%s ", sarr[i].name);
	}

	return 0;
}