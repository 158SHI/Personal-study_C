#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stddef.h>

//
//int main()
//{
//	int arr[10] = { 0 };
//	FILE* pf = fopen("log.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i + 1;
//		fprintf(pf,"file:%s date:%s time:%s line:%d data:%d\n",
//			__FILE__, __DATE__, __TIME__, __LINE__, arr[i]);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//ʵ��offsetof��

//#define OFFSETOF(struct_name, member_name) (int)(&(((struct_name*)0)->member_name))
//
//struct S 
//{
//	char c;
//	int d;
//	double n;
//};
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S, c));//0
//	printf("%d\n", OFFSETOF(struct S, d));//4
//	printf("%d\n", OFFSETOF(struct S, n));//8
//	return 0;
//}

//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

//���ù�ʽ
//#include<math.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int tmp = (int)pow(n, 2) + n;
//	tmp >>= 1;
//	printf("%d\n", tmp);
//	return 0;
//}

//�����߼�������
//�߼����������Ƶݹ�
//#include<stdbool.h>
//
//int Sum(int n)
//{
//	int sum = 0;
//	_Bool flag =  (n > 0) && (sum = n + Sum(n - 1));//&&�Ķ�·����
//	return sum;
//}
//
////int Sum(int n)
////{
////	if (n > 0)
////	{
////		return n + Sum(n - 1);
////	}
////	else
////	{
////		return 0;
////	}
////}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Sum(n);
//	printf("%d\n", ret);
//	return 0;
//}

//��ʹ������������ӷ�

//int Sum(int a, int b)
//{
//	if (b == 0)
//	{
//		return a;
//	}
//	int tmp1 = a ^ b;//����λ
//	int tmp2 = (a & b) << 1;//ģ���λ
//	return Sum(tmp1, tmp2);//�ݹ�
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = Sum(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

//�����������

//#define DEBUG

//int main()
//{
//	int n = 10;
//	int arr[10] = { 0 };
//	int i = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//
//#ifdef DEBUG//��DEBUG��������������
//		printf("%d\n", arr[i]);
//#endif
//
//#if 0
//		printf("hehe\n");
//#endif
//
//#ifndef DEBUG
//		printf("haha\n");
//#endif
//	}
//	return 0;
//}

//#include<stdlib.h>
//
//struct S
//{
//	char c;
//	int* parr;
//};
//
//int main()
//{
//	struct S* p = (struct S*)malloc(sizeof(struct S));//Ϊ�ṹ��S���ٿռ�
//	if (p != NULL)
//	{
//		p->parr = (int*)malloc(10 * sizeof(int));
//		if (p->parr != NULL)
//		{
//			//ʹ��
//		}
//	}
//
//	free(p->parr);//ע���ͷ�˳��
//	p->parr = NULL;
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}

#include<string.h>

//void Reserve(char* arr, int len)
//{
//    char* left = arr;
//    char* right = arr + len - 1;
//    while (left < right)
//    {
//        char tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}
//
//void ReserveWord(char* arr, int len)
//{
//    char* end = arr;
//    while (*end != '\0')
//    {
//        end = arr;
//        while ((*end != ' ') && (*end != '\0'))
//        {
//            end++;
//        }
//        int len_word = end - arr;
//
//        char* left = arr;
//        char* right = end - 1;
//        while (left < right)
//        {
//            char tmp = *left;
//            *left = *right;
//            *right = tmp;
//            left++;
//            right--;
//        }
//
//        arr = end + 1;
//    }
//}
//
//
//int main()
//{
//    char arr[100] = { 0 };
//    gets(arr);
//    int len = strlen(arr);
//
//    Reserve(arr, len);//���������ַ���
//    ReserveWord(arr, len);//����ÿ������
//
//    puts(arr);
//    return 0;
//}

//int Func(int a, int b)
//{
//	while ((a % b) != 0)
//	{
//		int c = a % b;
//
//		a = b;
//		b = c;
//	}
//	return b;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret1 = Func(a, b);
//	int ret2 = a * b / ret1;
//	printf("%d\n", ret2);
//	return 0;
//}


//������������С������
/*
	a,b
	����a,b����С�������� m
	����1.  m/a == i;	����i��һ������
		2.	a*i % b == 0;
*/
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int i = 1;
//	while (a * i % b != 0)
//	{
//		i++;
//	}
//	printf("%d\n", a * i);
//	return 0;
//}

//�����ַ���

void Reserve(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[100] = { 0 };
	gets(arr);
	int len = strlen(arr);
	Reserve(arr, arr + len - 1);//���������ַ���
	
	char* cur = arr;

	while (*cur != '\0')//����ÿ������
	{
		char* start = cur;
		while ((*cur != ' ') && (*cur != '\0'))
		{
			cur++;
		}
		Reserve(start, cur - 1);
		if (*cur != '\0')
		{
			cur++;
		}
	}

	puts(arr);
	return 0;
}