#define _CRT_SECURE_NO_WARNINGS 1


//模拟strlen函数求字符串长度

//1.计数器
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main(void)
//{
//	char arr[] = "hello";
//	int len = my_strlen(arr);
//	printf("len=%d\n", len);
//	return 0;
//}

//2.函数递归
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main(void)
//{
//	char arr[] = "hello";
//	int len = my_strlen(arr);
//	printf("len=%d\n", len);
//	return 0;
//}

//3.指针运算
#include<stdio.h>

int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}

int main(void)
{
	char arr[] = "hello";
	int len = my_strlen(arr);
	printf("len=%d\n", len);
	return 0;
}