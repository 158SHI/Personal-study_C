#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//int main()
//{
//	char* p = NULL;
//	printf("%s\n", p);
//	return 0;
//}

int main()
{
	char arr[10] = "abc";
	printf("%zd\n", strlen(arr));
	printf("%d\n", *(arr + strlen(arr)));
	return 0;
}