#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//enum Color
//{
//	Red,
//	Green,
//	Blue
//};
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	enum Color c1= Red;
//	printf("%d\n", c1);
//	printf("%d\n", Green);
//	
//	switch (n)
//	{
//	case 0:
//		printf("Red");
//		break;
//	case 1:
//		printf("Green");
//		break;
//	case 2:
//		printf("Blue");
//		break;
//	}
//	return 0;
//}

//ö�ٳ���

#include<stdio.h>

enum COLOR
{
	red = 1,//ö�ٳ���
	green,
	blue
};//����ö������

//int main()
//{
//	enum COLOR color;//����ö�ٱ���
//	for ( color = 1; color <=3 ; color++)//��ö��Ԫ����������������£����Ա���ö��Ԫ��
//	{
//		printf("ö��Ԫ��:%d\n", color);
//	}
//
//	printf("chose your color (1.red 2.green 3.blue)\n >:");//ö��������ѡ�������
//	scanf("%d", &color);//����ĸ�ʽҪ������
//	switch (color)
//	{
//	case red:
//		printf("your color is red\n");
//		break;
//	case green:
//		printf("your color is green\n");
//		break;
//	case blue:
//		printf("your color is blue\n");
//		break;
//	default:
//		printf("you haven't chosen your color\n");
//		break;
//	}
//	return 0;
//}

int main()//������ת��Ϊö��
{
	enum COLOR color;
	int a = 2;
	enum COLOR color2;
	color2 = (enum color) a;//����ת��
	printf("%d", color2);
	return 0;
}