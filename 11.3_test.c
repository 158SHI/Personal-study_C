#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//递归实现字符串倒置

//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr)
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//
//void reverse_string(char* arr)
//{
//	char* left = arr;
//	char* right = arr + my_strlen(arr) - 1;
//	char tmp = *left;//暂时存放第一个数组元素
//	*left = *right;
//	*right = '\0';
//	if (my_strlen(arr) > 1)
//	{
//		reverse_string(arr + 1);
//	}
//	*right = tmp;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//int ADD(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int x = 4;
//	int y = 7;
//	int ret = ADD(x , y);
//	return 0;
//}

int main()
{
	char arr1[10] = "123456";
	char arr2[] = "abcde";
	strncpy(arr1, arr2, 7);
	printf("%s\n", arr1);
	return 0;
}