#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//struct Stu//结构体
//{
//	int age;
//	char name[15];
//};
//
//struct Stu//位域
//{
//	char a : 4;
//	int b : 10;
//	int c : 5;
//};
//
//enum sex//枚举
//{
//	MALE,
//	FEMALE = 2,
//	SECRET
//};
//
//union un//联合体
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


//判断大小端

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
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}