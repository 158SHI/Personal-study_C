#define _CRT_SECURE_NO_WARNINGS 1


//#include<stdio.h>
//int main(void)
//{
//	int a = 0;
//	int b = 0;
//	printf("������a=");
//	scanf("%d", &a);
//	printf("������b=");
//	scanf("%d", &b); 
//	int c = a * b;
//	printf("the length=%d,the width=%d\n", a, b);
//	printf("The area is %d\n", c);
//	return 0;
//}



#include"struck.h"

//�ṹ������
int main(void)
{
	struct user a[N];
	input(&a);//��ַ����
	sort(&a);
	output(&a);
	return 0;
}
