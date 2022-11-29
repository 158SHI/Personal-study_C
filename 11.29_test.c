#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//��ˮ�����ؽ�
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int drinks = 0;//�ܹ��ȵ���ˮ��
//	int bottles = 0;//��ƿ
//
//	drinks += money;
//	bottles += money;
//
//	while (bottles>1)
//	{
//		drinks += bottles / 2;
//		bottles = bottles / 2 + bottles % 2;
//	}
//
//	printf("%d\n", drinks);
//	return 0;
//}

//�������е������ŵ�ż��ǰ��

void Reserve(int* const p, int n)
{
	//�����һ��������
	//���������飬���������������ǰ����
	int i = 0;
	for (i = 1; i < n; i++)
	{
		int key = p[i];//���
		if (p[i] % 2 == 1)//������
		{
			int j = i - 1;
			while(p[j] % 2 == 0 && j >= 0)
			{
				p[j + 1] = p[j];
				j--;
			}
			p[j + 1] = key;
		}
	}
}

int main()
{
	//����˳��Ҫ��
	int n = 0;
	scanf("%d", &n);
	int* p = (int*)malloc((n + 1) * sizeof(int));
	int i = 0;
	for ( i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}

	Reserve(p, n);//����

	for (i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	free(p);
	p = NULL;
	return 0;
}

//void Reserve(int* const p, int n)
//{
//	int left = 0;
//	int right = n - 1;
//	while (left < right)
//	{
//		while ((p[left] % 2 != 0) && (left < right))//������ż��
//		{
//			left++;
//		}
//		while ((p[right] % 2 == 0) && (left < right))//����������
//		{
//			right--;
//		}
//
//		if (left < right)
//		{
//			int tmp = p[left];
//			p[left] = p[right];
//			p[right] = tmp;
//
//			left++;
//			right--;
//		}
//	}
//}
//
//int main()
//{
//	//����˳��Ҫ��
//	int n = 0;
//	scanf("%d", &n);
//	int arr[50] = { 0 };
//	int i = 0;
//
//	for ( i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	Reserve(arr, n);
//	for ( i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//�ϲ���������
//int main()
//{
//	int arr1[50] = { 0 };
//	int arr2[50] = { 0 };
//	int arr3[100] = { 0 };
//	int n = 0;
//	int m = 0;
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	for ( i = 0; i < n; i++)//����arr1
//	{
//		scanf("%d", &arr1[i]);
//	}
//	scanf("%d", &m);
//	for ( i = 0; i < m; i++)//����arr2
//	{
//		scanf("%d", &arr2[i]);
//	}
//
//	//��i����arr1,��j����arr2
//	//ȡ��С�����ַ���arr3��
//	int k = 0;
//	for (i = 0, j = 0; i < n && j < m; )
//	{
//		if (arr1[i]<arr2[j])
//		{
//			arr3[k++] = arr1[i++];
//		}
//		else
//		{
//			arr3[k++] = arr2[j++];
//		}
//	}
//	if (i == n)
//	{
//		while (j < m)
//		{
//			arr3[k++] = arr2[j++];
//		}
//	}
//	else if(j == m)
//	{
//		while (i < n)
//		{
//			arr3[k++] = arr1[i++];
//		}
//	}
//
//	for ( k = 0; k < m+n; k++)
//	{
//		printf("%d ", arr3[k]);
//	}
//	return 0;
//}

//���������ж�

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[20] = { 0 };
//
//	int flag_up = 0;
//	int flag_down = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (i > 0)
//		{
//			if (arr[i - 1] < arr[i])//����
//			{
//				flag_up = 1;
//			}
//			else if (arr[i - 1] > arr[i])//����
//			{
//				flag_down = 1;
//			}
//			else
//			{
//				continue;//������Ȳ�������
//			}
//		}
//	}
//
//	if (flag_up + flag_down == 2)
//	{
//		printf("unsorted\n");
//	}
//	else//flag_up + flag_down == 0 || flag_up + flag_down == 1
//	{
//		printf("sorted\n");
//	}
//
//	return 0;
//}

//��
//����ɵ��Ǽ򵥵��滻�����Ǵ���
//#define SQUARE(x) ((x)*(x))//ע�������
//
//int main()
//{
//	int ret = SQUARE(5);
//	printf("%d\n", ret);
//	return 0;
//}

//#define PRINT(X) printf("the value of " #X " is %d\n",X)
////�ں��� # ����ʵ�ֽ��������뵽�ַ�����
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	PRINT(b);
//	return 0;
//}


//##
//#define CAT(X,Y) X##Y
//
//int main()
//{
//	int xixihaha = 666;
//	printf("%d\n", CAT(xixi, haha));//666
//	//printf("%d\n", xixi##haha);
//	//printf("%d\n", xixihaha);
//	return 0;
//}

//int main()
//{
//	char arr[6] = "hello";
//	arr[0] = 'X';
//	printf("%s\n", arr);
//
//	//char* p = "hello";
//	//p[0] = 'X';//err
//	//printf("%s\n", p);
//	return 0;
//}


int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		//ʹ��
	}

	free(p);
	p = NULL;

	return 0;
}