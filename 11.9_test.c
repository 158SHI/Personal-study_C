#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//struct Stu//�ṹ��
//{
//	int age;
//	char name[15];
//};
//
//struct Stu//λ��
//{
//	char a : 4;
//	int b : 10;
//	int c : 5;
//};
//
//enum sex//ö��
//{
//	MALE,
//	FEMALE = 2,
//	SECRET
//};
//
//union un//������
//{
//	char c;
//	int b;
//};
//
//int main()
//{
//	enum sex s = MALE;
//	s = MALE;
//
//	union un u;
//
//	printf("%d\n", sizeof(u));
//	printf("%p\n", &(u.b));
//	printf("%p\n", &(u.c));
//	printf("%p\n", &u);
//
//	return 0;
//}


//�жϴ�С��

//int check_sys(int x)
//{
//	return *(char*)&x;
//}

int check_sys(int x)
{
	union
	{
		char c;
		int a;
	}u;
	u.a = 1;
	return u.c;
}

int main()
{
	int a = 1;
	int ret = check_sys(a);
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}