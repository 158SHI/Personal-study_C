#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

//作业：
//函数递归计算n的k次方

//float power(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//
//	else if(k>0)
//	{
//		if (k == 1)
//		{
//			return n;
//		}
//		else
//		{
//			return n * power(n, k - 1);
//		}
//	}
//
//	else //k<0
//	{
//		if (k == -1)
//		{
//			return 1.0 / n;
//		}
//		else
//		{
//			return (1.0 / n) * power(n, k + 1);
//		}
//	}
//}
//
//int main()
//{
//	int n, k;
//	while (printf("请输入两个数>:"),scanf("%d %d", &n, &k) != EOF)
//	{
//		float ret = power(n, k);
//		printf("(%d)^(%d)=%.2f\n", n, k, ret);
//	}
//	return 0;
//}


/*
写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和

例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19

输入：1729，输出：19
*/

//int DigitSum(int n)
//{
//	if (n>9)
//	{
//		return DigitSum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int ret = DigitSum(n);
//		printf("%d\n", ret);
//	}
//	return 0;
//}

/*
递归和非递归分别实现strlen
*/

////递归
//size_t my_strlen_1(const char* str)
//{
//	assert(str != NULL);
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen_1(str + 1);
//	}
//}
//
////非递归_1 计数器
//size_t my_strlen_2(const char* str)
//{
//	assert(str != EOF);
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
////非递归_2 指针运算
//size_t my_strlen_3(const char* str)
//{
//	assert(str != EOF);
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - str;
//}
//
//int main()
//{
//	char arr[] = "hello world!";//12
//	printf("%u\n", my_strlen_1(arr));
//	printf("%u\n", my_strlen_2(arr));
//	printf("%u\n", my_strlen_3(arr));
//	return 0;
//}

/*
递归实现打印一个整数的每一位
*/
//
//void Print(int n)
//{
//	if (n>9)
//	{
//		Print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}

//单词排序

//int cmp_char_arr(const void* e1, const void* e2)
//{
//	return *(char*)e1 - *(char*)e2;
//}
//
//int main()
//{
//	char arr[5][20] = { 0 };
//	for (int i = 0; i < 5; i++)//输入每一行元素
//	{
//		scanf("%s", &arr[i]);
//	}
//	qsort(arr, 5, sizeof(arr[0]), cmp_char_arr);
//	printf("排序后:\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%s\n", arr[i]);
//	}
//	return 0;
//}

//模拟实现strcpy

//char* my_strcpy(const char* sous, char* dest)
//{
//	assert(sous != NULL);
//	assert(dest != NULL);
//	char* ret = dest;//返回值是目的地的数组名即首元素地址
//	while (*dest++ = *sous++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char Sous[] = "abcdefg";
//	char Dest[] = "hahahahaha";
//	//strcpy(Dest, Sous);
//	my_strcpy(Sous,Dest);
//	printf("%s", Dest);
//	return 0;
//}


//strcat函数
//模拟实现strcat

//char* my_strcat(char* dest,const char* sour)
//{
//	assert(dest && sour);
//
//	//1.找到dest中的 \0
//	//2.追加
//
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *sour++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	//strcat(arr1, arr2);
//	my_strcat(arr1,arr2);
//	printf("%s", arr1);
//	return  0;
//}

