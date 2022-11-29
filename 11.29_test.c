#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//汽水问题重解
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int drinks = 0;//总共喝的汽水数
//	int bottles = 0;//空瓶
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

//将数组中的奇数放到偶数前面

void Reserve(int* const p, int n)
{
	//假设第一个数有序
	//向后遍历数组，若是奇数则进行向前插入
	int i = 0;
	for (i = 1; i < n; i++)
	{
		int key = p[i];//标记
		if (p[i] % 2 == 1)//是奇数
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
	//若有顺序要求
	int n = 0;
	scanf("%d", &n);
	int* p = (int*)malloc((n + 1) * sizeof(int));
	int i = 0;
	for ( i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}

	Reserve(p, n);//重排

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
//		while ((p[left] % 2 != 0) && (left < right))//向右找偶数
//		{
//			left++;
//		}
//		while ((p[right] % 2 == 0) && (left < right))//向左找奇数
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
//	//若无顺序要求
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

//合并有序数列
//int main()
//{
//	int arr1[50] = { 0 };
//	int arr2[50] = { 0 };
//	int arr3[100] = { 0 };
//	int n = 0;
//	int m = 0;
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	for ( i = 0; i < n; i++)//输入arr1
//	{
//		scanf("%d", &arr1[i]);
//	}
//	scanf("%d", &m);
//	for ( i = 0; i < m; i++)//输入arr2
//	{
//		scanf("%d", &arr2[i]);
//	}
//
//	//用i遍历arr1,用j遍历arr2
//	//取较小的数字放入arr3中
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

//有序数列判断

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
//			if (arr[i - 1] < arr[i])//升序
//			{
//				flag_up = 1;
//			}
//			else if (arr[i - 1] > arr[i])//降序
//			{
//				flag_down = 1;
//			}
//			else
//			{
//				continue;//两数相等不做操作
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

//宏
//宏完成的是简单的替换，不是传参
//#define SQUARE(x) ((x)*(x))//注意加括号
//
//int main()
//{
//	int ret = SQUARE(5);
//	printf("%d\n", ret);
//	return 0;
//}

//#define PRINT(X) printf("the value of " #X " is %d\n",X)
////在宏中 # 可以实现将参数插入到字符串中
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
		//使用
	}

	free(p);
	p = NULL;

	return 0;
}