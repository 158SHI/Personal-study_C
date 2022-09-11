#define _CRT_SECURE_NO_WARNINGS 1


//#include<stdio.h>
//int main(void)
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入a=");
//	scanf("%d", &a);
//	printf("请输入b=");
//	scanf("%d", &b); 
//	int c = a * b;
//	printf("the length=%d,the width=%d\n", a, b);
//	printf("The area is %d\n", c);
//	return 0;
//}



#include"struck.h"

//结构体类型
int main(void)
{
	struct user a[N];
	input(&a);//传址调用
	sort(&a);
	output(&a);
	return 0;
}
