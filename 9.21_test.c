#define _CRT_SECURE_NO_WARNINGS 1


//���������ַ��󣬰����ַ���ASCII���С�����˳������������ַ���
//���룺���������ж��飬ÿ��ռһ�У��������ַ���ɣ�֮���޿ո�
//���������ÿ���������ݣ����һ�У��ַ��м���һ���ո�ֿ���

//#include<stdio.h>
//#include<string.h>
//
//swap(char* x, char* y)
//{
//	char tmp;
//	tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//
//	char a, b, c, t;
//	while (scanf("%c%c%c",&a,&b,&c) != EOF)//EOF��ֵΪ-1�������벻����-1����ѭ������
//	{
//		
//		if (a > c)
//		{
//			swap(&a, &c);//����
//		}
//		if (a > b)
//		{
//			swap(&a, &b);
//		}
//		if (b > c)
//		{
//			swap(&b, &c);
//		}
//		scanf("%c", &t);//���ջس���������س���¼��
//		printf("%c %c %c", a, b, c);
//		printf("\n");
//	}
//	return 0;
//}

//�����������꣨X1,Y1��,��X2,Y2��,���㲢��������ľ��롣
//���������ж��飬ÿ��ռһ�У���4��ʵ����ɣ��ֱ��ʾx1,y1,x2,y2,����֮���ÿո������
//����ÿ���������ݣ����һ�У����������λС����
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int x1, y1, x2, y2;
//	while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF)
//	{
//		float ret = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));//�������
//		printf("%.2lf\n", ret);
//	}
//	return 0;
//}

//��ʵ���ľ���ֵ
//���������ж��飬ÿ��ռһ�У�ÿ�а���һ��ʵ����
//����ÿ���������ݣ�������ľ���ֵ��Ҫ��ÿ���������һ�У����������λС����
//#include<stdio.h>
//
//double F(double n)
//{
//	if (n >= 0)
//	{
//		return n;
//	}
//	else
//	{
//		return -n;
//	}
//}
//
//int main()
//{
//	double n;
//	while (scanf("%lf",&n) != EOF)
//	{
//		printf("%.2lf\n", F(n));
//	}
//	return 0;
//}

//����������
//#define PI 3.1415927
//#include<stdio.h>
//
//double Squ(double r)
//{
//	return (4.0/3) * PI * r * r * r;
//}
//
//int main()
//{
//	double r;
//	while (scanf("%lf",&r) != EOF)
//	{
//		double ret = Squ(r);
//		printf("%.3lf\n", ret);
//	}
//}


/*

����һ���ٷ��Ƶĳɼ�t������ת���ɶ�Ӧ�ĵȼ�������ת���������£�
90~100ΪA;
80~89ΪB;
70~79ΪC;
60~69ΪD;
0~59ΪE;
���������ж��飬ÿ��ռһ�У���һ��������ɡ�
����ÿ���������ݣ����һ�С�����������ݲ���0~100��Χ�ڣ������һ�У���Score is error!����

*/

#include<stdio.h>
int main()
{
	int input;
	while (scanf("%d",&input) != EOF)
	{
		if (input>0 && input <= 100)
		{
			if (input>=90 && input<= 100)
			{
				printf("A\n");
			}
			else if(input>=80 && input<=89)
			{
				printf("B\n");
			}
			else if (input >= 70 && input <= 79)
			{
				printf("C\n");
			}
			else if (input >= 60 && input <= 69)
			{
				printf("D\n");
			}
			else
			{
				printf("E\n");
			}
		}
		else
		{
			printf("Score is error!\n");
		}
	}
}