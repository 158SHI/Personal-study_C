#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//struct stu
//{
//	char name[20];
//	char sex[20];
//	int Id[15];
//	//}s1,s2,s3;//ȫ�ֱ���
//};

//typedef struct stu//����
//{
//	char name[20];
//	char sex[5];
//	int Id[15];
//}stu;//����
//
//struct T
//{
//	int arr[10];
//	struct stu s;
//	char* p;
//};

//int main()
//{
//	struct stu s1={"����","��",2212345678};//�ֲ�����
//	stu s2;//ʹ��typedef�Խṹ�����������
//	stu s3 = { "����","��",2215649868 };//��ʼ��
//	return 0;
//}

//�ṹ���Ƕ��ʹ��
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

//�ṹ��Ĵ���
//ֱ�Ӵ���
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
}//��ַ���ã����迪����ʱ����������

int main()
{
	stu s1 = { "����","��","2228123412"};
	Print1(s1);
	Print2(&s1);
	return 0;
}