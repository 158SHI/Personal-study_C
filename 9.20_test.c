#define _CRT_SECURE_NO_WARNINGS 1

//输出的结果是什么
//输出的结果一样吗？为什么？
//#include<stdio.h>
//int main()
//{
//	char a = -128;
//	char b = 128;
//	//128 = 127+1 = -128
//	printf("a=%u\n", a);
//	printf("a=%u\n", b);
//	return 0;
//}

//输出的结果是什么
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	unsigned int i;
//	for  (i = 9; i>=0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(500);
//	}
//	return 0;
//}

//输出结果是什么？
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[1000];
	int i;
	for ( i = 0; i < 1000; i++)
	{
		arr[i] = -1 - i;//-1 -2 -3 ... -128 127 126 ...1 0 
	}
	printf("%d", strlen(arr));
	return 0;
}
