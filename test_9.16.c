#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//struct stu
//{
//	char name[20];
//	char sex[20];
//	int Id[15];
//	//}s1,s2,s3;//全局变量
//};

//typedef struct stu//定义
//{
//	char name[20];
//	char sex[5];
//	int Id[15];
//}stu;//类型
//
//struct T
//{
//	int arr[10];
//	struct stu s;
//	char* p;
//};

//int main()
//{
//	struct stu s1={"张三","男",2212345678};//局部变量
//	stu s2;//使用typedef对结构体进行重命名
//	stu s3 = { "李四","男",2215649868 };//初始化
//	return 0;
//}

//结构体的嵌套使用
//struct S
//{
//	int a;
//	char c;
//	double d;
//};
//
//struct T
//{
//	char ch[10];
//	struct S s;
//	char* pc;
//};
//
//int main()
//{
//	struct T t = { "hehe",{100,'w',3.14},NULL};
//	printf("%s\n", t.ch);
//	printf("%s\n", t.pc);
//	printf("%d\n", t.s.a);
//}

//结构体的传参
//直接传参
#include<stdio.h>

typedef struct S
{
	char name[20];
	char sex[5];
	char ID[15];
}stu;

void Print1(stu s)
{
	printf("name:  %s\n", s.name);
	printf("sex:   %s\n", s.sex);
	printf("ID:    %s\n", s.ID);
}

void Print2(stu* s)
{
	printf("name:  %s\n", s->name);
	printf("sex:   %s\n", s->sex);
	printf("ID:    %s\n", s->ID);
}//传址调用，无需开辟临时变量，更优

int main()
{
	stu s1 = { "张三","男","2228123412"};
	Print1(s1);
	Print2(&s1);
	return 0;
}