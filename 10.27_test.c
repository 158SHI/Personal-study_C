#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
//
////猜数字游戏
//
//void menu()
//{
//	printf("**** 猜数字游戏 ****\n");
//	printf("*****  1.play  *****\n");
//	printf("*****  0.exit  *****\n");
//	printf("********************\n");
//}
//
//void game()
//{
//	int cin;
//	int count = 0;
//	int Rand = (rand()%100+1);//生成1到100之间的随机数1
//	while (1)
//	{
//		printf("请输入你的数字>:");
//		scanf("%d", &cin);
//		if (cin > Rand)
//		{
//			printf("猜大了\n");
//			count++;
//		}
//		else if (cin < Rand)
//		{
//			printf("猜小了\n");
//			count++;
//		}
//		else
//		{
//			printf("恭喜你，猜对了!\n");
//			printf("你一共猜了%d次，太棒了！\n", count+1);
//			count = 0;
//			break;
//		}
//	}
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));//生成随机数种子
//	int input = 0;
//	do 
//	{
//		menu();
//		printf("请选择>:");
//		again:
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择>:");
//			goto again;
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//qsort函数
#include<string.h>

//排序整型
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

//结构体按年龄排序
int cmp_struct_by_age(void* e1,void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}


//结构体按姓名排序
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
	struct Stu s1 = { 18,"无疫烦","男" };
	struct Stu s2 = { 20,"蓝色妖姬","男" };
	struct Stu s3 = { 28,"粉色妖姬","男" };
	struct Stu s4 = { 30,"紫色妖姬","保密" };

	struct Stu sarr[4] = { s1,s2,s3,s4 };

	//结构体年龄排序
	qsort(sarr, 4, sizeof(sarr[0]), cmp_struct_by_age);

	printf("结构体年龄排序:\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", sarr[i].age);
	}

	printf("结构体姓名排序:\n");
	qsort(sarr, 4, sizeof(sarr[0]), cmp_struck_by_name);
	for (int i = 0; i < 4; i++)
	{
		printf("%s ", sarr[i].name);
	}

	return 0;
}