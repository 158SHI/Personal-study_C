#define _CRT_SECURE_NO_WARNINGS 1

//9*9�˷��ھ���

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		int tmp = rand() % 3;
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//�Զ��庯��������������

//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//	int a = 6;
//	int b = 8;
//	printf("����ǰ:a=%d,b=%d\n", a, b);
//	swap(&a, &b);
//	printf("������:a=%d,b=%d\n", a, b);
//	return 0;
//}

//�ж�����

//int is_leap(int y)
//{
//	if (((y%4==0)&&(y%100!=0))||(y%400==0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int y;
//	while (printf("������һ�����:>"),scanf("%d", &y) != EOF)
//	{
//		int ret = is_leap(y);
//		if (ret == 1)
//		{
//			printf("������\n");
//		}
//		else
//		{
//			printf("��������\n");
//		}
//	}
//	return 0;
//}

//��ӡ����

//int is_prime(int x)
//{
//	for (int i = 2; i <= sqrt(x); i++)
//	{
//		if (x%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	for (int i = 101; i <= 199; i+=2)
//	{
//		int ret = is_prime(i);
//		if (ret == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//void Plus(int x, int y,int arr[2])
//{
//	x += 1;
//	y += 1;
//	arr[0] = x;
//	arr[1] = y;
//}
//
//int main()
//{
//	int a = 3, b = 4;
//	int arr[2];
//	Plus(a, b, arr);
//	printf("%d %d\n", arr[0], arr[1]);
//	return 0;
//}

//����100��1��100֮��������
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int count = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		printf("%-2d ", rand() % 100 + 1);
//		count++;
//		if (count==10)
//		{
//			printf("\n");
//			count = 0;
//		}
//	}
//	return 0;
//}


/*
ָ�������
*/

//������һ
//int main()
//{
//    int a[5] = { 1, 2, 3, 4, 5 };
//    int* ptr = (int*)(&a + 1);
//    printf("%d,%d", *(a + 1), *(ptr - 1));// 2,5
//    return 0;
//}
////����Ľ����ʲô��


//�������
//���ڻ�ûѧϰ�ṹ�壬�����֪�ṹ��Ĵ�С��20���ֽ�
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}* p;
//����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
//��֪���ṹ��Test���͵ı�����С��20���ֽ�
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);// 0x00100014 p��ʾ�ṹ��ĵ�ַ��+1��ʾ�ṹ���1�ĵ�ַ
//	printf("%p\n", (unsigned long)p + 0x1);//0x00100001 
//	printf("%p\n", (unsigned int*)p + 0x1);//0x00100004 ��pת��Ϊ�޷�������ָ�룬+1�������ĸ��ֽ�
//	return 0;
//}
/*
�������ָ��+1��Ч��
ָ��+1��Ч��ȡ����ָ������
*/


//��������
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);//
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//0x04  0x02
//	return 0;
//	/*
//	ptr[-1] == *(ptr-1)
//	*/
//}

//��������
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//���ű��ʽ�����Ϊ���Ĳ���
//	int* p;
//	p = a[0];//a[0]�ǵ�һ�е����������������ʾ��һ�е�һ��Ԫ�صĵ�ַ
//	printf("%d", p[0]);// 0 p[0]=*(p+0)
//	return 0;
//}


//�������壨ע�⣩
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//0xFF FF FF FC,-4
//	// 10000000 00000000 00000000 00000100
//	// 11111111 11111111 11111111 11111011
//	// 11111111 11111111 11111111 11111100
//	// 1111 1111 1111 1111 1111 1111 1111 1100
//	//   F    F    F    F   F    F    F     C
//	// 0xFF FF FF FC
//	//-4�Ե�ַ��ʽ��ӡʱֱ�Ӵ�ӡ����
//	return 0;
//}

//��������
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));// 10,5
//	return 0;
//}


//��������
int main()
{
	char* a[] = { "work","at","alibaba" };// p(w) p(a) p(a2)
	char** pa = a;// char* * pa pa��a[]��Ԫ�صĵ�ַ
	pa++;//��ʾ�ڶ���Ԫ�صĵ�ַ
	printf("%s\n", *pa);// *pa��ʾ�ڶ���Ԫ�ؼ� "at"����Ԫ�صĵ�ַ
	return 0;//at
}